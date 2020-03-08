/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:355  */

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


#line 115 "src/parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "src/parser.y" /* yacc.c:355  */

  const astnode * expr;
  int number;
  std::string * str;;

#line 194 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   960

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    59,    60,    61,    62,
      63,    64,    65,    66,    70,    71,    75,    76,    77,    78,
      79,    80,    84,    85,    86,    87,    88,    89,    93,    94,
      98,    99,   100,   101,   105,   106,   107,   111,   112,   113,
     117,   118,   119,   120,   121,   125,   126,   127,   131,   132,
     136,   137,   141,   142,   146,   147,   151,   152,   156,   157,
     161,   162,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   180,   181,   185,   189,   190,   194,   195,
     196,   197,   203,   204,   208,   209,   213,   214,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   232,   257,   258,
     298,   299,   303,   304,   305,   306,   307,   308,   309,   312,
     314,   325,   330,   331,   335,   336,   337,   341,   342,   346,
     347,   351,   352,   353,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   370,   371,   372,   376,   377,   381,   382,
     383,   384,   385,   386,   390,   391,   392,   396,   397,   398,
     399,   403,   404,   408,   409,   413,   414,   418,   419,   420,
     424,   425,   426,   427,   432,   433,   434,   435,   440,   441,
     445,   446,   451,   453
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "declarator", "direct_declarator", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     844,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,    26,   -23,  -144,     7,   915,   915,
     -58,    77,    30,   760,  -144,  -144,    -4,  -144,  -144,   -51,
    -144,    82,  -144,  -144,   232,  -144,   362,   548,    77,  -144,
    -144,  -144,    26,  -144,   182,  -144,   -11,  -144,  -144,   678,
     703,   703,   748,    13,    38,    44,    60,   444,   128,    93,
     113,   478,   563,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   500,    29,   748,  -144,    57,   114,     6,    27,
      49,   125,   133,    48,   199,    -6,  -144,  -144,    22,  -144,
       7,  -144,  -144,  -144,   302,   372,  -144,  -144,  -144,  -144,
    -144,  -144,    15,   157,   155,  -144,    34,  -144,  -144,  -144,
    -144,   158,  -144,   149,   182,  -144,  -144,   444,   563,  -144,
     748,  -144,  -144,   151,   444,   748,   748,   748,   179,   514,
    -144,  -144,  -144,    24,    62,   284,    59,   172,   239,  -144,
    -144,   584,   748,   252,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,   748,  -144,   748,   748,   748,
     748,   748,   748,   748,   748,   748,   748,   748,   748,   748,
     748,   748,   748,   748,   748,   748,   748,  -144,  -144,  -144,
     408,  -144,  -144,   802,   633,  -144,     9,  -144,   111,  -144,
     915,  -144,   253,  -144,  -144,   -22,  -144,   195,   444,  -144,
      70,    73,   102,   197,   514,  -144,  -144,  -144,   862,   148,
    -144,   748,  -144,  -144,   104,  -144,   139,  -144,  -144,  -144,
    -144,  -144,    57,    57,   114,   114,     6,     6,     6,     6,
      27,    27,    49,   125,   133,    48,   199,    31,  -144,  -144,
    -144,   201,   202,  -144,   210,   111,   898,   654,  -144,  -144,
     110,  -144,  -144,  -144,   444,   444,   444,   748,   666,  -144,
    -144,   748,  -144,   748,  -144,  -144,  -144,  -144,   213,  -144,
     214,  -144,  -144,   207,  -144,  -144,   140,   444,   142,  -144,
    -144,  -144,  -144,   444,   198,  -144,   444,  -144,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,    97,    86,    87,    89,    90,    91,    92,    95,
      96,    93,    94,    88,     0,   109,   171,     0,    78,    80,
       0,   101,     0,     0,   168,   170,     0,   110,    76,     0,
      82,    84,    79,    81,     0,   173,     0,     0,   100,     1,
     169,   103,     0,    77,     0,   172,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,   155,
     147,     6,    16,    28,     0,    30,    34,    37,    40,    45,
      48,    50,    52,    54,    56,    58,    60,    73,     0,   151,
       0,   153,   138,   139,     0,     0,   140,   141,   142,   143,
     117,   108,   116,     0,   111,   112,     0,     2,   105,    28,
      75,     0,    83,    84,     0,   133,    85,     0,     0,    20,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,     0,     0,    99,   119,     0,     0,    12,
      13,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,   149,   152,
       0,   148,   154,     0,     0,   114,   121,   115,   122,   106,
       0,   107,     0,   104,   136,     0,   144,     0,     0,   146,
       0,     0,     0,     0,     0,   167,     5,    98,     0,   121,
     120,     0,    11,     8,     0,    14,     0,    10,    61,    31,
      32,    33,    35,    36,    38,    39,    43,    44,    41,    42,
      46,    47,    49,    51,    53,    55,    57,     0,    74,   150,
     129,     0,     0,   125,     0,   123,     0,     0,   113,   118,
       0,   134,    21,   145,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   130,   124,   126,   131,     0,   127,
       0,   135,   137,   157,   159,   160,     0,     0,     0,    15,
      59,   132,   128,     0,     0,   162,     0,   158,   161,   163
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,   -15,  -144,   -50,    53,    65,    80,
      56,   107,   108,   112,   116,   120,  -144,   -24,   -43,  -144,
     -41,   -47,   -20,    23,  -144,   254,  -144,   -53,   160,   -10,
     -19,    -7,   -34,  -144,   119,  -144,   180,   -75,  -143,   -88,
    -144,   -57,  -144,    -1,  -144,   203,  -123,  -144,  -144,  -144,
    -144,   290,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    71,    72,   214,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   155,
      88,   111,    16,   102,    29,    30,    18,    19,   136,    20,
      21,    22,   241,   104,   105,   106,   137,   242,   188,   116,
     195,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      23,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     128,   115,   103,    38,    26,   123,   204,    31,    27,   135,
       1,   174,     1,   110,    89,    42,   162,   163,     1,    35,
     133,   134,   109,    17,   156,    34,   194,   187,   110,     1,
      45,    43,   113,     1,   119,   121,   122,   109,   182,   164,
     165,    32,    33,   245,   250,    15,    17,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    90,    41,   109,
     196,   210,   251,   168,   169,   135,   245,   199,    14,   117,
     183,   115,   184,   175,   179,    15,   183,   134,   184,   134,
     113,   258,   135,    15,   200,   201,   202,    14,   176,    28,
     176,    14,   185,   124,    15,   186,   191,   176,   215,   125,
     192,   216,   166,   167,   177,   126,   205,   219,   220,   221,
     154,   263,   218,   107,    47,    48,    49,    90,    50,    51,
     208,   127,   184,   182,   206,   157,   172,    15,   176,   209,
     158,   159,   254,   238,   237,   255,   176,   244,    36,   176,
      37,   253,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   259,   272,    44,   256,    34,   260,    38,   176,   109,
     261,    62,   246,    26,   247,   130,   186,    63,    64,    65,
      66,    67,    68,   160,   161,   107,    47,    48,    49,   129,
      50,    51,   170,   114,   271,   131,   109,   273,   274,   275,
     270,   209,   284,   262,   286,   176,   176,   115,   176,   208,
     171,   184,   268,   222,   223,   173,   276,   278,   279,   189,
     285,   190,   193,   110,   230,   231,   287,   224,   225,   289,
      44,   198,   109,   203,   211,    46,    47,    48,    49,   280,
      50,    51,   212,    62,   226,   227,   228,   229,   109,    63,
      64,    65,    66,    67,    68,   217,   249,   252,   257,   283,
       2,     3,     4,   264,   265,   114,     5,     6,     7,     8,
       9,    10,    11,    12,   266,   281,    13,   232,   282,   233,
     288,    52,    53,    54,   234,    55,    56,    57,    58,   235,
      59,    60,    61,    62,   236,   207,   112,   180,   197,    63,
      64,    65,    66,    67,    68,    46,    47,    48,    49,   248,
      50,    51,     2,    40,    69,    34,    70,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,    13,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     0,     0,     0,
       0,    52,    53,    54,     0,    55,    56,    57,    58,     0,
      59,    60,    61,    62,     0,   100,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    46,    47,    48,    49,     0,
      50,    51,     0,     0,    69,    34,   178,     0,     0,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     0,     0,     0,
       0,    46,    47,    48,    49,     0,    50,    51,     0,     0,
       0,    52,    53,    54,   101,    55,    56,    57,    58,     0,
      59,    60,    61,    62,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,     0,     0,    46,    47,    48,
      49,     0,    50,    51,    69,    34,   181,    52,    53,    54,
       0,    55,    56,    57,    58,     0,    59,    60,    61,    62,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,   107,    47,    48,    49,     0,    50,    51,     0,     0,
      69,    34,   239,    52,    53,    54,     0,    55,    56,    57,
      58,     0,    59,    60,    61,    62,     0,   138,   139,   140,
       0,    63,    64,    65,    66,    67,    68,   107,    47,    48,
      49,     0,    50,    51,     0,     0,    69,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,   107,    47,    48,    49,     0,    50,    51,     0,     0,
     132,   141,     0,   142,     0,   143,   107,    47,    48,    49,
       0,    50,    51,     0,     0,    62,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,   107,    47,    48,
      49,     2,    50,    51,     0,     0,    69,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,     0,    62,
       0,     0,   108,     0,     0,    63,    64,    65,    66,    67,
      68,     0,     0,     0,    62,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,   107,    47,    48,    49,
       0,    50,    51,     0,     0,    62,   213,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,   107,    47,    48,
      49,     0,    50,    51,     0,     0,     0,     0,     0,   107,
      47,    48,    49,     0,    50,    51,     0,     0,     0,     0,
       0,   107,    47,    48,    49,     0,    50,    51,     0,     0,
       0,     0,     0,     0,    62,     0,     0,   243,     0,     0,
      63,    64,    65,    66,    67,    68,   107,    47,    48,    49,
       0,    50,    51,     0,     0,    62,     0,     0,   269,     0,
       0,    63,    64,    65,    66,    67,    68,    62,   277,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,   118,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,   107,    47,    48,    49,     0,    50,    51,     0,     0,
      39,     0,     0,     1,   120,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,     1,     0,     0,     0,    62,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    14,     0,     0,     0,     0,     0,     0,    15,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   240,   184,     0,     0,     0,     0,
      15,     0,     2,     3,     4,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,    13,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    14,    13,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   240,   184,     2,     3,     4,     0,
      15,     0,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     2,     3,     4,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
     267
};

