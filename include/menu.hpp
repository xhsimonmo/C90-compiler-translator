#ifndef menu_hpp
#define menu_hpp

#include "mips.hpp"
#include "function_parameter.hpp"
#include "enum_specifier.hpp"
#include "ast.hpp"
#include "abstract_declarator.hpp"
#include "initializer_list.hpp"
#include "argument_expression_list.hpp"
#include "iteration_statement.hpp"
#include "assignment_expression.hpp"
#include "jump_statement.hpp"

#include "labeled_statement.hpp"
#include "base_expression.hpp"
#include "mul_add_shift_expression.hpp"
#include "cast_expression.hpp"
#include "parameter_declaration.hpp"
#include "compound_statement.hpp"
#include "parameter_list.hpp"
#include "conditional_expression.hpp"
#include "pointer.hpp"
#include "declaration.hpp"
#include "postfix_expression.hpp"
#include "declaration_specifiers.hpp"
#include "primary_expression.hpp"
#include "declarator.hpp"
#include "relational_expression.hpp"
#include "direct_abstract_declarator.hpp"
#include "selection_statement.hpp"
#include "direct_declarator.hpp"
#include "specifier_qualifier_list.hpp"
#include "expression_statement.hpp"
#include "statement_list.hpp"
#include "function_definition.hpp"
#include "storage_class_specifier.hpp"
#include "identifier_list.hpp"
#include "translation_unit.hpp"
#include "init_declarator.hpp"
#include "type_name.hpp"
#include "init_declarator_list.hpp"
#include "type_specifier.hpp"
#include "initializer.hpp"
#include "unary_expression.hpp"
#include "declaration_list.hpp"

#include "external_declaration.hpp"



extern const astnode * parseAST();
// extern FILE *yyin; // pointer to input stream

#endif
