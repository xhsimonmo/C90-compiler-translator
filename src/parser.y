%code requires{
  #include "menu.hpp"

  #include <cassert>
  #include <string>

  extern const astnode * g_root; // A way of getting the AST out

  //extern FILE *yyin; // pointer to input stream

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
   int yylex(void);
   void yyerror(const char *);

}
 // Represents the value associated with any kind of
 // AST node.
%union{
  astnode * expr;
  int number;
  std::string * str;;
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

%type<expr> primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression
%type<expr> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression expression constant_expression declaration declaration_specifiers
%type<expr> init_declarator_list init_declarator storage_class_specifier type_specifier specifier_qualifier_list declarator direct_declarator pointer parameter_type_list parameter_list parameter_declaration identifier_list
%type<expr> type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement
%type<expr> iteration_statement jump_statement translation_unit external_declaration function_definition

%type<number> unary_operator assignment_operator
%type<str> IDENTIFIER CONSTANT STRING_LITERAL



%start translation_unit



%%

primary_expression
	: IDENTIFIER    {$$ = new primary_expression(0,*$1);}
	| CONSTANT      {$$ = new primary_expression(1,*$1);}
	| STRING_LITERAL {$$ = new primary_expression(2,*$1);}
	| '(' expression ')' {$$ = new primary_expression(3,$2);}
	;

postfix_expression
	: primary_expression                                   {$$ = $1;}
	| postfix_expression '[' expression ']'                {$$ = new postfix_expression(0, $1, $3);}
	| postfix_expression '(' ')'                           {$$ = new postfix_expression(1, $1);}
	| postfix_expression '(' argument_expression_list ')'  {$$ = new postfix_expression(2, $1, $3);}
	| postfix_expression '.' IDENTIFIER                    {$$ = new postfix_expression(3, $1, *$3);}
	| postfix_expression PTR_OP IDENTIFIER                 {$$ = new postfix_expression(4, $1, *$3);}
	| postfix_expression INC_OP                            {$$ = new postfix_expression(5, $1);}
	| postfix_expression DEC_OP                            {$$ = new postfix_expression(6, $1);}
	;

argument_expression_list
	: assignment_expression                                  {$$ = $1;}
	| argument_expression_list ',' assignment_expression     {$$ = new argument_expression_list($1, $3);}
	;

unary_expression
	: postfix_expression               {$$ = $1;}
	| INC_OP unary_expression          {$$ = new unary_expression(0, $2);}
	| DEC_OP unary_expression          {$$ = new unary_expression(1, $2);}
	| unary_operator cast_expression   {$$ = new unary_expression($1, $2);}
	| SIZEOF unary_expression          {$$ = new unary_expression(2, $2);}
	| SIZEOF '(' type_name ')'         {$$ = new unary_expression(3, $3);}
	;

unary_operator
	: '&'      {$$ = 4;}
	| '*'      {$$ = 5;}
	| '+'      {$$ = 6;}
	| '-'      {$$ = 7;}
	| '~'      {$$ = 8;}
	| '!'      {$$ = 9;}
	;

cast_expression
	: unary_expression                       {$$ = $1;}
	| '(' type_name ')' cast_expression      {$$ = new cast_expression(0, $2, $4);}
	;

multiplicative_expression
	: cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression  {$$ = new multiplicative_expression(1,$1, $3);}
	| multiplicative_expression '/' cast_expression  {$$ = new multiplicative_expression(2,$1, $3);}
	| multiplicative_expression '%' cast_expression  {$$ = new multiplicative_expression(3,$1, $3);}
	;

additive_expression
	: multiplicative_expression  {$$ = $1;}
	| additive_expression '+' multiplicative_expression  {$$ = new additive_expression(1, $1, $3);}
	| additive_expression '-' multiplicative_expression  {$$ = new additive_expression(2, $1, $3);}
	;

shift_expression
	: additive_expression  {$$ = $1;}
	| shift_expression LEFT_OP additive_expression {$$ = new shift_expression(1,$1,$3);}
	| shift_expression RIGHT_OP additive_expression {$$ = new shift_expression(2,$1,$3);}
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
	: '='                {$$ = 0;}
	| MUL_ASSIGN         {$$ = 1;}
	| DIV_ASSIGN         {$$ = 2;}
	| MOD_ASSIGN         {$$ = 3;}
	| ADD_ASSIGN         {$$ = 4;}
	| SUB_ASSIGN         {$$ = 5;}
	| LEFT_ASSIGN        {$$ = 6;}
	| RIGHT_ASSIGN       {$$ = 7;}
	| AND_ASSIGN         {$$ = 8;}
	| XOR_ASSIGN         {$$ = 9;}
	| OR_ASSIGN          {$$ = 10;}
	;

expression
	: assignment_expression                  {$$ = $1;}
	| expression ',' assignment_expression   {$$ = new base_expression($1, $3);}
	;

constant_expression
	: conditional_expression   {$$ = $1;} // what is this for?
	;

declaration
	: declaration_specifiers ';'  {$$ = new declaration($1);}
	| declaration_specifiers init_declarator_list ';'  {$$ = new declaration($1, $2);}
	;

declaration_specifiers
	: storage_class_specifier    {$$ = $1;}
	| storage_class_specifier declaration_specifiers   {$$ = new declaration_specifiers($1,$2);}
	| type_specifier   {$$ = $1;}
	| type_specifier declaration_specifiers    {$$ = new declaration_specifiers($1,$2);}
	//| type_qualifier
	//| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator   {$$ = $1;}
	| init_declarator_list ',' init_declarator   {$$ = new init_declarator_list($1,$3);}
	;

init_declarator
	: declarator   {$$ = $1;}
	| declarator '=' initializer   {$$ = new init_declarator($1,$3);}
	;

storage_class_specifier
	: TYPEDEF  {$$ = new storage_class_specifier(0);}
	| EXTERN   {$$ = new storage_class_specifier(1);}
//	| STATIC
//	| AUTO
//	| REGISTER
	;

type_specifier
	: VOID   {$$ = new type_specifier(0);}
	| CHAR   {$$ = new type_specifier(1);}
	| SHORT   {$$ = new type_specifier(2);}
	| INT   {$$ = new type_specifier(3);}
	| LONG   {$$ = new type_specifier(4);}
	| FLOAT   {$$ = new type_specifier(5);}
	| DOUBLE   {$$ = new type_specifier(6);}
	| SIGNED   {$$ = new type_specifier(7);}
	| UNSIGNED   {$$ = new type_specifier(8);}
//	| struct_or_union_specifier   {$$ = new type_specifier("STRUCT");}
//	| enum_specifier   {$$ = new type_specifier("ENUM");}
	| TYPE_NAME   {$$ = new type_specifier(9);}
	;
/////////////////////////////////struct ////////////////////////////////////////////////
/* struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	//| UNION  no requoement for union
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	; */
/////////////////////////////////struct ////////////////////////////////////////////////

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {$$ = new specifier_qualifier_list($1,$2);}
	| type_specifier  {$$ = $1;}
	//| type_qualifier specifier_qualifier_list
	//| type_qualifier
	;
 /////////////////////////////////struct && enum////////////////////////////////////////////////
/* struct_declarator_list
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
	; */

/* type_qualifier       no need to Implement type_qualifier
	: CONST
	： VOLATILE
	; */

 /////////////////////////////////struct && enum////////////////////////////////////////////////

declarator
	: pointer direct_declarator  {$$ = new declarator($1, $2);}
	| direct_declarator    {$$ = $1;}
	;

direct_declarator
	: IDENTIFIER   {$$ = new direct_declarator(0,*$1);}
	| '(' declarator ')'  {$$ = new direct_declarator(1,$2);}
	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);}
	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);}
	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);}
	| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);}
	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);}