static const yytype_int16 yycheck[] =
{
      57,    44,    36,    22,    14,    52,   129,    17,    15,    62,
       3,    17,     3,    37,    34,    66,    10,    11,     3,    20,
      61,    62,    37,     0,    74,    83,   114,   102,    52,     3,
      31,    82,    42,     3,    49,    50,    51,    52,    95,    12,
      13,    18,    19,   186,    66,    68,    23,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    34,    62,    74,
     117,   136,    84,    14,    15,   118,   209,   124,    61,    80,
      61,   114,    63,    79,    94,    68,    61,   118,    63,   120,
      90,   204,   135,    68,   125,   126,   127,    61,    66,    82,
      66,    61,   102,    80,    68,   102,    62,    66,   141,    61,
      66,   142,    75,    76,    82,    61,    82,   157,   158,   159,
      81,    80,   155,     3,     4,     5,     6,    94,     8,     9,
      61,    61,    63,   180,    62,    68,    78,    68,    66,   136,
      73,    74,    62,   176,   175,    62,    66,   184,    61,    66,
      63,   198,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     184,   211,   250,    81,    62,    83,    62,   186,    66,   184,
      66,    61,    61,   183,    63,    82,   183,    67,    68,    69,
      70,    71,    72,    69,    70,     3,     4,     5,     6,    61,
       8,     9,    67,    83,    84,    82,   211,   254,   255,   256,
     247,   208,    62,    64,    62,    66,    66,   250,    66,    61,
      77,    63,   246,   160,   161,    16,   257,   258,   261,    62,
     277,    66,    64,   247,   168,   169,   283,   162,   163,   286,
      81,    80,   247,    54,    62,     3,     4,     5,     6,   263,
       8,     9,     3,    61,   164,   165,   166,   167,   263,    67,
      68,    69,    70,    71,    72,     3,     3,    62,    61,    52,
      28,    29,    30,    62,    62,    83,    34,    35,    36,    37,
      38,    39,    40,    41,    64,    62,    44,   170,    64,   171,
      82,    49,    50,    51,   172,    53,    54,    55,    56,   173,
      58,    59,    60,    61,   174,   135,    42,    94,   118,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,   190,
       8,     9,    28,    23,    82,    83,    84,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    -1,     3,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    49,    50,    51,    62,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    82,    83,    84,    49,    50,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    83,    84,    49,    50,    51,    -1,    53,    54,    55,
      56,    -1,    58,    59,    60,    61,    -1,     7,     8,     9,
      -1,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    61,    -1,    63,    -1,    65,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    28,     8,     9,    -1,    -1,    82,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    -1,    61,
      -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    61,    -1,    -1,    64,    -1,
      -1,    67,    68,    69,    70,    71,    72,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
       0,    -1,    -1,     3,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,     3,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    61,    44,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    28,    29,    30,    -1,
      68,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    44,    61,    68,   107,   108,   111,   112,
     114,   115,   116,   135,   136,   137,   114,   116,    82,   109,
     110,   114,   108,   108,    83,   128,    61,    63,   115,     0,
     136,    62,    66,    82,    81,   128,     3,     4,     5,     6,
       8,     9,    49,    50,    51,    53,    54,    55,    56,    58,
      59,    60,    61,    67,    68,    69,    70,    71,    72,    82,
      84,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   105,   107,
     108,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       3,    62,   108,   117,   118,   119,   120,     3,    64,    89,
     102,   106,   110,   114,    83,   103,   124,    80,    61,    89,
      61,    89,    89,   106,    80,    61,    61,    61,   126,    61,
      82,    82,    82,   105,   105,   112,   113,   121,     7,     8,
       9,    61,    63,    65,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    81,   104,    91,    68,    73,    74,
      69,    70,    10,    11,    12,    13,    75,    76,    14,    15,
      67,    77,    78,    16,    17,    79,    66,    82,    84,   107,
     130,    84,   126,    61,    63,   114,   116,   122,   123,    62,
      66,    62,    66,    64,   124,   125,   126,   121,    80,   126,
     105,   105,   105,    54,   131,    82,    62,   113,    61,   116,
     122,    62,     3,    62,    88,   103,   105,     3,   103,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      95,    95,    96,    97,    98,    99,   100,   105,   103,    84,
      62,   117,   122,    64,   106,   123,    61,    63,   119,     3,
      66,    84,    62,   126,    62,    62,    62,    61,   131,    91,
      62,    66,    64,    80,    62,    62,    64,    62,   117,    64,
     106,    84,   124,   126,   126,   126,   105,    62,   105,   103,
     102,    62,    64,    52,    62,   126,    62,   126,    82,   126
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   118,   118,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   124,   125,   125,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   128,   128,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   133,   134,   134,   134,   134,   135,   135,
     136,   136,   137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     2,     2,     2,     3,     1,     2,
       1,     1,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(0,*(yyvsp[0].str));}
