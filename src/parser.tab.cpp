/* A Bison parser, made by GNU Bison 3.5.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 1 "src/parser.y"

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


#line 129 "src/parser.tab.cpp"

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
#line 20 "src/parser.y"

  astnode * expr;
  int number;
  std::string * str;;

#line 207 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   963

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    56,    57,    58,    62,    63,    64,    65,
      66,    67,    68,    69,    73,    74,    78,    79,    80,    81,
      82,    83,    87,    88,    89,    90,    91,    92,    96,    97,
     101,   102,   103,   104,   108,   109,   110,   114,   115,   116,
     120,   121,   122,   123,   124,   128,   129,   130,   134,   135,
     139,   140,   144,   145,   149,   150,   154,   155,   159,   160,
     164,   165,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   183,   184,   188,   192,   193,   197,   198,
     199,   200,   206,   207,   211,   212,   216,   217,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   234,   235,   260,
     261,   279,   280,   281,   285,   286,   290,   291,   302,   303,
     307,   308,   309,   310,   311,   313,   316,   318,   329,   334,
     335,   339,   340,   341,   350,   351,   355,   356,   357,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   374,   375,
     376,   380,   381,   385,   386,   387,   388,   389,   390,   394,
     395,   396,   400,   401,   402,   403,   407,   408,   412,   413,
     417,   418,   422,   423,   424,   428,   429,   430,   431,   436,
     437,   438,   439,   444,   445,   449,   452,   453,   458,   459
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
  "enum_specifier", "enumerator_list", "enumerator", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "begin", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     825,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,     1,    24,   -38,  -190,    19,   916,
     916,  -190,   -15,    14,    20,   825,    61,  -190,  -190,    -7,
      83,    34,  -190,  -190,   -35,  -190,    68,  -190,  -190,   231,
    -190,   361,   582,    14,  -190,  -190,    83,    67,   -33,  -190,
    -190,    24,  -190,   495,  -190,    79,  -190,  -190,   701,   722,
     722,   738,    97,   122,   135,   138,   477,   139,   119,   123,
     512,   598,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,    45,   148,   738,  -190,    51,    44,   112,    27,   180,
     141,   136,   134,   198,    25,  -190,  -190,   -22,  -190,    19,
    -190,  -190,  -190,   301,   371,  -190,  -190,  -190,  -190,  -190,
      32,   153,   150,  -190,  -190,  -190,  -190,  -190,   159,   -29,
     738,    83,  -190,  -190,   143,   495,  -190,  -190,   477,   598,
    -190,   738,  -190,  -190,   145,   477,   738,   738,   738,   172,
     549,  -190,  -190,  -190,    81,    -4,   840,     6,   165,   227,
    -190,  -190,   619,   738,   228,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,   738,  -190,   738,   738,
     738,   738,   738,   738,   738,   738,   738,   738,   738,   738,
     738,   738,   738,   738,   738,   738,   738,   738,  -190,  -190,
    -190,   407,  -190,  -190,   783,   652,  -190,    46,  -190,   101,
    -190,   916,  -190,  -190,  -190,  -190,  -190,   -28,  -190,   176,
     477,  -190,    49,    54,    94,   181,   549,  -190,  -190,  -190,
     860,   129,  -190,   738,  -190,  -190,    95,  -190,   127,  -190,
    -190,  -190,  -190,  -190,    51,    51,    44,    44,   112,   112,
     112,   112,    27,    27,   180,   141,   136,   134,   198,   -30,
    -190,  -190,  -190,   179,   182,  -190,   183,   101,   896,   668,
    -190,   441,  -190,  -190,  -190,   477,   477,   477,   738,   689,
    -190,  -190,   738,  -190,   738,  -190,  -190,  -190,  -190,   184,
    -190,   186,  -190,  -190,   193,  -190,  -190,   116,   477,   118,
    -190,  -190,  -190,  -190,   477,   166,  -190,   477,  -190,  -190,
    -190
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   110,    98,    86,    87,    89,    90,    91,    92,    95,
      96,    93,    94,    88,     0,     0,   116,   177,     0,    78,
      80,    97,     0,   109,     0,   175,     0,   173,   176,   103,
       0,     0,   117,    76,     0,    82,    84,    79,    81,     0,
     179,     0,     0,   108,   174,     1,     0,   106,     0,   104,
     111,     0,    77,     0,   178,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,   160,   152,
       6,    16,    28,     0,    30,    34,    37,    40,    45,    48,
      50,    52,    54,    56,    58,    60,    73,     0,   156,     0,
     158,   143,   144,     0,     0,   145,   146,   147,   148,   115,
     123,     0,   118,   119,     2,   113,    28,    75,     0,     0,
       0,     0,   101,    83,    84,     0,   138,    85,     0,     0,
      20,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,     0,     0,   100,   124,     0,     0,
      12,    13,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    62,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,   154,
     157,     0,   153,   159,     0,     0,   121,   126,   122,   127,
     114,     0,   112,   102,   107,   105,   141,     0,   149,     0,
       0,   151,     0,     0,     0,     0,     0,   172,     5,    99,
       0,   126,   125,     0,    11,     8,     0,    14,     0,    10,
      61,    31,    32,    33,    35,    36,    38,    39,    43,    44,
      41,    42,    46,    47,    49,    51,    53,    55,    57,     0,
      74,   155,   134,     0,     0,   130,     0,   128,     0,     0,
     120,     0,   139,    21,   150,     0,     0,     0,     0,     0,
      29,     9,     0,     7,     0,   135,   129,   131,   136,     0,
     132,     0,   140,   142,   162,   164,   165,     0,     0,     0,
      15,    59,   137,   133,     0,     0,   167,     0,   163,   166,
     168
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,   -42,  -190,   -71,    26,    33,    10,
      31,    70,    72,    73,    71,    77,  -190,   -41,    -8,  -190,
     -65,   -50,   -14,     9,  -190,   206,  -190,   -64,   117,  -190,
     212,   152,    -5,   -21,     8,   -39,  -190,    75,   154,   -84,
    -189,  -111,  -190,   -45,  -190,    21,  -190,   171,  -125,  -190,
    -190,  -190,  -190,  -190,   252,  -190
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    81,   226,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   166,
      97,   118,    17,   110,    34,    35,    19,    20,   147,    21,
      48,    49,    22,    23,    24,   253,   112,   113,   148,   254,
     199,   127,   207,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    25,    26,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   117,   111,    43,    29,   144,   145,   146,   257,    18,
      31,   134,   167,    36,   206,   216,   130,   132,   133,   116,
     117,   139,     1,     1,    32,    98,   198,     1,    37,    38,
      16,    51,   257,   121,    18,     1,   187,   121,   261,   175,
     176,   116,   185,    40,   187,   126,   124,    52,    99,     1,
     274,   122,   149,   150,   151,   203,   262,    54,   218,   193,
     188,    45,   187,   222,   145,   146,   145,   220,    39,   195,
     204,   212,   213,   214,    16,    41,    46,    42,   116,   117,
      15,    15,   146,   208,    30,    15,    47,    16,   228,   190,
     211,   269,    16,   194,   124,   195,    50,   231,   232,   233,
      16,    33,   177,   178,   186,   196,   152,   194,   153,   195,
     154,   265,    99,   171,   172,   187,   266,   126,   197,   168,
     187,   249,   173,   174,   169,   170,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   227,   256,   193,   187,   120,    53,
     283,    39,   270,   116,   117,   221,   267,   271,   230,   128,
     187,   272,   258,   217,   259,   264,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    43,   135,   295,   250,
     297,   116,   187,   136,   187,   238,   239,   240,   241,    31,
     220,   273,   195,   187,   179,   180,   137,   234,   235,   138,
     140,   141,   197,   287,   289,   142,   236,   237,   181,   281,
     242,   243,   183,   182,   184,   200,   201,   116,   117,   279,
     284,   285,   286,   202,    53,   210,   215,   223,   221,   165,
     224,   229,   116,   291,    55,    56,    57,    58,   263,    59,
      60,   275,   268,   296,   276,   294,   292,   277,   299,   298,
     293,   244,   300,   126,   245,   247,   246,   123,   119,     2,
       3,     4,   248,   219,   290,     5,     6,     7,     8,     9,
      10,    11,    12,   205,   191,    13,   260,    44,    14,     0,
      61,    62,    63,   209,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    55,    56,    57,    58,     0,    59,
      60,     0,     0,    78,    39,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,     0,     0,    14,     0,
      61,    62,    63,     0,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    55,    56,    57,    58,     0,    59,
      60,     0,     0,    78,    39,   189,     0,     0,     0,     2,
       3,     4,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,     0,     0,    14,     0,
      55,    56,    57,    58,     0,    59,    60,     0,     0,     0,
      61,    62,    63,   109,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,   114,    56,    57,    58,     0,    59,
      60,     0,     0,    78,    39,   192,    61,    62,    63,     0,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
      55,    56,    57,    58,     0,    59,    60,     0,     0,    78,
      39,   251,     0,     0,     0,     0,     0,     0,   114,    56,
      57,    58,    71,    59,    60,     0,     0,     0,    72,    73,
      74,    75,    76,    77,     0,   114,    56,    57,    58,     0,
      59,    60,     0,     0,   125,   282,    61,    62,    63,     0,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
       0,     0,   114,    56,    57,    58,    71,    59,    60,    78,
      39,     0,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,   125,    72,
      73,    74,    75,    76,    77,   114,    56,    57,    58,     0,
      59,    60,     0,     0,   143,     0,     0,     0,     0,     0,
       0,   114,    56,    57,    58,     0,    59,    60,     0,     0,
      71,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,   114,    56,    57,    58,     2,    59,    60,     0,
       0,    78,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,    71,     0,    14,   115,     0,     0,    72,
      73,    74,    75,    76,    77,   114,    56,    57,    58,    71,
      59,    60,     0,     0,     0,    72,    73,    74,    75,    76,
      77,   114,    56,    57,    58,     0,    59,    60,     0,     0,
      71,   225,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,   114,    56,    57,    58,     0,    59,    60,     0,
       0,     0,     0,     0,   114,    56,    57,    58,     0,    59,
      60,     0,     0,    71,     0,     0,   255,     0,     0,    72,
      73,    74,    75,    76,    77,   114,    56,    57,    58,    71,
      59,    60,   280,     0,     0,    72,    73,    74,    75,    76,
      77,   114,    56,    57,    58,     0,    59,    60,     0,     0,
      71,   288,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,   129,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     1,     0,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,     2,     3,     4,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,     1,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   252,   195,     0,     0,     0,
       0,    16,     0,     2,     3,     4,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     2,    13,
       0,     0,    14,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,     0,    15,    14,     2,     3,
       4,     0,     0,    16,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   252,   195,     2,     3,     4,     0,    16,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,     0,     0,    14,     2,     3,     4,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,   278,     0,
      13,     0,     0,    14
};

static const yytype_int16 yycheck[] =
{
      42,    42,    41,    24,     3,    70,    71,    71,   197,     0,
      15,    61,    83,    18,   125,   140,    58,    59,    60,    61,
      61,    66,     3,     3,    16,    39,   110,     3,    19,    20,
      68,    66,   221,    66,    25,     3,    66,    66,    66,    12,
      13,    83,    17,    22,    66,    53,    51,    82,    39,     3,
      80,    84,     7,     8,     9,    84,    84,    36,    62,   104,
      82,     0,    66,   147,   129,   129,   131,    61,    83,    63,
     120,   136,   137,   138,    68,    61,    83,    63,   120,   120,
      61,    61,   146,   128,    83,    61,     3,    68,   153,   103,
     135,   216,    68,    61,    99,    63,    62,   168,   169,   170,
      68,    82,    75,    76,    79,   110,    61,    61,    63,    63,
      65,    62,   103,    69,    70,    66,    62,   125,   110,    68,
      66,   186,    10,    11,    73,    74,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   152,   195,   191,    66,    81,    81,
     261,    83,   223,   195,   195,   147,    62,    62,   166,    80,
      66,    66,    61,    82,    63,   210,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   197,    80,    62,   187,
      62,   223,    66,    61,    66,   175,   176,   177,   178,   194,
      61,    64,    63,    66,    14,    15,    61,   171,   172,    61,
      61,    82,   194,   268,   269,    82,   173,   174,    67,   259,
     179,   180,    78,    77,    16,    62,    66,   259,   259,   258,
     265,   266,   267,    64,    81,    80,    54,    62,   220,    81,
       3,     3,   274,   274,     3,     4,     5,     6,    62,     8,
       9,    62,    61,   288,    62,    52,    62,    64,    82,   294,
      64,   181,   297,   261,   182,   184,   183,    51,    46,    28,
      29,    30,   185,   146,   272,    34,    35,    36,    37,    38,
      39,    40,    41,   121,   103,    44,   201,    25,    47,    -1,
      49,    50,    51,   129,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,    47,    -1,
      49,    50,    51,    -1,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,    47,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      49,    50,    51,    62,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    83,    84,    49,    50,    51,    -1,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    61,     8,     9,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    83,    84,    49,    50,    51,    -1,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,     3,     4,     5,     6,    61,     8,     9,    82,
      83,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    83,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    28,     8,     9,    -1,
      -1,    82,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    61,    -1,    47,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    61,
       8,     9,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    61,
       8,     9,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,     3,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    28,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,     3,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    28,    44,
      -1,    -1,    47,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    -1,    61,    47,    28,    29,
      30,    -1,    -1,    68,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    28,    29,    30,    -1,    68,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    47,    28,    29,    30,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    62,    -1,
      44,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    44,    47,    61,    68,   107,   108,   111,
     112,   114,   117,   118,   119,   137,   138,   139,   140,     3,
      83,   117,   119,    82,   109,   110,   117,   108,   108,    83,
     130,    61,    63,   118,   139,     0,    83,     3,   115,   116,
      62,    66,    82,    81,   130,     3,     4,     5,     6,     8,
       9,    49,    50,    51,    53,    54,    55,    56,    58,    59,
      60,    61,    67,    68,    69,    70,    71,    72,    82,    84,
      86,    87,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   105,   107,   108,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    62,
     108,   120,   121,   122,     3,    64,    89,   102,   106,   115,
      81,    66,    84,   110,   117,    83,   103,   126,    80,    61,
      89,    61,    89,    89,   106,    80,    61,    61,    61,   128,
      61,    82,    82,    82,   105,   105,   112,   113,   123,     7,
       8,     9,    61,    63,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    81,   104,    91,    68,    73,
      74,    69,    70,    10,    11,    12,    13,    75,    76,    14,
      15,    67,    77,    78,    16,    17,    79,    66,    82,    84,
     107,   132,    84,   128,    61,    63,   117,   119,   124,   125,
      62,    66,    64,    84,   106,   116,   126,   127,   128,   123,
      80,   128,   105,   105,   105,    54,   133,    82,    62,   113,
      61,   119,   124,    62,     3,    62,    88,   103,   105,     3,
     103,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    96,    97,    98,    99,   100,   105,
     103,    84,    62,   120,   124,    64,   106,   125,    61,    63,
     122,    66,    84,    62,   128,    62,    62,    62,    61,   133,
      91,    62,    66,    64,    80,    62,    62,    64,    62,   120,
      64,   106,    84,   126,   128,   128,   128,   105,    62,   105,
     103,   102,    62,    64,    52,    62,   128,    62,   128,    82,
     128
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
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   114,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     126,   127,   127,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   135,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   139,   139,   140,   140
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     5,     2,     1,     3,     1,     3,     2,     1,
       1,     3,     4,     3,     4,     3,     1,     2,     1,     1,
       3,     2,     2,     1,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     2,
       2,     2,     3,     1,     2,     1,     1,     1,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 55 "src/parser.y"
                        {(yyval.expr) = new primary_expression(0,*(yyvsp[0].str)); std::cerr << "primary expression 1, which is IDENTIFIER : " <<  *(yyvsp[0].str) << std::endl;}
#line 1755 "src/parser.tab.cpp"
    break;

  case 3:
#line 56 "src/parser.y"
                        {(yyval.expr) = new primary_expression(1,*(yyvsp[0].str)); std::cerr << "primary expression 2, which is const with value: " << *(yyvsp[0].str) <<std::endl;}
#line 1761 "src/parser.tab.cpp"
    break;

  case 4:
#line 57 "src/parser.y"
                         {(yyval.expr) = new primary_expression(2,*(yyvsp[0].str)); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
#line 1767 "src/parser.tab.cpp"
    break;

  case 5:
#line 58 "src/parser.y"
                             {(yyval.expr) = new primary_expression(3,(yyvsp[-1].expr)); std::cerr << "primary expression 4" << std::endl;}
#line 1773 "src/parser.tab.cpp"
    break;

  case 6:
#line 62 "src/parser.y"
                                                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "postfix expression 1" << std::endl;}
#line 1779 "src/parser.tab.cpp"
    break;

  case 7:
#line 63 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(0, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 2" << std::endl;}
#line 1785 "src/parser.tab.cpp"
    break;

  case 8:
#line 64 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(1, (yyvsp[-2].expr));std::cerr << "postfix expression 3" << std::endl;}
#line 1791 "src/parser.tab.cpp"
    break;

  case 9:
#line 65 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(2, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 4" << std::endl;}
#line 1797 "src/parser.tab.cpp"
    break;

  case 10:
#line 66 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(3, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 5" << std::endl;}
#line 1803 "src/parser.tab.cpp"
    break;

  case 11:
#line 67 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 6" << std::endl;}
#line 1809 "src/parser.tab.cpp"
    break;

  case 12:
#line 68 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(5, (yyvsp[-1].expr));std::cerr << "postfix expression 7" << std::endl;}
#line 1815 "src/parser.tab.cpp"
    break;

  case 13:
#line 69 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr));std::cerr << "postfix expression 8" << std::endl;}
#line 1821 "src/parser.tab.cpp"
    break;

  case 14:
#line 73 "src/parser.y"
                                                                 {(yyval.expr) = new argument_expression_list((yyvsp[0].expr)); std::cerr << "argument expression 1" << std::endl;}
#line 1827 "src/parser.tab.cpp"
    break;

  case 15:
#line 74 "src/parser.y"
                                                                 {(yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "argument expression 2" << std::endl;}
#line 1833 "src/parser.tab.cpp"
    break;

  case 16:
#line 78 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "unary expression 1" << std::endl;}
#line 1839 "src/parser.tab.cpp"
    break;

  case 17:
#line 79 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(0, (yyvsp[0].expr)); std::cerr << "unary expression 2" << std::endl;}
#line 1845 "src/parser.tab.cpp"
    break;

  case 18:
#line 80 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); std::cerr << "unary expression 3" << std::endl;}
#line 1851 "src/parser.tab.cpp"
    break;

  case 19:
#line 81 "src/parser.y"
                                           {(yyval.expr) = new unary_expression((yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "unary expression 4" << std::endl;}
#line 1857 "src/parser.tab.cpp"
    break;

  case 20:
#line 82 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); std::cerr << "unary expression 5" << std::endl;}
#line 1863 "src/parser.tab.cpp"
    break;

  case 21:
#line 83 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(3, (yyvsp[-1].expr)); std::cerr << "unary expression 6" << std::endl;}
#line 1869 "src/parser.tab.cpp"
    break;

  case 22:
#line 87 "src/parser.y"
                   {(yyval.number) = 4; std::cerr << "unary operator 1" << std::endl;}
#line 1875 "src/parser.tab.cpp"
    break;

  case 23:
#line 88 "src/parser.y"
                   {(yyval.number) = 5; std::cerr << "unary operator 2" << std::endl;}
#line 1881 "src/parser.tab.cpp"
    break;

  case 24:
#line 89 "src/parser.y"
                   {(yyval.number) = 6; std::cerr << "unary operator 3" << std::endl;}
#line 1887 "src/parser.tab.cpp"
    break;

  case 25:
#line 90 "src/parser.y"
                   {(yyval.number) = 7; std::cerr << "unary operator 4" << std::endl;}
#line 1893 "src/parser.tab.cpp"
    break;

  case 26:
#line 91 "src/parser.y"
                   {(yyval.number) = 8; std::cerr << "unary operator 5" << std::endl;}
#line 1899 "src/parser.tab.cpp"
    break;

  case 27:
#line 92 "src/parser.y"
                   {(yyval.number) = 9; std::cerr << "unary operator 6" << std::endl;}
#line 1905 "src/parser.tab.cpp"
    break;

  case 28:
#line 96 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "cast expression 1" << std::endl;}
#line 1911 "src/parser.tab.cpp"
    break;

  case 29:
#line 97 "src/parser.y"
                                                 {(yyval.expr) = new cast_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "cast expression 2" << std::endl;}
#line 1917 "src/parser.tab.cpp"
    break;

  case 30:
#line 101 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr); std::cerr << "mulitiplicative expression 1" << std::endl;}
#line 1923 "src/parser.tab.cpp"
    break;

  case 31:
#line 102 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(1,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 2" << std::endl;}
#line 1929 "src/parser.tab.cpp"
    break;

  case 32:
#line 103 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(2,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 3" << std::endl;}
#line 1935 "src/parser.tab.cpp"
    break;

  case 33:
#line 104 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(3,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 4" << std::endl;}
#line 1941 "src/parser.tab.cpp"
    break;

  case 34:
#line 108 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr); std::cerr << "additive_expression 1" << std::endl;}
#line 1947 "src/parser.tab.cpp"
    break;

  case 35:
#line 109 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 2" << std::endl;}
#line 1953 "src/parser.tab.cpp"
    break;

  case 36:
#line 110 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 3" << std::endl;}
#line 1959 "src/parser.tab.cpp"
    break;

  case 37:
#line 114 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "shift_expression 1" << std::endl;}
#line 1965 "src/parser.tab.cpp"
    break;

  case 38:
#line 115 "src/parser.y"
                                                       {(yyval.expr) = new shift_expression(1,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 2" << std::endl;}
#line 1971 "src/parser.tab.cpp"
    break;

  case 39:
#line 116 "src/parser.y"
                                                        {(yyval.expr) = new shift_expression(2,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 3" << std::endl;}
#line 1977 "src/parser.tab.cpp"
    break;

  case 40:
#line 120 "src/parser.y"
                                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "relational_expression 1" << std::endl;}
#line 1983 "src/parser.tab.cpp"
    break;

  case 41:
#line 121 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 2" << std::endl;}
#line 1989 "src/parser.tab.cpp"
    break;

  case 42:
#line 122 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 3" << std::endl;}
#line 1995 "src/parser.tab.cpp"
    break;

  case 43:
#line 123 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 4" << std::endl;}
#line 2001 "src/parser.tab.cpp"
    break;

  case 44:
#line 124 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(3, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 5" << std::endl;}
#line 2007 "src/parser.tab.cpp"
    break;

  case 45:
#line 128 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "equality_expression 1" << std::endl;}
#line 2013 "src/parser.tab.cpp"
    break;

  case 46:
#line 129 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(4, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 2" << std::endl;}
#line 2019 "src/parser.tab.cpp"
    break;

  case 47:
#line 130 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(5, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 3" << std::endl;}
#line 2025 "src/parser.tab.cpp"
    break;

  case 48:
#line 134 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "and_expression 1" << std::endl;}
#line 2031 "src/parser.tab.cpp"
    break;

  case 49:
#line 135 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(6, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "and_expression 2" << std::endl;}
#line 2037 "src/parser.tab.cpp"
    break;

  case 50:
#line 139 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "exclusive_or_expression 1" << std::endl;}
#line 2043 "src/parser.tab.cpp"
    break;

  case 51:
#line 140 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(7, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "exclusive_or_expression 2" << std::endl;}
#line 2049 "src/parser.tab.cpp"
    break;

  case 52:
#line 144 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "inclusive_or_expression 1" << std::endl;}
#line 2055 "src/parser.tab.cpp"
    break;

  case 53:
#line 145 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(8, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "inclusive_or_expression 2" << std::endl;}
#line 2061 "src/parser.tab.cpp"
    break;

  case 54:
#line 149 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_and_expression 1" << std::endl;}
#line 2067 "src/parser.tab.cpp"
    break;

  case 55:
#line 150 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(9, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_and_expression 2" << std::endl;}
#line 2073 "src/parser.tab.cpp"
    break;

  case 56:
#line 154 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_or_expression 1" << std::endl;}
#line 2079 "src/parser.tab.cpp"
    break;

  case 57:
#line 155 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(10, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_or_expression 2" << std::endl;}
#line 2085 "src/parser.tab.cpp"
    break;

  case 58:
#line 159 "src/parser.y"
                                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "conditional expression 1" << std::endl;}
#line 2091 "src/parser.tab.cpp"
    break;

  case 59:
#line 160 "src/parser.y"
                                                                             {(yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "conditional expression 2" << std::endl;}
#line 2097 "src/parser.tab.cpp"
    break;

  case 60:
#line 164 "src/parser.y"
                                                                             {(yyval.expr) = new assignment_expression((yyvsp[0].expr)); std::cerr << "assignment expression 1" << std::endl;}
#line 2103 "src/parser.tab.cpp"
    break;

  case 61:
#line 165 "src/parser.y"
                                                                             {(yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "assignment expression 2" << std::endl;}
#line 2109 "src/parser.tab.cpp"
    break;

  case 62:
#line 169 "src/parser.y"
                             {(yyval.number) = 0; std::cerr << "assignment operator 1" << std::endl;}
#line 2115 "src/parser.tab.cpp"
    break;

  case 63:
#line 170 "src/parser.y"
                             {(yyval.number) = 1; std::cerr << "assignment operator 2" << std::endl;}
#line 2121 "src/parser.tab.cpp"
    break;

  case 64:
#line 171 "src/parser.y"
                             {(yyval.number) = 2; std::cerr << "assignment operator 3" << std::endl;}
#line 2127 "src/parser.tab.cpp"
    break;

  case 65:
#line 172 "src/parser.y"
                             {(yyval.number) = 3; std::cerr << "assignment operator 4" << std::endl;}
#line 2133 "src/parser.tab.cpp"
    break;

  case 66:
#line 173 "src/parser.y"
                             {(yyval.number) = 4; std::cerr << "assignment operator 5" << std::endl;}
#line 2139 "src/parser.tab.cpp"
    break;

  case 67:
#line 174 "src/parser.y"
                             {(yyval.number) = 5; std::cerr << "assignment operator 6" << std::endl;}
#line 2145 "src/parser.tab.cpp"
    break;

  case 68:
#line 175 "src/parser.y"
                             {(yyval.number) = 6; std::cerr << "assignment operator 7" << std::endl;}
#line 2151 "src/parser.tab.cpp"
    break;

  case 69:
#line 176 "src/parser.y"
                             {(yyval.number) = 7; std::cerr << "assignment operator 8" << std::endl;}
#line 2157 "src/parser.tab.cpp"
    break;

  case 70:
#line 177 "src/parser.y"
                             {(yyval.number) = 8; std::cerr << "assignment operator 9" << std::endl;}
#line 2163 "src/parser.tab.cpp"
    break;

  case 71:
#line 178 "src/parser.y"
                             {(yyval.number) = 9; std::cerr << "assignment operator 10" << std::endl;}
#line 2169 "src/parser.tab.cpp"
    break;

  case 72:
#line 179 "src/parser.y"
                             {(yyval.number) = 10; std::cerr << "assignment operator 11" << std::endl;}
#line 2175 "src/parser.tab.cpp"
    break;

  case 73:
#line 183 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "expression 1" << std::endl;}
#line 2181 "src/parser.tab.cpp"
    break;

  case 74:
#line 184 "src/parser.y"
                                                 {(yyval.expr) = new base_expression((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "expression 2" << std::endl;}
#line 2187 "src/parser.tab.cpp"
    break;

  case 75:
#line 188 "src/parser.y"
                                   {(yyval.expr) = (yyvsp[0].expr); std::cerr << "constant_expression 0" << std::endl;}
#line 2193 "src/parser.tab.cpp"
    break;

  case 76:
#line 192 "src/parser.y"
                                      {(yyval.expr) = new declaration((yyvsp[-1].expr)); std::cerr << "declaration 0 " << std::endl;}
#line 2199 "src/parser.tab.cpp"
    break;

  case 77:
#line 193 "src/parser.y"
                                                           {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr));std::cerr << "declaration 1 " << std::endl;}
#line 2205 "src/parser.tab.cpp"
    break;

  case 78:
#line 197 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 0" << std::endl;}
#line 2211 "src/parser.tab.cpp"
    break;

  case 79:
#line 198 "src/parser.y"
                                                           {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 1" << std::endl;}
#line 2217 "src/parser.tab.cpp"
    break;

  case 80:
#line 199 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 2" << std::endl;}
#line 2223 "src/parser.tab.cpp"
    break;

  case 81:
#line 200 "src/parser.y"
                                                   {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 3" << std::endl;}
#line 2229 "src/parser.tab.cpp"
    break;

  case 82:
#line 206 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr); std::cerr << "init_declarator_list 0 " << std::endl;}
#line 2235 "src/parser.tab.cpp"
    break;

  case 83:
#line 207 "src/parser.y"
                                                     {(yyval.expr) = new init_declarator_list((yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "init_declarator_list 1" << std::endl;}
#line 2241 "src/parser.tab.cpp"
    break;

  case 84:
#line 211 "src/parser.y"
                       {(yyval.expr) = new init_declarator((yyvsp[0].expr)); std::cerr << "init_declarator 0 " << std::endl;}
#line 2247 "src/parser.tab.cpp"
    break;

  case 85:
#line 212 "src/parser.y"
                                       {(yyval.expr) = new init_declarator((yyvsp[-2].expr),(yyvsp[0].expr));  std::cerr << "init_declarator 1" << std::endl;}
#line 2253 "src/parser.tab.cpp"
    break;

  case 86:
#line 216 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
#line 2259 "src/parser.tab.cpp"
    break;

  case 87:
#line 217 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}
#line 2265 "src/parser.tab.cpp"
    break;

  case 88:
#line 224 "src/parser.y"
                 {(yyval.expr) = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
#line 2271 "src/parser.tab.cpp"
    break;

  case 89:
#line 225 "src/parser.y"
                 {(yyval.expr) = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
#line 2277 "src/parser.tab.cpp"
    break;

  case 90:
#line 226 "src/parser.y"
                  {(yyval.expr) = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
#line 2283 "src/parser.tab.cpp"
    break;

  case 91:
#line 227 "src/parser.y"
                {(yyval.expr) = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
#line 2289 "src/parser.tab.cpp"
    break;

  case 92:
#line 228 "src/parser.y"
                 {(yyval.expr) = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
#line 2295 "src/parser.tab.cpp"
    break;

  case 93:
#line 229 "src/parser.y"
                  {(yyval.expr) = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
#line 2301 "src/parser.tab.cpp"
    break;

  case 94:
#line 230 "src/parser.y"
                   {(yyval.expr) = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
#line 2307 "src/parser.tab.cpp"
    break;

  case 95:
#line 231 "src/parser.y"
                   {(yyval.expr) = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
#line 2313 "src/parser.tab.cpp"
    break;

  case 96:
#line 232 "src/parser.y"
                     {(yyval.expr) = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
#line 2319 "src/parser.tab.cpp"
    break;

  case 97:
#line 234 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "type_specifier signed enum 10" << std::endl;}
#line 2325 "src/parser.tab.cpp"
    break;

  case 98:
#line 235 "src/parser.y"
                      {(yyval.expr) = new type_specifier(10); std::cerr << "type_name" << std::endl;}
#line 2331 "src/parser.tab.cpp"
    break;

  case 99:
#line 260 "src/parser.y"
                                                  {(yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "specifier_qualifier_list 0" << std::endl;}
#line 2337 "src/parser.tab.cpp"
    break;

  case 100:
#line 261 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "specifier_qualifier_list 1" << std::endl;}
#line 2343 "src/parser.tab.cpp"
    break;

  case 101:
#line 279 "src/parser.y"
                                           {(yyval.expr) = new enum_specifier(0,(yyvsp[-1].expr)); std::cerr << "enum_specifier 0" << std::endl;}
#line 2349 "src/parser.tab.cpp"
    break;

  case 102:
#line 280 "src/parser.y"
                                                     {(yyval.expr) = new enum_specifier(1,*(yyvsp[-3].str),(yyvsp[-1].expr)); std::cerr << "enum_specifier 1" << std::endl;}
#line 2355 "src/parser.tab.cpp"
    break;

  case 103:
#line 281 "src/parser.y"
                                 {(yyval.expr) = new enum_specifier(2,*(yyvsp[0].str)); std::cerr << "enum_specifier 2" << std::endl;}
#line 2361 "src/parser.tab.cpp"
    break;

  case 104:
#line 285 "src/parser.y"
                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "enumerator_list 0" << std::endl;}
#line 2367 "src/parser.tab.cpp"
    break;

  case 105:
#line 286 "src/parser.y"
                                            {(yyval.expr) = new enumerator_list((yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "enumerator_list 1" << std::endl;}
#line 2373 "src/parser.tab.cpp"
    break;

  case 106:
#line 290 "src/parser.y"
                         {(yyval.expr) = new enumerator(*(yyvsp[0].str)); std::cerr << "enumerator 0" << std::endl;}
#line 2379 "src/parser.tab.cpp"
    break;

  case 107:
#line 291 "src/parser.y"
                                                 {(yyval.expr) = new enumerator(*(yyvsp[-2].str),(yyvsp[0].expr)); std::cerr << "enumerator 0" << std::endl;}
#line 2385 "src/parser.tab.cpp"
    break;

  case 108:
#line 302 "src/parser.y"
                                     {(yyval.expr) = new declarator((yyvsp[-1].expr), (yyvsp[0].expr));  std::cerr << "declarator 0" << std::endl;}
#line 2391 "src/parser.tab.cpp"
    break;

  case 109:
#line 303 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "declarator 1" << std::endl;}
#line 2397 "src/parser.tab.cpp"
    break;

  case 110:
#line 307 "src/parser.y"
                       {(yyval.expr) = new direct_declarator(0,*(yyvsp[0].str));std::cerr << "direct_declarator 0,IDENTIFIER : " << *(yyvsp[0].str) <<std::endl; }
#line 2403 "src/parser.tab.cpp"
    break;

  case 111:
#line 308 "src/parser.y"
                              {(yyval.expr) = new direct_declarator(1,(yyvsp[-1].expr)); std::cerr << "direct_declarator 1" << std::endl;}
#line 2409 "src/parser.tab.cpp"
    break;

  case 112:
#line 309 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(2,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 2" << std::endl;}
#line 2415 "src/parser.tab.cpp"
    break;

  case 113:
#line 310 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(3,(yyvsp[-2].expr));  std::cerr << "direct_declarator 3" << std::endl;}
#line 2421 "src/parser.tab.cpp"
    break;

  case 114:
#line 311 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(4,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 4" << std::endl;}
#line 2427 "src/parser.tab.cpp"
    break;

  case 115:
#line 313 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(6,(yyvsp[-2].expr));  std::cerr << "direct_declarator 6" << std::endl;}
#line 2433 "src/parser.tab.cpp"
    break;

  case 116:
#line 316 "src/parser.y"
              {(yyval.expr) = new pointer(0); std::cerr << "pointer 0" << std::endl;}
#line 2439 "src/parser.tab.cpp"
    break;

  case 117:
#line 318 "src/parser.y"
                        {(yyval.expr) = new pointer(1, (yyvsp[0].expr)); std::cerr << "pointer 1" << std::endl;}
#line 2445 "src/parser.tab.cpp"
    break;

  case 118:
#line 329 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_type_list 0" << std::endl;}
#line 2451 "src/parser.tab.cpp"
    break;

  case 119:
#line 334 "src/parser.y"
                                                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_list 0" << std::endl; }
#line 2457 "src/parser.tab.cpp"
    break;

  case 120:
#line 335 "src/parser.y"
                                                       {(yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "parameter_list 1" << std::endl;}
#line 2463 "src/parser.tab.cpp"
    break;

  case 121:
#line 339 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 0" << std::endl; }
#line 2469 "src/parser.tab.cpp"
    break;

  case 122:
#line 340 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(1, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 1" << std::endl; }
#line 2475 "src/parser.tab.cpp"
    break;

  case 123:
#line 341 "src/parser.y"
                                                   {(yyval.expr) = new parameter_declaration(2, (yyvsp[0].expr)); std::cerr << "parameter_declaration 2" << std::endl;  }
#line 2481 "src/parser.tab.cpp"
    break;

  case 124:
#line 350 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);std::cerr << "type name 1" << std::endl; }
#line 2487 "src/parser.tab.cpp"
    break;

  case 125:
#line 351 "src/parser.y"
                                                         {(yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr));std::cerr << "type name 2" << std::endl;}
#line 2493 "src/parser.tab.cpp"
    break;

  case 126:
#line 355 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "abstract_declarator 0" << std::endl;}
#line 2499 "src/parser.tab.cpp"
    break;

  case 127:
#line 356 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "abstract_declarator 1" << std::endl;}
#line 2505 "src/parser.tab.cpp"
    break;

  case 128:
#line 357 "src/parser.y"
                                                         {(yyval.expr) = new abstract_declarator((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "abstract_declarator 2" << std::endl;}
#line 2511 "src/parser.tab.cpp"
    break;

  case 129:
#line 362 "src/parser.y"
                                                                     {(yyval.expr) = (yyvsp[-1].expr);  std::cerr << "direct_abstract_declarator 0" << std::endl;}
#line 2517 "src/parser.tab.cpp"
    break;

  case 130:
#line 363 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(0);  std::cerr << "direct_abstract_declarator 1" << std::endl;}
#line 2523 "src/parser.tab.cpp"
    break;

  case 131:
#line 364 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(1, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 2" << std::endl;}
#line 2529 "src/parser.tab.cpp"
    break;

  case 132:
#line 365 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 3" << std::endl;}
#line 2535 "src/parser.tab.cpp"
    break;

  case 133:
#line 366 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 4" << std::endl;}
#line 2541 "src/parser.tab.cpp"
    break;

  case 134:
#line 367 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(4);  std::cerr << "direct_abstract_declarator 5" << std::endl;}
#line 2547 "src/parser.tab.cpp"
    break;

  case 135:
#line 368 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(5, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 6" << std::endl;}
#line 2553 "src/parser.tab.cpp"
    break;

  case 136:
#line 369 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(6, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 7" << std::endl;}
#line 2559 "src/parser.tab.cpp"
    break;

  case 137:
#line 370 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 8" << std::endl;}
#line 2565 "src/parser.tab.cpp"
    break;

  case 138:
#line 374 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "initializer 0" << std::endl;}
#line 2571 "src/parser.tab.cpp"
    break;

  case 139:
#line 375 "src/parser.y"
                                                 {(yyval.expr) = new initializer(0, (yyvsp[-1].expr)); std::cerr << "initializer 1" << std::endl;}
#line 2577 "src/parser.tab.cpp"
    break;

  case 140:
#line 376 "src/parser.y"
                                                 {(yyval.expr) = new initializer(1, (yyvsp[-2].expr)); std::cerr << "initializer 2" << std::endl;}
#line 2583 "src/parser.tab.cpp"
    break;

  case 141:
#line 380 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(0, (yyvsp[0].expr)); std::cerr << "initializer_list 0" << std::endl;}
#line 2589 "src/parser.tab.cpp"
    break;

  case 142:
#line 381 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "initializer_list 1" << std::endl;}
#line 2595 "src/parser.tab.cpp"
    break;

  case 143:
#line 385 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 0" << std::endl;}
#line 2601 "src/parser.tab.cpp"
    break;

  case 144:
#line 386 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 1" << std::endl; }
#line 2607 "src/parser.tab.cpp"
    break;

  case 145:
#line 387 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 2" << std::endl;}
#line 2613 "src/parser.tab.cpp"
    break;

  case 146:
#line 388 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 3" << std::endl;}
#line 2619 "src/parser.tab.cpp"
    break;

  case 147:
#line 389 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 4" << std::endl;}
#line 2625 "src/parser.tab.cpp"
    break;

  case 148:
#line 390 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 5" << std::endl;}
#line 2631 "src/parser.tab.cpp"
    break;

  case 149:
#line 394 "src/parser.y"
                                     {(yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); std::cerr << "labeled_statement 0" << std::endl;}
#line 2637 "src/parser.tab.cpp"
    break;

  case 150:
#line 395 "src/parser.y"
                                                   {(yyval.expr) = new labeled_statement(1, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "labeled_statement 1" << std::endl;}
#line 2643 "src/parser.tab.cpp"
    break;

  case 151:
#line 396 "src/parser.y"
                                   {(yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); std::cerr << "labeled_statement 2" << std::endl;}
#line 2649 "src/parser.tab.cpp"
    break;

  case 152:
#line 400 "src/parser.y"
                     {(yyval.expr) = new compound_statement(0); std::cerr << "compound_statement 0" << std::endl;}
#line 2655 "src/parser.tab.cpp"
    break;

  case 153:
#line 401 "src/parser.y"
                                   {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr)); std::cerr << "compound_statement 1" << std::endl;}
#line 2661 "src/parser.tab.cpp"
    break;

  case 154:
#line 402 "src/parser.y"
                                     {(yyval.expr) = new compound_statement(2, (yyvsp[-1].expr)); std::cerr << "compound_statement 2" << std::endl;}
#line 2667 "src/parser.tab.cpp"
    break;

  case 155:
#line 403 "src/parser.y"
                                                     {(yyval.expr) = new compound_statement(3, (yyvsp[-2].expr), (yyvsp[-1].expr)); std::cerr << "compound_statement 3" << std::endl;}
#line 2673 "src/parser.tab.cpp"
    break;

  case 156:
#line 407 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "declaration list 1" << std::endl;}
#line 2679 "src/parser.tab.cpp"
    break;

  case 157:
#line 408 "src/parser.y"
                                           {(yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "declaration list 2" << std::endl;}
#line 2685 "src/parser.tab.cpp"
    break;

  case 158:
#line 412 "src/parser.y"
                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement_list 0" << std::endl;}
#line 2691 "src/parser.tab.cpp"
    break;

  case 159:
#line 413 "src/parser.y"
                                     {(yyval.expr) = new statement_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "statement_list 1" << std::endl;}
#line 2697 "src/parser.tab.cpp"
    break;

  case 160:
#line 417 "src/parser.y"
                 {(yyval.expr) = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
#line 2703 "src/parser.tab.cpp"
    break;

  case 161:
#line 418 "src/parser.y"
                           {(yyval.expr) = new expression_statement((yyvsp[-1].expr));std::cerr << "expression_statement 1" << std::endl;}
#line 2709 "src/parser.tab.cpp"
    break;

  case 162:
#line 422 "src/parser.y"
                                             {(yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 0" << std::endl;}
#line 2715 "src/parser.tab.cpp"
    break;

  case 163:
#line 423 "src/parser.y"
                                                           {(yyval.expr) = new selection_statement(1, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 1" << std::endl;}
#line 2721 "src/parser.tab.cpp"
    break;

  case 164:
#line 424 "src/parser.y"
                                                 {(yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 2" << std::endl;}
#line 2727 "src/parser.tab.cpp"
    break;

  case 165:
#line 428 "src/parser.y"
                                               {(yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "iteration_statement 0 " << std::endl;}
#line 2733 "src/parser.tab.cpp"
    break;

  case 166:
#line 429 "src/parser.y"
                                                       {(yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));std::cerr << "iteration_statement 1 " << std::endl;}
#line 2739 "src/parser.tab.cpp"
    break;

  case 167:
#line 430 "src/parser.y"
                                                                             {(yyval.expr) = new iteration_statement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 2 " << std::endl;}
#line 2745 "src/parser.tab.cpp"
    break;

  case 168:
#line 431 "src/parser.y"
                                                                                       {(yyval.expr) = new iteration_statement(3, (yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 3 " << std::endl;}
#line 2751 "src/parser.tab.cpp"
    break;

  case 169:
#line 436 "src/parser.y"
                         {(yyval.expr) = new jump_statement(1, "CONTINUE");std::cerr << "jump_statement 1 " << std::endl;}
#line 2757 "src/parser.tab.cpp"
    break;

  case 170:
#line 437 "src/parser.y"
                       {(yyval.expr) = new jump_statement(2, "BREAK");std::cerr << "jump_statement 2 " << std::endl;}
#line 2763 "src/parser.tab.cpp"
    break;

  case 171:
#line 438 "src/parser.y"
                       {(yyval.expr) = new jump_statement(3, "RETURN");std::cerr << "jump_statement 3 " << std::endl;}
#line 2769 "src/parser.tab.cpp"
    break;

  case 172:
#line 439 "src/parser.y"
                                   {(yyval.expr) = new jump_statement(4, (yyvsp[-1].expr));std::cerr << "jump_statement 4 " << std::endl;}
#line 2775 "src/parser.tab.cpp"
    break;

  case 173:
#line 444 "src/parser.y"
                                                   {(yyval.expr) = (yyvsp[0].expr);std::cerr << " translation_unit 1" << std::endl;}
#line 2781 "src/parser.tab.cpp"
    break;

  case 174:
#line 445 "src/parser.y"
                                                   {std::cerr << "translation_unit 2" << std::endl;(yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2787 "src/parser.tab.cpp"
    break;

  case 175:
#line 449 "src/parser.y"
                        {g_root = (yyvsp[0].expr);}
#line 2793 "src/parser.tab.cpp"
    break;

  case 176:
#line 452 "src/parser.y"
                                     {(yyval.expr) = new external_declaration(0,(yyvsp[0].expr));std::cerr << "external declaration 1" << std::endl;}
#line 2799 "src/parser.tab.cpp"
    break;

  case 177:
#line 453 "src/parser.y"
                                     {(yyval.expr) =  new external_declaration(1,(yyvsp[0].expr));std::cerr << "external declaration 2" << std::endl;}
#line 2805 "src/parser.tab.cpp"
    break;

  case 178:
#line 458 "src/parser.y"
                                                                                 {std::cerr << "function definition 1" << std::endl;(yyval.expr) = new function_definition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2811 "src/parser.tab.cpp"
    break;

  case 179:
#line 459 "src/parser.y"
                                                                           {std::cerr << "function definition 2" << std::endl;(yyval.expr) = new function_definition((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2817 "src/parser.tab.cpp"
    break;


#line 2821 "src/parser.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 463 "src/parser.y"

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