pointer
	: '*' {$$ = new pointer(0);}
	//| '*' type_qualifier_list
	| '*' pointer   {$$ = new pointer(1, $2);}
	//| '*' type_qualifier_list pointer
	;

/* type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	; */


parameter_type_list
	: parameter_list                   {$$ = $1;}
/*	| parameter_list ',' ELLIPSIS */
	;

parameter_list
	: parameter_declaration                        {$$ = $1;}
	| parameter_list ',' parameter_declaration     {$$ = new parameter_list($1, $3);}
	;

parameter_declaration
	: declaration_specifiers declarator             {$$ = new parameter_declaration(0, $1, $2);}
	| declaration_specifiers abstract_declarator    {$$ = new parameter_declaration(1, $1, $2);}
	| declaration_specifiers/*喵喵喵*/                   {$$ = new parameter_declaration(2, $1);} /*TODO what does this do */
	;

identifier_list
	: IDENTIFIER                                     {$$ = new identifier_list(*$1);std::cout << "identifier is here !" << std::endl;}
	| identifier_list ',' IDENTIFIER                 {$$ = new identifier_list($1, *$3);}
	;

type_name
	: specifier_qualifier_list                       {$$ = $1;std::cout << "type name" << std::endl;}
	| specifier_qualifier_list abstract_declarator   {$$ = new type_name($1, $2);}
	;

abstract_declarator
	: pointer                                        {$$ = $1;}
	| direct_abstract_declarator                     {$$ = $1;}
	| pointer direct_abstract_declarator             {$$ = new abstract_declarator($1, $2);}
	;