#line 1655 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(1,*(yyvsp[0].str));}
#line 1661 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(2,*(yyvsp[0].str));}
#line 1667 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 55 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new primary_expression(3,(yyvsp[-1].expr));}
#line 1673 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1679 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(0, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1685 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(1, (yyvsp[-2].expr));}
#line 1691 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(2, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1697 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(3, (yyvsp[-2].expr), (yyvsp[0].str));}
#line 1703 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 64 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(4, (yyvsp[-2].expr), (yyvsp[0].str));}
#line 1709 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 65 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(5, (yyvsp[-1].expr));}
#line 1715 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 66 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(6, (yyvsp[-1].expr));}
#line 1721 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1727 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1733 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1739 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(0, (yyvsp[0].expr));}
#line 1745 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(1, (yyvsp[0].expr));}
#line 1751 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 78 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression((yyvsp[-1].number), (yyvsp[0].expr));}
#line 1757 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(2, (yyvsp[0].expr));}
#line 1763 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new unary_expression(3, (yyvsp[-1].expr));}
#line 1769 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 84 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 4;}
#line 1775 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 5;}
#line 1781 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 86 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 6;}
#line 1787 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 87 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 7;}
#line 1793 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 88 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 8;}
#line 1799 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 89 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 9;}
#line 1805 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1811 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new cast_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1817 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 1823 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(1,(yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1829 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(2,(yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1835 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new multiplicative_expression(3,(yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1841 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 105 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 1847 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 106 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new additive_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1853 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 107 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new additive_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1859 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 111 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 1865 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new shift_expression(1,(yyvsp[-2].expr),(yyvsp[0].expr))}
#line 1871 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new shift_expression(2,(yyvsp[-2].expr),(yyvsp[0].expr))}
#line 1877 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1883 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 118 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1889 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 119 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1895 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1901 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 121 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(3, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1907 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1913 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 126 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(4, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1919 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 127 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(5, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1925 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 131 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1931 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 132 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(6, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1937 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1943 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(7, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1949 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 141 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1955 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(8, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1961 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 146 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1967 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 147 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(9, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1973 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 151 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1979 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new relational_expression(10, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1985 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 156 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 1991 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 157 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1997 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 161 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2003 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 162 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].number), (yyvsp[0].expr));}
#line 2009 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 166 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 0;}
#line 2015 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 167 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 1;}
#line 2021 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 168 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 2;}
#line 2027 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 169 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 3;}
#line 2033 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 4;}
#line 2039 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 5;}
#line 2045 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 172 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 6;}
#line 2051 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 173 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 7;}
#line 2057 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 8;}
#line 2063 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 175 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 9;}
#line 2069 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 176 "src/parser.y" /* yacc.c:1646  */
    {(yyval.number) = 10;}
