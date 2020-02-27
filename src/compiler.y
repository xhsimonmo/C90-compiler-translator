%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union{

}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER    {$$ = new primary_expression(0,*$1);}
	| CONSTANT      {$$ = new primary_expression(1,*$1);}
	| STRING_LITERAL {$$ = new primary_expression(2,*$1);}
	| '(' expression ')' {$$ = new primary_expression(3,$1);}
	;

postfix_expression
	: primary_expression                                   {$$ = $1;}
	| postfix_expression '[' expression ']'                {$$ = new unary_expression(0, $1, $3);}
	| postfix_expression '(' ')'                           {$$ = new unary_expression(1, $1);}
	| postfix_expression '(' argument_expression_list ')'  {$$ = new unary_expression(2, $1, $3);}
	| postfix_expression '.' IDENTIFIER                    {$$ = new unary_expression(3, $1, $3);}
	| postfix_expression PTR_OP IDENTIFIER                 {$$ = new unary_expression(4, $1, $3);}
	| postfix_expression INC_OP                            {$$ = new unary_expression(5, $1);}
	| postfix_expression DEC_OP                            {$$ = new unary_expression(6, $1);}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression               {$$ = $1;}
	| INC_OP unary_expression          {$$ = new unary_expression(0, $2);}
	| DEC_OP unary_expression          {$$ = new unary_expression(1, $2);}
	| unary_operator cast_expression   {$$ = new unary_expression($1, $2);}
	| SIZEOF unary_expression          {$$ = new unary_expression(2, $2);}
	| SIZEOF '(' type_name ')'         {$$ = new unary_expression(3, $2);}
	;

unary_operator
	: '&'      {$$ = "&";}
	| '*'      {$$ = "*";}
	| '+'      {$$ = "+";}
	| '-'      {$$ = "-";}
	| '~'      {$$ = "~";}
	| '!'      {$$ = "!";}
	;

cast_expression
	: unary_expression                       {$$ = $1;}
	| '(' type_name ')' cast_expression      {$$ = new cast_expression(0, $2, $4);}
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression                                 {$$ = $1;}
	| relational_expression '<' shift_expression       {$$ = new relational_expression(0, $1, $3);}
	| relational_expression '>' shift_expression       {$$ = new relational_expression(1, $1, $3);}
	| relational_expression LE_OP shift_expression     {$$ = new relational_expression(2, $1, $3);}
	| relational_expression GE_OP shift_expression     {$$ = new relational_expression(3, $1, $3);}
	;

equality_expression
	: relational_expression                              {$$ = $1;}
	| equality_expression EQ_OP relational_expression    {$$ = new relational_expression(4, $1, $3);}
	| equality_expression NE_OP relational_expression    {$$ = new relational_expression(5, $1, $3);}
	;

and_expression
	: equality_expression                                {$$ = $1;}
	| and_expression '&' equality_expression             {$$ = new relational_expression(6, $1, $3);}
	;

exclusive_or_expression
	: and_expression                                     {$$ = $1;}
	| exclusive_or_expression '^' and_expression         {$$ = new relational_expression(7, $1, $3);}
	;

inclusive_or_expression
	: exclusive_or_expression                                {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression    {$$ = new relational_expression(8, $1, $3);}
	;

logical_and_expression
	: inclusive_or_expression                                {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression  {$$ = new relational_expression(9, $1, $3);}
	;

logical_or_expression
	: logical_and_expression                                 {$$ = $1;}
	| logical_or_expression OR_OP logical_and_expression     {$$ = new relational_expression(10, $1, $3);}
	;

conditional_expression
	: logical_or_expression                                              {$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression    {$$ = new conditional_expression($1, $3, $5);}
	;

assignment_expression
	: conditional_expression                                             {$$ = $1;}
	| unary_expression assignment_operator assignment_expression         {$$ = new assignment_expression($1, $2, $3);}
	;

assignment_operator
	: '='                {$$ = "ASSIGN";}
	| MUL_ASSIGN         {$$ = "MUL";}
	| DIV_ASSIGN         {$$ = "DIV";}
	| MOD_ASSIGN         {$$ = "MOD";}
	| ADD_ASSIGN         {$$ = "ADD";}
	| SUB_ASSIGN         {$$ = "SUB";}
	| LEFT_ASSIGN        {$$ = "LEFT";}
	| RIGHT_ASSIGN       {$$ = "RIGHT";}
	| AND_ASSIGN         {$$ = "AND";}
	| XOR_ASSIGN         {$$ = "XOR";}
	| OR_ASSIGN          {$$ = "OR";}
	;

expression
	: assignment_expression                  {$$ = $1;}
	| expression ',' assignment_expression   {$$ = new expression($1, $3);}
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement   {$$ = $1}
	| compound_statement {$$ = $1}
	| expression_statement {$$ = $1}
	| selection_statement  {$$ = $1}
	| iteration_statement  {$$ = $1}
	| jump_statement {$$ = $1}
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'    {$$ = new compound_statement(0)}
	| '{' statement_list '}'   {$$ = new compound_statement(1, $2)}
	| '{' declaration_list '}'   {$$ = new compound_statement(1, $2)}
	| '{' declaration_list statement_list '}'    {$$ = new compound_statement(1, $2, $3)}
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement   {$$ = new iteration_statement(0, $3, $5)}
	| DO statement WHILE '(' expression ')' ';'    {$$ = new iteration_statement(1, $2, $5)}
	| FOR '(' expression_statement expression_statement ')' statement    {$$ = new iteration_statement(2, $3, $4, $6)}
	| FOR '(' expression_statement expression_statement expression ')' statement   {$$ = new iteration_statement(0, $3, $4, $5, $7)}
	;

jump_statement
	: GOTO IDENTIFIER ';' ///no goto statement
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
