%code requires{
  #include "menu.hpp"

  #include <cassert>
  #include <string>

  extern const astnode * g_root; // A way of getting the AST out

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
%type<expr> init_declarator_list init_declarator storage_class_specifier type_specifier specifier_qualifier_list declarator direct_declarator pointer parameter_type_list parameter_list parameter_declaration
%type<expr> type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement
%type<expr> iteration_statement jump_statement translation_unit external_declaration function_definition enum_specifier enumerator_list enumerator

%type<number> unary_operator assignment_operator
%type<str> IDENTIFIER CONSTANT STRING_LITERAL



%start begin



%%

primary_expression
	: IDENTIFIER    {$$ = new primary_expression(0,*$1); std::cerr << "primary expression 1, which is IDENTIFIER : " <<  *$1 << std::endl;}
	| CONSTANT      {$$ = new primary_expression(1,*$1); std::cerr << "primary expression 2, which is const with value: " << *$1 <<std::endl;}
	| STRING_LITERAL {$$ = new primary_expression(2,*$1); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
	| '(' expression ')' {$$ = new primary_expression(3,$2); std::cerr << "primary expression 4" << std::endl;}
	;

postfix_expression
	: primary_expression                                   {$$ = $1; std::cerr << "postfix expression 1" << std::endl;}
	| postfix_expression '[' expression ']'                {$$ = new postfix_expression(0, $1, $3);std::cerr << "postfix expression 222222222222222222222222222222222222222222222" << std::endl;}
	| postfix_expression '(' ')'                           {$$ = new postfix_expression(1, $1);std::cerr << "postfix expression 3" << std::endl;}
	| postfix_expression '(' argument_expression_list ')'  {$$ = new postfix_expression(2, $1, $3);std::cerr << "postfix expression 4" << std::endl;}
	| postfix_expression '.' IDENTIFIER                    {$$ = new postfix_expression(3, $1, *$3);std::cerr << "postfix expression 5" << std::endl;}
	| postfix_expression PTR_OP IDENTIFIER                 {$$ = new postfix_expression(4, $1, *$3);std::cerr << "postfix expression 6" << std::endl;}
	| postfix_expression INC_OP                            {$$ = new postfix_expression(5, $1);std::cerr << "postfix expression 7" << std::endl;}
	| postfix_expression DEC_OP                            {$$ = new postfix_expression(6, $1);std::cerr << "postfix expression 8" << std::endl;}
	;

argument_expression_list
	: assignment_expression                                  {$$ = new argument_expression_list($1); std::cerr << "argument expression 1" << std::endl;}
	| argument_expression_list ',' assignment_expression     {$$ = new argument_expression_list($1, $3); std::cerr << "argument expression 2" << std::endl;}
	;

unary_expression
	: postfix_expression               {$$ = $1; std::cerr << "unary expression 1" << std::endl;}
	| INC_OP unary_expression          {$$ = new unary_expression(0, $2); std::cerr << "unary expression 2" << std::endl;}
	| DEC_OP unary_expression          {$$ = new unary_expression(1, $2); std::cerr << "unary expression 3" << std::endl;}
	| unary_operator cast_expression   {$$ = new unary_expression($1, $2); std::cerr << "unary expression 4" << std::endl;}
	| SIZEOF unary_expression          {$$ = new unary_expression(2, $2); std::cerr << "unary expression 5" << std::endl;}
	| SIZEOF '(' type_name ')'         {$$ = new unary_expression(3, $3); std::cerr << "unary expression 6" << std::endl;}
	;

unary_operator
	: '&'      {$$ = 4; std::cerr << "unary operator 1" << std::endl;}
	| '*'      {$$ = 5; std::cerr << "unary operator 2" << std::endl;}
	| '+'      {$$ = 6; std::cerr << "unary operator 3" << std::endl;}
	| '-'      {$$ = 7; std::cerr << "unary operator 4" << std::endl;}
	| '~'      {$$ = 8; std::cerr << "unary operator 5" << std::endl;}
	| '!'      {$$ = 9; std::cerr << "unary operator 6" << std::endl;}
	;

cast_expression
	: unary_expression                       {$$ = $1; std::cerr << "cast expression 1" << std::endl;}
	| '(' type_name ')' cast_expression      {$$ = new cast_expression(0, $2, $4); std::cerr << "cast expression 2" << std::endl;}
	;

multiplicative_expression
	: cast_expression {$$ = $1; std::cerr << "mulitiplicative expression 1" << std::endl;}
	| multiplicative_expression '*' cast_expression  {$$ = new multiplicative_expression(1,$1, $3); std::cerr << "mulitiplicative expression 2" << std::endl;}
	| multiplicative_expression '/' cast_expression  {$$ = new multiplicative_expression(2,$1, $3); std::cerr << "mulitiplicative expression 3" << std::endl;}
	| multiplicative_expression '%' cast_expression  {$$ = new multiplicative_expression(3,$1, $3); std::cerr << "mulitiplicative expression 4" << std::endl;}
	;

additive_expression
	: multiplicative_expression  {$$ = $1; std::cerr << "additive_expression 1" << std::endl;}
	| additive_expression '+' multiplicative_expression  {$$ = new additive_expression(1, $1, $3); std::cerr << "additive_expression 2" << std::endl;}
	| additive_expression '-' multiplicative_expression  {$$ = new additive_expression(2, $1, $3); std::cerr << "additive_expression 3" << std::endl;}
	;

shift_expression
	: additive_expression  {$$ = $1; std::cerr << "shift_expression 1" << std::endl;}
	| shift_expression LEFT_OP additive_expression {$$ = new shift_expression(1,$1,$3); std::cerr << "shift_expression 2" << std::endl;}
	| shift_expression RIGHT_OP additive_expression {$$ = new shift_expression(2,$1,$3); std::cerr << "shift_expression 3" << std::endl;}
	;

relational_expression
	: shift_expression                                 {$$ = $1; std::cerr << "relational_expression 1" << std::endl;}
	| relational_expression '<' shift_expression       {$$ = new relational_expression(0, $1, $3); std::cerr << "relational_expression 2" << std::endl;}
	| relational_expression '>' shift_expression       {$$ = new relational_expression(1, $1, $3); std::cerr << "relational_expression 3" << std::endl;}
	| relational_expression LE_OP shift_expression     {$$ = new relational_expression(2, $1, $3); std::cerr << "relational_expression 4" << std::endl;}
	| relational_expression GE_OP shift_expression     {$$ = new relational_expression(3, $1, $3); std::cerr << "relational_expression 5" << std::endl;}
	;

equality_expression
	: relational_expression                              {$$ = $1; std::cerr << "equality_expression 1" << std::endl;}
	| equality_expression EQ_OP relational_expression    {$$ = new relational_expression(4, $1, $3); std::cerr << "equality_expression 2" << std::endl;}
	| equality_expression NE_OP relational_expression    {$$ = new relational_expression(5, $1, $3); std::cerr << "equality_expression 3" << std::endl;}
	;

and_expression
	: equality_expression                                {$$ = $1; std::cerr << "and_expression 1" << std::endl;}
	| and_expression '&' equality_expression             {$$ = new relational_expression(6, $1, $3); std::cerr << "and_expression 2" << std::endl;}
	;

exclusive_or_expression
	: and_expression                                     {$$ = $1; std::cerr << "exclusive_or_expression 1" << std::endl;}
	| exclusive_or_expression '^' and_expression         {$$ = new relational_expression(7, $1, $3); std::cerr << "exclusive_or_expression 2" << std::endl;}
	;

inclusive_or_expression
	: exclusive_or_expression                                {$$ = $1; std::cerr << "inclusive_or_expression 1" << std::endl;}
	| inclusive_or_expression '|' exclusive_or_expression    {$$ = new relational_expression(8, $1, $3); std::cerr << "inclusive_or_expression 2" << std::endl;}
	;

logical_and_expression
	: inclusive_or_expression                                {$$ = $1; std::cerr << "logical_and_expression 1" << std::endl;}
	| logical_and_expression AND_OP inclusive_or_expression  {$$ = new relational_expression(9, $1, $3); std::cerr << "logical_and_expression 2" << std::endl;}
	;

logical_or_expression
	: logical_and_expression                                 {$$ = $1; std::cerr << "logical_or_expression 1" << std::endl;}
	| logical_or_expression OR_OP logical_and_expression     {$$ = new relational_expression(10, $1, $3); std::cerr << "logical_or_expression 2" << std::endl;}
	;

conditional_expression
	: logical_or_expression                                              {$$ = $1; std::cerr << "conditional expression 1" << std::endl;}
	| logical_or_expression '?' expression ':' conditional_expression    {$$ = new conditional_expression($1, $3, $5); std::cerr << "conditional expression 2" << std::endl;}
	;

assignment_expression
	: conditional_expression                                             {$$ = new assignment_expression($1); std::cerr << "assignment expression 1" << std::endl;}
	| unary_expression assignment_operator assignment_expression         {$$ = new assignment_expression($1, $2, $3); std::cerr << "assignment expression 2" << std::endl;}
	;

assignment_operator
	: '='                {$$ = 0; std::cerr << "assignment operator 1" << std::endl;}
	| MUL_ASSIGN         {$$ = 1; std::cerr << "assignment operator 2" << std::endl;}
	| DIV_ASSIGN         {$$ = 2; std::cerr << "assignment operator 3" << std::endl;}
	| MOD_ASSIGN         {$$ = 3; std::cerr << "assignment operator 4" << std::endl;}
	| ADD_ASSIGN         {$$ = 4; std::cerr << "assignment operator 5" << std::endl;}
	| SUB_ASSIGN         {$$ = 5; std::cerr << "assignment operator 6" << std::endl;}
	| LEFT_ASSIGN        {$$ = 6; std::cerr << "assignment operator 7" << std::endl;}
	| RIGHT_ASSIGN       {$$ = 7; std::cerr << "assignment operator 8" << std::endl;}
	| AND_ASSIGN         {$$ = 8; std::cerr << "assignment operator 9" << std::endl;}
	| XOR_ASSIGN         {$$ = 9; std::cerr << "assignment operator 10" << std::endl;}
	| OR_ASSIGN          {$$ = 10; std::cerr << "assignment operator 11" << std::endl;}
	;

expression
	: assignment_expression                  {$$ = $1; std::cerr << "expression 1" << std::endl;}
	| expression ',' assignment_expression   {$$ = new base_expression($1, $3); std::cerr << "expression 2" << std::endl;}
	;

constant_expression
	: conditional_expression   {$$ = $1; std::cerr << "constant_expression 0" << std::endl;} // what is this for?
	;

declaration
	: declaration_specifiers ';'  {$$ = new declaration($1); std::cerr << "declaration 0 " << std::endl;}
	| declaration_specifiers init_declarator_list ';'  {$$ = new declaration($1, $2);std::cerr << "declaration 1 " << std::endl;}
	;

declaration_specifiers
	: storage_class_specifier    {$$ = $1;std::cerr << "declaration_specifiers 0" << std::endl;}
	| storage_class_specifier declaration_specifiers   {$$ = new declaration_specifiers($1,$2);std::cerr << "declaration_specifiers 1" << std::endl;}
	| type_specifier   {$$ = $1;std::cerr << "declaration_specifiers 2" << std::endl;}
	| type_specifier declaration_specifiers    {$$ = new declaration_specifiers($1,$2);std::cerr << "declaration_specifiers 3" << std::endl;}
	//| type_qualifier
	//| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator   {$$ = $1; std::cerr << "init_declarator_list 0 " << std::endl;}
	| init_declarator_list ',' init_declarator   {$$ = new init_declarator_list($1,$3); std::cerr << "init_declarator_list 1" << std::endl;}
	;

init_declarator
	: declarator   {$$ = new init_declarator($1); std::cerr << "init_declarator 0 " << std::endl;}
	| declarator '=' initializer   {$$ = new init_declarator($1,$3);  std::cerr << "init_declarator 1" << std::endl;}
	;

storage_class_specifier
	: TYPEDEF  {$$ = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
	| EXTERN   {$$ = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}
	;

type_specifier
	: VOID   {$$ = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
	| CHAR   {$$ = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
	| SHORT   {$$ = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
	| INT   {$$ = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
	| LONG   {$$ = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
	| FLOAT   {$$ = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
	| DOUBLE   {$$ = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
	| SIGNED   {$$ = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
	| UNSIGNED   {$$ = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
//	| struct_or_union_specifier   {$$ = new type_specifier("STRUCT");}
	| enum_specifier   {$$ = $1; std::cerr << "type_specifier signed enum 10" << std::endl;}
	| TYPE_NAME   {$$ = new type_specifier(10); std::cerr << "type_name" << std::endl;}
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
/*////////////////////////////////struct ///////////////////////////////////////////////*/

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {$$ = new specifier_qualifier_list($1,$2); std::cerr << "specifier_qualifier_list 0" << std::endl;}
	| type_specifier  {$$ = $1;  std::cerr << "specifier_qualifier_list 1" << std::endl;}
	/*/| type_qualifier specifier_qualifier_list
	//| type_qualifier */
	;
 /*////////////////////////////////struct ///////////////////////////////////////////////*/
/* struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	; */
/*////////////////////////////////struct ///////////////////////////////////////////////*/

enum_specifier
	: ENUM '{' enumerator_list '}'     {$$ = new enum_specifier(0,$3); std::cerr << "enum_specifier 0" << std::endl;}
	| ENUM IDENTIFIER '{' enumerator_list '}'    {$$ = new enum_specifier(1,*$2,$4); std::cerr << "enum_specifier 1" << std::endl;}
	| ENUM IDENTIFIER        {$$ = new enum_specifier(2,*$2); std::cerr << "enum_specifier 2" << std::endl;}
	;

enumerator_list
	: enumerator   {$$ = $1; std::cerr << "enumerator_list 0" << std::endl;}
	| enumerator_list ',' enumerator    {$$ = new enumerator_list($1,$3); std::cerr << "enumerator_list 1" << std::endl;}
	;

enumerator
	: IDENTIFIER     {$$ = new enumerator(*$1); std::cerr << "enumerator 0" << std::endl;}
	| IDENTIFIER '=' constant_expression     {$$ = new enumerator(*$1,$3); std::cerr << "enumerator 0" << std::endl;}
	;

/* type_qualifier       no need to Implement type_qualifier
	: CONST
	： VOLATILE
	; */

 /////////////////////////////////struct ////////////////////////////////////////////////

declarator
	: pointer direct_declarator  {$$ = new declarator($1, $2);  std::cerr << "declarator 0" << std::endl;}
	| direct_declarator    {$$ = $1;  std::cerr << "declarator 1" << std::endl;}
	;

direct_declarator
	: IDENTIFIER   {$$ = new direct_declarator(0,*$1);std::cerr << "direct_declarator 0,IDENTIFIER : " << *$1 <<std::endl; }
	| '(' declarator ')'  {$$ = new direct_declarator(1,$2); std::cerr << "direct_declarator 1" << std::endl;}
	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);  std::cerr << "direct_declarator 2" << std::endl;}
	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);  std::cerr << "direct_declarator 3" << std::endl;}
	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);  std::cerr << "direct_declarator 4" << std::endl;}
	//| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);  std::cerr << "direct_declarator 5" << std::endl;} KR style
	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);  std::cerr << "direct_declarator 6" << std::endl;}

pointer
	: '*' {$$ = new pointer(0); std::cerr << "pointer 0" << std::endl;}
	//| '*' type_qualifier_list
	| '*' pointer   {$$ = new pointer(1, $2); std::cerr << "pointer 1" << std::endl;}
	//| '*' type_qualifier_list pointer
	;

/* type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	; */


parameter_type_list
	: parameter_list                   {$$ = $1; std::cerr << "parameter_type_list 0" << std::endl;}
/*	| parameter_list ',' ELLIPSIS */
	;

parameter_list
	: parameter_declaration                        {$$ = $1; std::cerr << "parameter_list 0" << std::endl; }
	| parameter_list ',' parameter_declaration     {$$ = new parameter_list($1, $3); std::cerr << "parameter_list 1" << std::endl;}
	;

parameter_declaration
	: declaration_specifiers declarator             {$$ = new parameter_declaration(0, $1, $2); std::cerr << "parameter_declaration 0" << std::endl; }
	| declaration_specifiers abstract_declarator    {$$ = new parameter_declaration(1, $1, $2); std::cerr << "parameter_declaration 1" << std::endl; }
	| declaration_specifiers                   {$$ = new parameter_declaration(2, $1); std::cerr << "parameter_declaration 2" << std::endl;  } /*TODO what does this do */
	;

/* identifier_list
	: IDENTIFIER                                     {$$ = new identifier_list(*$1);std::cerr << "identifier_list 0; an IDENTIFIER: " << std::endl;}
	| identifier_list ',' IDENTIFIER                 {$$ = new identifier_list($1, *$3); std::cerr << "identifier_list 1; an IDENTIFIER: " <<   std::endl;}
	; */

type_name
	: specifier_qualifier_list                       {$$ = $1;std::cerr << "type name 1" << std::endl; }
	| specifier_qualifier_list abstract_declarator   {$$ = new type_name($1, $2);std::cerr << "type name 2" << std::endl;}
	;

abstract_declarator
	: pointer                                        {$$ = $1;  std::cerr << "abstract_declarator 0" << std::endl;}
	| direct_abstract_declarator                     {$$ = $1; std::cerr << "abstract_declarator 1" << std::endl;}
	| pointer direct_abstract_declarator             {$$ = new abstract_declarator($1, $2); std::cerr << "abstract_declarator 2" << std::endl;}
	;

/*喵喵喵*/
direct_abstract_declarator
	: '(' abstract_declarator ')'                                {$$ = $2;  std::cerr << "direct_abstract_declarator 0" << std::endl;}
	| '[' ']'                                                    {$$ = new direct_abstract_declarator(0);  std::cerr << "direct_abstract_declarator 1" << std::endl;}
	| '[' constant_expression ']'                                {$$ = new direct_abstract_declarator(1, $2);  std::cerr << "direct_abstract_declarator 2" << std::endl;}
	| direct_abstract_declarator '[' ']'                         {$$ = new direct_abstract_declarator(2, $1);  std::cerr << "direct_abstract_declarator 3" << std::endl;}
	| direct_abstract_declarator '[' constant_expression ']'     {$$ = new direct_abstract_declarator(3, $1, $3);  std::cerr << "direct_abstract_declarator 4" << std::endl;}
	| '(' ')'                                                    {$$ = new direct_abstract_declarator(4);  std::cerr << "direct_abstract_declarator 5" << std::endl;}
	| '(' parameter_type_list ')'                                {$$ = new direct_abstract_declarator(5, $2);  std::cerr << "direct_abstract_declarator 6" << std::endl;}
	| direct_abstract_declarator '(' ')'                         {$$ = new direct_abstract_declarator(6, $1);  std::cerr << "direct_abstract_declarator 7" << std::endl;}
	| direct_abstract_declarator '(' parameter_type_list ')'     {$$ = new direct_abstract_declarator(7, $1, $3);  std::cerr << "direct_abstract_declarator 8" << std::endl;}
	;

initializer
	: assignment_expression                  {$$ = $1; std::cerr << "initializer 0" << std::endl;}
	| '{' initializer_list '}'               {$$ = new initializer(0, $2); std::cerr << "initializer 1" << std::endl;}
	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2); std::cerr << "initializer 2" << std::endl;}
	;

initializer_list
	: initializer                            {$$ = new initializer_list(0, $1); std::cerr << "initializer_list 0" << std::endl;}
	| initializer_list ',' initializer       {$$ = new initializer_list(1, $1, $3); std::cerr << "initializer_list 1" << std::endl;}
	;

statement
	: labeled_statement   {$$ = $1; std::cerr << "statement 0" << std::endl;}
	| compound_statement {$$ = $1; std::cerr << "statement 1" << std::endl; }
	| expression_statement {$$ = $1; std::cerr << "statement 2" << std::endl;}
	| selection_statement  {$$ = $1; std::cerr << "statement 3" << std::endl;}
	| iteration_statement  {$$ = $1; std::cerr << "statement 4" << std::endl;}
	| jump_statement {$$ = $1; std::cerr << "statement 5" << std::endl;}
	;

labeled_statement
	: IDENTIFIER ':' statement   {$$ = new labeled_statement(0, $3); std::cerr << "labeled_statement 0" << std::endl;}
	| CASE constant_expression ':' statement   {$$ = new labeled_statement(1, $2, $4);std::cerr << "labeled_statement 1" << std::endl;}
	| DEFAULT ':' statement    {$$ = new labeled_statement(2, $3); std::cerr << "labeled_statement 2" << std::endl;}
	;

compound_statement
	: '{' '}'    {$$ = new compound_statement(0); std::cerr << "compound_statement 0" << std::endl;}
	| '{' statement_list '}'   {$$ = new compound_statement(1, $2); std::cerr << "compound_statement 1" << std::endl;}
	| '{' declaration_list '}'   {$$ = new compound_statement(2, $2); std::cerr << "compound_statement 2" << std::endl;}
	| '{' declaration_list statement_list '}'    {$$ = new compound_statement(3, $2, $3); std::cerr << "compound_statement 3" << std::endl;} /*declaration list need to be in front of statement in c language"*/
	;

declaration_list
	: declaration                      {$$ = $1; std::cerr << "declaration list 1" << std::endl;}
	| declaration_list declaration     {$$ = new declaration_list($1, $2); std::cerr << "declaration list 2" << std::endl;}
	;

statement_list
	: statement    {$$ = $1; std::cerr << "statement_list 0" << std::endl;}
	| statement_list statement   {$$ = new statement_list($1,$2); std::cerr << "statement_list 1" << std::endl;}
	;

expression_statement
	: ';'    {$$ = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
	| expression ';'   {$$ = new expression_statement($1);std::cerr << "expression_statement 1" << std::endl;}
	;

selection_statement
	: IF '(' expression ')' statement    {$$ = new selection_statement(0, $3, $5);std::cerr << "selection_statement 0" << std::endl;}
	| IF '(' expression ')' statement ELSE statement   {$$ = new selection_statement(1, $3, $5, $7);std::cerr << "selection_statement 1" << std::endl;}
	| SWITCH '(' expression ')' statement    {$$ = new selection_statement(2, $3, $5);std::cerr << "selection_statement 2" << std::endl;}
	;

iteration_statement
	: WHILE '(' expression ')' statement   {$$ = new iteration_statement(0, $3, $5); std::cerr << "iteration_statement 0 " << std::endl;}
	| DO statement WHILE '(' expression ')' ';'    {$$ = new iteration_statement(1, $2, $5);std::cerr << "iteration_statement 1 " << std::endl;}
	| FOR '(' expression_statement expression_statement ')' statement    {$$ = new iteration_statement(2, $3, $4, $6);std::cerr << "iteration_statement 2 " << std::endl;}
	| FOR '(' expression_statement expression_statement expression ')' statement   {$$ = new iteration_statement(3, $3, $4, $5, $7);std::cerr << "iteration_statement 3 " << std::endl;}
	;

jump_statement
	 //GOTO IDENTIFIER ';'   {$$ = new jump_statement(0, "GOTO");}  // no need to Implement this
	: CONTINUE ';'   {$$ = new jump_statement(1, "CONTINUE");std::cerr << "jump_statement 1 " << std::endl;}
	| BREAK ';'    {$$ = new jump_statement(2, "BREAK");std::cerr << "jump_statement 2 " << std::endl;}
	| RETURN ';'   {$$ = new jump_statement(3, "RETURN");std::cerr << "jump_statement 3 " << std::endl;}
	| RETURN expression ';'    {$$ = new jump_statement(4, $2);std::cerr << "jump_statement 4 " << std::endl;}
	;

/*translation unit: (#include)source file*/
translation_unit
	: external_declaration                     {$$ = $1;std::cerr << " translation_unit 1" << std::endl;}
	| translation_unit external_declaration    {std::cerr << "translation_unit 2" << std::endl;$$ = new translation_unit($1, $2);}
	;

begin
  : translation_unit    {g_root = $1;}

external_declaration
	: function_definition        {$$ = new external_declaration(0,$1);std::cerr << "external declaration 1" << std::endl;}
	| declaration                {$$ =  new external_declaration(1,$1);std::cerr << "external declaration 2" << std::endl;}/*global variable???*/
	;

function_definition
	/*: declaration_specifiers declarator declaration_list compound_statement  喵喵喵*/
	: declaration_specifiers declarator compound_statement                   {std::cerr << "function definition 1" << std::endl;$$ = new function_definition($1, $2, $3);}
  | declarator compound_statement                                          {std::cerr << "function definition 2" << std::endl;$$ = new function_definition($1, $2);}
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
  //std::cerr << "parseast" << std::endl;
  g_root= 0;
  yyparse();
  return g_root;
}