#line 2075 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 180 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2081 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 181 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new base_expression((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2087 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 185 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2093 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 189 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration((yyvsp[-1].expr));}
#line 2099 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr));}
#line 2105 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2111 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2117 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 196 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2123 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 197 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2129 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 203 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2135 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new init_declarator_list((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2141 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 208 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2147 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 209 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new init_declarator((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2153 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 213 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new storage_class_specifier(0);}
#line 2159 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 214 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new storage_class_specifier(1);}
#line 2165 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 221 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(0);}
#line 2171 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 222 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(1);}
#line 2177 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 223 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(2);}
#line 2183 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 224 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(3);}
#line 2189 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(4);}
#line 2195 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 226 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(5);}
#line 2201 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 227 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(6);}
#line 2207 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 228 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(7);}
#line 2213 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(8);}
#line 2219 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 232 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_specifier(9);}
#line 2225 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 257 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2231 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 258 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2237 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 298 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new declarator((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2243 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 299 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2249 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 303 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(0,(yyvsp[0].str));}
#line 2255 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(1,(yyvsp[-1].expr));}
#line 2261 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 305 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(2,(yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2267 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(3,(yyvsp[-2].expr));}
#line 2273 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 307 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(4,(yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2279 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 308 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(5,(yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 2285 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 309 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_declarator(6,(yyvsp[-2].expr));}
#line 2291 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new pointer(0);}
#line 2297 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 314 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new pointer(1, (yyvsp[0].expr));}
#line 2303 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 325 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2309 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 330 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2315 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 331 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2321 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 335 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr))}
#line 2327 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declarator(1, (yyvsp[-1].expr), (yyvsp[0].expr))}
#line 2333 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 337 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new parameter_declarator(2, (yyvsp[0].expr))}
#line 2339 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 341 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].str);}
#line 2345 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 342 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new identifier_list((yyvsp[-2].expr), (yyvsp[0].str));}
#line 2351 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 346 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2357 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 347 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2363 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2369 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 352 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2375 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 353 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new abstract_declarator((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2381 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 358 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 2387 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 359 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(0);}
#line 2393 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 360 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(1, (yyvsp[-1].expr));}
#line 2399 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 361 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-2].expr));}
#line 2405 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 362 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 2411 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 363 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(4);}
#line 2417 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 364 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(5, (yyvsp[-1].expr));}
#line 2423 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 365 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(6, (yyvsp[-2].expr));}
#line 2429 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 366 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new direct_abstract_declarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 2435 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 370 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2441 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 371 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer(0, (yyvsp[-1].expr));}
#line 2447 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 372 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer(1, (yyvsp[-2].expr));}
#line 2453 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 376 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer_list(0, (yyvsp[0].expr));}
#line 2459 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 377 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new initializer_list(1, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2465 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 381 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2471 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 382 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2477 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 383 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2483 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2489 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 385 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2495 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 386 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2501 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 390 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(0, (yyvsp[0].expr));}
#line 2507 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 391 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(1, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2513 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 392 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new labeled_statement(2, (yyvsp[0].expr));}
#line 2519 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 396 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(0);}
#line 2525 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 397 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr));}
#line 2531 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 398 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr));}
#line 2537 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 399 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new compound_statement(1, (yyvsp[-2].expr), (yyvsp[-1].expr));}
#line 2543 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 408 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr)}
#line 2549 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 409 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new statement_list((yyvsp[-1].expr),(yyvsp[0].expr));}
#line 2555 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 413 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression_statement(0)}
#line 2561 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 414 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new expression_statement((yyvsp[-1].expr))}
#line 2567 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 418 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2573 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 419 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(1, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2579 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 420 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2585 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 424 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2591 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 425 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));}
#line 2597 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 426 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2603 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 427 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new iteration_statement(0, (yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2609 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 432 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(1, "CONTINUE");}
#line 2615 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 433 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(2, "BREAK");}
#line 2621 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 434 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(3, "RETURN");}
#line 2627 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 435 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new jump_statement(4, (yyvsp[-1].expr));}
#line 2633 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 440 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2639 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 441 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2645 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 445 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2651 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 446 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2657 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 451 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new function_definition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2663 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 453 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new function_definition((yyvsp[-1].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2669 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2673 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 456 "src/parser.y" /* yacc.c:1906  */

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
  g_root= NULL;
  yyparse();
  return g_root;
}