/*喵喵喵*/
direct_abstract_declarator
	: '(' abstract_declarator ')'                                {$$ = $2;}
	| '[' ']'                                                    {$$ = new direct_abstract_declarator(0);}
	| '[' constant_expression ']'                                {$$ = new direct_abstract_declarator(1, $2);}
	| direct_abstract_declarator '[' ']'                         {$$ = new direct_abstract_declarator(2, $1);}
	| direct_abstract_declarator '[' constant_expression ']'     {$$ = new direct_abstract_declarator(3, $1, $3);}
	| '(' ')'                                                    {$$ = new direct_abstract_declarator(4);}
	| '(' parameter_type_list ')'                                {$$ = new direct_abstract_declarator(5, $2);}
	| direct_abstract_declarator '(' ')'                         {$$ = new direct_abstract_declarator(6, $1);}
	| direct_abstract_declarator '(' parameter_type_list ')'     {$$ = new direct_abstract_declarator(7, $1, $3);}
	;

initializer
	: assignment_expression                  {$$ = $1;}
	| '{' initializer_list '}'               {$$ = new initializer(0, $2);}
	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2);}
	;

initializer_list
	: initializer                            {$$ = new initializer_list(0, $1);}
	| initializer_list ',' initializer       {$$ = new initializer_list(1, $1, $3);}
	;

statement
	: labeled_statement   {$$ = $1;}
	| compound_statement {$$ = $1;}
	| expression_statement {$$ = $1;}
	| selection_statement  {$$ = $1;}
	| iteration_statement  {$$ = $1;}
	| jump_statement {$$ = $1;}
	;

labeled_statement
	: IDENTIFIER ':' statement   {$$ = new labeled_statement(0, $3);}
	| CASE constant_expression ':' statement   {$$ = new labeled_statement(1, $2, $4);}
	| DEFAULT ':' statement    {$$ = new labeled_statement(2, $3);}
	;

compound_statement
	: '{' '}'    {$$ = new compound_statement(0);}
	| '{' statement_list '}'   {$$ = new compound_statement(1, $2);}
	| '{' declaration_list '}'   {$$ = new compound_statement(1, $2);}
	| '{' declaration_list statement_list '}'    {$$ = new compound_statement(1, $2, $3);}
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement    {$$ = $1;}
	| statement_list statement   {$$ = new statement_list($1,$2);}
	;

expression_statement
	: ';'    {$$ = new expression_statement(0);}
	| expression ';'   {$$ = new expression_statement($1);}
	;

selection_statement
	: IF '(' expression ')' statement    {$$ = new selection_statement(0, $3, $5);}
	| IF '(' expression ')' statement ELSE statement   {$$ = new selection_statement(1, $3, $5, $7);}
	| SWITCH '(' expression ')' statement    {$$ = new selection_statement(2, $3, $5);}
	;

iteration_statement
	: WHILE '(' expression ')' statement   {$$ = new iteration_statement(0, $3, $5);}
	| DO statement WHILE '(' expression ')' ';'    {$$ = new iteration_statement(1, $2, $5);}
	| FOR '(' expression_statement expression_statement ')' statement    {$$ = new iteration_statement(2, $3, $4, $6);}
	| FOR '(' expression_statement expression_statement expression ')' statement   {$$ = new iteration_statement(0, $3, $4, $5, $7);}
	;

jump_statement
	 //GOTO IDENTIFIER ';'   {$$ = new jump_statement(0, "GOTO");}  // no need to Implement this
	: CONTINUE ';'   {$$ = new jump_statement(1, "CONTINUE");}
	| BREAK ';'    {$$ = new jump_statement(2, "BREAK");}
	| RETURN ';'   {$$ = new jump_statement(3, "RETURN");}
	| RETURN expression ';'    {$$ = new jump_statement(4, $2);}
	;

/*translation unit: (#include)source file*/
translation_unit
	: external_declaration                     {$$ = $1;std::cout << " at the top" << std::endl;}
	| translation_unit external_declaration    {$$ = new translation_unit($1, $2);std::cout << "at the top" << std::endl;}
	;

external_declaration
	: function_definition        {$$ = $1;}
	| declaration                {$$ = $1;}/*global variable???*/
	;

function_definition
	/*: declaration_specifiers declarator declaration_list compound_statement  喵喵喵*/
	: declaration_specifiers declarator compound_statement                   {$$ = new function_definition($1, $2, $3);}
  | declarator compound_statement                                          {$$ = new function_definition($1, $2);}
	/*| declarator declaration_list compound_statement                      喵喵喵*/
	;

%%
/* #include <stdio.h>
#include <string>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
} */

 const astnode * g_root;
 /* const astnode* parseAST(char* filename)
{
    yyin = fopen(filename, "r");
    g_root= NULL;
    yyparse();
   return g_root;
} */


 const astnode* parseAST(void){
  //std::cout << "parseast" << std::endl;
  g_root= NULL;
  yyparse();
  return g_root;
}
