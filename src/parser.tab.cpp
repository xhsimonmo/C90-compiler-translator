/* A Bison parser, made by GNU Bison 3.5.1.  */

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
#define YYBISON_VERSION "3.5.1"

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   918

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

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
     226,   227,   228,   229,   230,   231,   232,   235,   260,   261,
     301,   302,   306,   307,   308,   309,   310,   311,   312,   315,
     317,   328,   333,   334,   338,   339,   340,   344,   345,   349,
     350,   354,   355,   356,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   373,   374,   375,   379,   380,   384,   385,
     386,   387,   388,   389,   393,   394,   395,   399,   400,   401,
     402,   406,   407,   411,   412,   416,   417,   421,   422,   423,
     427,   428,   429,   430,   435,   436,   437,   438,   443,   444,
     448,   451,   452,   457,   458
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
  "jump_statement", "translation_unit", "begin", "external_declaration",
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

#define YYPACT_NINF (-165)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     802,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,    36,   -15,  -165,     7,   873,   873,
       5,    33,    11,   802,    93,  -165,  -165,     4,  -165,  -165,
     -41,  -165,   -31,  -165,  -165,   232,  -165,   362,   548,    33,
    -165,  -165,  -165,    36,  -165,   182,  -165,    19,  -165,  -165,
     678,   703,   703,   748,    45,    69,   128,   131,   444,   134,
      85,   122,   478,   563,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,   500,   301,   748,  -165,   -10,   114,    72,
      35,    91,   108,   136,   130,   195,    12,  -165,  -165,   -26,
    -165,     7,  -165,  -165,  -165,   302,   372,  -165,  -165,  -165,
    -165,  -165,  -165,    13,   152,   149,  -165,   -47,  -165,  -165,
    -165,  -165,   155,  -165,   140,   182,  -165,  -165,   444,   563,
    -165,   748,  -165,  -165,   142,   444,   748,   748,   748,   170,
     514,  -165,  -165,  -165,   -12,     3,   496,    -6,   163,   224,
    -165,  -165,   584,   748,   225,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,   748,  -165,   748,   748,
     748,   748,   748,   748,   748,   748,   748,   748,   748,   748,
     748,   748,   748,   748,   748,   748,   748,   748,  -165,  -165,
    -165,   408,  -165,  -165,   760,   633,  -165,    39,  -165,    75,
    -165,   873,  -165,   227,  -165,  -165,   -33,  -165,   169,   444,
    -165,    55,    58,    60,   172,   514,  -165,  -165,  -165,   820,
     105,  -165,   748,  -165,  -165,    65,  -165,   106,  -165,  -165,
    -165,  -165,  -165,   -10,   -10,   114,   114,    72,    72,    72,
      72,    35,    35,    91,   108,   136,   130,   195,   -36,  -165,
    -165,  -165,   180,   183,  -165,   191,    75,   856,   654,  -165,
    -165,   110,  -165,  -165,  -165,   444,   444,   444,   748,   666,
    -165,  -165,   748,  -165,   748,  -165,  -165,  -165,  -165,   184,
    -165,   192,  -165,  -165,   205,  -165,  -165,    66,   444,    73,
    -165,  -165,  -165,  -165,   444,   162,  -165,   444,  -165,  -165,
    -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,    97,    86,    87,    89,    90,    91,    92,    95,
      96,    93,    94,    88,     0,   109,   172,     0,    78,    80,
       0,   101,     0,   170,     0,   168,   171,     0,   110,    76,
       0,    82,    84,    79,    81,     0,   174,     0,     0,   100,
     169,     1,   103,     0,    77,     0,   173,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
     155,   147,     6,    16,    28,     0,    30,    34,    37,    40,
      45,    48,    50,    52,    54,    56,    58,    60,    73,     0,
     151,     0,   153,   138,   139,     0,     0,   140,   141,   142,
     143,   117,   108,   116,     0,   111,   112,     0,     2,   105,
      28,    75,     0,    83,    84,     0,   133,    85,     0,     0,
      20,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,   164,   165,   166,     0,     0,    99,   119,     0,     0,
      12,    13,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    62,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   149,
     152,     0,   148,   154,     0,     0,   114,   121,   115,   122,
     106,     0,   107,     0,   104,   136,     0,   144,     0,     0,
     146,     0,     0,     0,     0,     0,   167,     5,    98,     0,
     121,   120,     0,    11,     8,     0,    14,     0,    10,    61,
      31,    32,    33,    35,    36,    38,    39,    43,    44,    41,
      42,    46,    47,    49,    51,    53,    55,    57,     0,    74,
     150,   129,     0,     0,   125,     0,   123,     0,     0,   113,
     118,     0,   134,    21,   145,     0,     0,     0,     0,     0,
      29,     9,     0,     7,     0,   130,   124,   126,   131,     0,
     127,     0,   135,   137,   157,   159,   160,     0,     0,     0,
      15,    59,   132,   128,     0,     0,   162,     0,   158,   161,
     163
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,  -165,  -165,   -16,  -165,   -51,    41,    42,    -3,
      40,    63,    86,    74,    89,    84,  -165,   -25,   -44,  -165,
     -42,   -48,   -17,     8,  -165,   221,  -165,   -46,   138,   -11,
     -13,    -8,   -35,  -165,    87,  -165,   156,   -92,  -164,  -111,
    -165,   -58,  -165,    29,  -165,   185,  -118,  -165,  -165,  -165,
    -165,  -165,   254,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    72,    73,   215,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   156,
      89,   112,    16,   103,    30,    31,    18,    19,   137,    20,
      21,    22,   242,   105,   106,   107,   138,   243,   189,   117,
     196,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      23,    24,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     129,   116,   104,    27,   195,   124,    32,    28,    17,    39,
       1,   188,   205,   111,     1,   192,     1,   136,    90,   193,
     134,   135,   110,   246,   157,    43,    33,    34,   111,   175,
     177,    17,   114,   251,   120,   122,   123,   110,   183,     1,
     177,    44,     1,    91,   264,   211,   246,   165,   166,    36,
      45,   252,    35,    15,   177,   209,   178,   185,   158,   110,
     197,    46,    15,   159,   160,   207,    42,   200,    14,   177,
     206,   116,    14,   136,   184,    15,   185,   135,   180,   135,
     114,    15,   163,   164,   201,   202,   203,   259,    35,    29,
     136,   176,   186,    41,    37,   187,    38,    14,   216,   118,
     184,   217,   185,    91,    15,   169,   170,   220,   221,   222,
     167,   168,   219,   108,    48,    49,    50,   255,    51,    52,
     256,   177,   257,   183,   177,   125,   177,   261,   285,   210,
     126,   262,   177,   239,   238,   287,   247,   245,   248,   177,
     273,   254,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   260,   227,   228,   229,   230,   209,   131,   185,   110,
     263,    63,   177,    27,    39,   171,   187,    64,    65,    66,
      67,    68,    69,   161,   162,   108,    48,    49,    50,   127,
      51,    52,   128,   115,   272,   130,   110,   274,   275,   276,
     271,   210,   223,   224,   132,   225,   226,   116,   173,   231,
     232,   174,   269,   172,   190,   191,   277,   279,   280,   194,
     286,    45,   199,   111,   204,   212,   288,   213,   218,   290,
     250,   253,   110,   258,   233,    47,    48,    49,    50,   281,
      51,    52,   265,    63,   289,   266,   282,   235,   110,    64,
      65,    66,    67,    68,    69,   267,   283,   284,   234,   237,
       2,     3,     4,   236,   113,   115,     5,     6,     7,     8,
       9,    10,    11,    12,   208,   198,    13,    40,   249,     0,
     181,    53,    54,    55,     0,    56,    57,    58,    59,     0,
      60,    61,    62,    63,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    47,    48,    49,    50,     0,
      51,    52,     0,     0,    70,    35,    71,     0,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     0,     0,     0,
       0,    53,    54,    55,     0,    56,    57,    58,    59,     0,
      60,    61,    62,    63,     0,   101,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    47,    48,    49,    50,     0,
      51,    52,   155,     0,    70,    35,   179,     0,     0,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     0,     0,     0,
       0,    47,    48,    49,    50,     0,    51,    52,     0,     0,
       0,    53,    54,    55,   102,    56,    57,    58,    59,     0,
      60,    61,    62,    63,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69,     0,     0,    47,    48,    49,
      50,     0,    51,    52,    70,    35,   182,    53,    54,    55,
       0,    56,    57,    58,    59,     0,    60,    61,    62,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,   108,    48,    49,    50,     0,    51,    52,     0,     0,
      70,    35,   240,    53,    54,    55,     0,    56,    57,    58,
      59,     0,    60,    61,    62,    63,     0,   139,   140,   141,
       0,    64,    65,    66,    67,    68,    69,   108,    48,    49,
      50,     0,    51,    52,     2,     0,    70,    35,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    63,
      13,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,   108,    48,    49,    50,     0,    51,    52,     0,     0,
     133,   142,     0,   143,     0,   144,   108,    48,    49,    50,
       0,    51,    52,     0,     0,    63,     0,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    69,   108,    48,    49,
      50,     2,    51,    52,     0,     0,    70,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,     0,    63,
       0,     0,   109,     0,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    63,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,   108,    48,    49,    50,
       0,    51,    52,     0,     0,    63,   214,     0,     0,     0,
       0,    64,    65,    66,    67,    68,    69,   108,    48,    49,
      50,     0,    51,    52,     0,     0,     0,     0,     0,   108,
      48,    49,    50,     0,    51,    52,     0,     0,     0,     0,
       0,   108,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     0,    63,     0,     0,   244,     0,     0,
      64,    65,    66,    67,    68,    69,   108,    48,    49,    50,
       0,    51,    52,     0,     0,    63,     0,     0,   270,     0,
       0,    64,    65,    66,    67,    68,    69,    63,   278,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,   119,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,   108,    48,    49,    50,     0,    51,    52,     0,     0,
       0,     0,     0,     1,   121,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    13,     1,     0,     0,     0,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,   184,   241,   185,     0,     0,     0,     0,    15,     0,
       2,     3,     4,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,    13,     0,     2,     3,
       4,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    14,    13,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,   241,   185,     2,     3,     4,     0,    15,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      13,     2,     3,     4,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,   268
};

static const yytype_int16 yycheck[] =
{
      58,    45,    37,    14,   115,    53,    17,    15,     0,    22,
       3,   103,   130,    38,     3,    62,     3,    63,    35,    66,
      62,    63,    38,   187,    75,    66,    18,    19,    53,    17,
      66,    23,    43,    66,    50,    51,    52,    53,    96,     3,
      66,    82,     3,    35,    80,   137,   210,    12,    13,    20,
      81,    84,    83,    68,    66,    61,    82,    63,    68,    75,
     118,    32,    68,    73,    74,    62,    62,   125,    61,    66,
      82,   115,    61,   119,    61,    68,    63,   119,    95,   121,
      91,    68,    10,    11,   126,   127,   128,   205,    83,    82,
     136,    79,   103,     0,    61,   103,    63,    61,   142,    80,
      61,   143,    63,    95,    68,    14,    15,   158,   159,   160,
      75,    76,   156,     3,     4,     5,     6,    62,     8,     9,
      62,    66,    62,   181,    66,    80,    66,    62,    62,   137,
      61,    66,    66,   177,   176,    62,    61,   185,    63,    66,
     251,   199,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     185,   212,   165,   166,   167,   168,    61,    82,    63,   185,
      64,    61,    66,   184,   187,    67,   184,    67,    68,    69,
      70,    71,    72,    69,    70,     3,     4,     5,     6,    61,
       8,     9,    61,    83,    84,    61,   212,   255,   256,   257,
     248,   209,   161,   162,    82,   163,   164,   251,    78,   169,
     170,    16,   247,    77,    62,    66,   258,   259,   262,    64,
     278,    81,    80,   248,    54,    62,   284,     3,     3,   287,
       3,    62,   248,    61,   171,     3,     4,     5,     6,   264,
       8,     9,    62,    61,    82,    62,    62,   173,   264,    67,
      68,    69,    70,    71,    72,    64,    64,    52,   172,   175,
      28,    29,    30,   174,    43,    83,    34,    35,    36,    37,
      38,    39,    40,    41,   136,   119,    44,    23,   191,    -1,
      95,    49,    50,    51,    -1,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    82,    83,    84,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    53,    54,    55,    56,    -1,
      58,    59,    60,    61,    -1,     3,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    81,    -1,    82,    83,    84,    -1,    -1,    -1,
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
       6,    -1,     8,     9,    28,    -1,    82,    83,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    61,
      44,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
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
      -1,    -1,    -1,     3,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,     3,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    61,    44,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    28,    29,    30,    -1,    68,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    28,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    44,    61,    68,   107,   108,   111,   112,
     114,   115,   116,   135,   136,   137,   138,   114,   116,    82,
     109,   110,   114,   108,   108,    83,   128,    61,    63,   115,
     137,     0,    62,    66,    82,    81,   128,     3,     4,     5,
       6,     8,     9,    49,    50,    51,    53,    54,    55,    56,
      58,    59,    60,    61,    67,    68,    69,    70,    71,    72,
      82,    84,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     107,   108,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     3,    62,   108,   117,   118,   119,   120,     3,    64,
      89,   102,   106,   110,   114,    83,   103,   124,    80,    61,
      89,    61,    89,    89,   106,    80,    61,    61,    61,   126,
      61,    82,    82,    82,   105,   105,   112,   113,   121,     7,
       8,     9,    61,    63,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    81,   104,    91,    68,    73,
      74,    69,    70,    10,    11,    12,    13,    75,    76,    14,
      15,    67,    77,    78,    16,    17,    79,    66,    82,    84,
     107,   130,    84,   126,    61,    63,   114,   116,   122,   123,
      62,    66,    62,    66,    64,   124,   125,   126,   121,    80,
     126,   105,   105,   105,    54,   131,    82,    62,   113,    61,
     116,   122,    62,     3,    62,    88,   103,   105,     3,   103,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    94,
      94,    95,    95,    96,    97,    98,    99,   100,   105,   103,
      84,    62,   117,   122,    64,   106,   123,    61,    63,   119,
       3,    66,    84,    62,   126,    62,    62,    62,    61,   131,
      91,    62,    66,    64,    80,    62,    62,    64,    62,   117,
      64,   106,    84,   124,   126,   126,   126,   105,    62,   105,
     103,   102,    62,    64,    52,    62,   126,    62,   126,    82,
     126
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
     136,   137,   137,   138,   138
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     2,     2,     2,     3,     1,     2,
       1,     1,     1,     3,     2
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
#line 1741 "src/parser.tab.cpp"
    break;

  case 3:
#line 56 "src/parser.y"
                        {(yyval.expr) = new primary_expression(1,*(yyvsp[0].str)); std::cerr << "primary expression 2, which is const with value: " << *(yyvsp[0].str) <<std::endl;}
#line 1747 "src/parser.tab.cpp"
    break;

  case 4:
#line 57 "src/parser.y"
                         {(yyval.expr) = new primary_expression(2,*(yyvsp[0].str)); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
#line 1753 "src/parser.tab.cpp"
    break;

  case 5:
#line 58 "src/parser.y"
                             {(yyval.expr) = new primary_expression(3,(yyvsp[-1].expr)); std::cerr << "primary expression 4" << std::endl;}
#line 1759 "src/parser.tab.cpp"
    break;

  case 6:
#line 62 "src/parser.y"
                                                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "postfix expression 1" << std::endl;}
#line 1765 "src/parser.tab.cpp"
    break;

  case 7:
#line 63 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(0, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 2" << std::endl;}
#line 1771 "src/parser.tab.cpp"
    break;

  case 8:
#line 64 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(1, (yyvsp[-2].expr));std::cerr << "postfix expression 3" << std::endl;}
#line 1777 "src/parser.tab.cpp"
    break;

  case 9:
#line 65 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(2, (yyvsp[-3].expr), (yyvsp[-1].expr));std::cerr << "postfix expression 4" << std::endl;}
#line 1783 "src/parser.tab.cpp"
    break;

  case 10:
#line 66 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(3, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 5" << std::endl;}
#line 1789 "src/parser.tab.cpp"
    break;

  case 11:
#line 67 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), *(yyvsp[0].str));std::cerr << "postfix expression 6" << std::endl;}
#line 1795 "src/parser.tab.cpp"
    break;

  case 12:
#line 68 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(5, (yyvsp[-1].expr));std::cerr << "postfix expression 7" << std::endl;}
#line 1801 "src/parser.tab.cpp"
    break;

  case 13:
#line 69 "src/parser.y"
                                                               {(yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr));std::cerr << "postfix expression 8" << std::endl;}
#line 1807 "src/parser.tab.cpp"
    break;

  case 14:
#line 73 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "argument expression 1" << std::endl;}
#line 1813 "src/parser.tab.cpp"
    break;

  case 15:
#line 74 "src/parser.y"
                                                                 {(yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "argument expression 2" << std::endl;}
#line 1819 "src/parser.tab.cpp"
    break;

  case 16:
#line 78 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "unary expression 1" << std::endl;}
#line 1825 "src/parser.tab.cpp"
    break;

  case 17:
#line 79 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(0, (yyvsp[0].expr)); std::cerr << "unary expression 2" << std::endl;}
#line 1831 "src/parser.tab.cpp"
    break;

  case 18:
#line 80 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); std::cerr << "unary expression 3" << std::endl;}
#line 1837 "src/parser.tab.cpp"
    break;

  case 19:
#line 81 "src/parser.y"
                                           {(yyval.expr) = new unary_expression((yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "unary expression 4" << std::endl;}
#line 1843 "src/parser.tab.cpp"
    break;

  case 20:
#line 82 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); std::cerr << "unary expression 5" << std::endl;}
#line 1849 "src/parser.tab.cpp"
    break;

  case 21:
#line 83 "src/parser.y"
                                           {(yyval.expr) = new unary_expression(3, (yyvsp[-1].expr)); std::cerr << "unary expression 6" << std::endl;}
#line 1855 "src/parser.tab.cpp"
    break;

  case 22:
#line 87 "src/parser.y"
                   {(yyval.number) = 4; std::cerr << "unary operator 1" << std::endl;}
#line 1861 "src/parser.tab.cpp"
    break;

  case 23:
#line 88 "src/parser.y"
                   {(yyval.number) = 5; std::cerr << "unary operator 2" << std::endl;}
#line 1867 "src/parser.tab.cpp"
    break;

  case 24:
#line 89 "src/parser.y"
                   {(yyval.number) = 6; std::cerr << "unary operator 3" << std::endl;}
#line 1873 "src/parser.tab.cpp"
    break;

  case 25:
#line 90 "src/parser.y"
                   {(yyval.number) = 7; std::cerr << "unary operator 4" << std::endl;}
#line 1879 "src/parser.tab.cpp"
    break;

  case 26:
#line 91 "src/parser.y"
                   {(yyval.number) = 8; std::cerr << "unary operator 5" << std::endl;}
#line 1885 "src/parser.tab.cpp"
    break;

  case 27:
#line 92 "src/parser.y"
                   {(yyval.number) = 9; std::cerr << "unary operator 6" << std::endl;}
#line 1891 "src/parser.tab.cpp"
    break;

  case 28:
#line 96 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "cast expression 1" << std::endl;}
#line 1897 "src/parser.tab.cpp"
    break;

  case 29:
#line 97 "src/parser.y"
                                                 {(yyval.expr) = new cast_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "cast expression 2" << std::endl;}
#line 1903 "src/parser.tab.cpp"
    break;

  case 30:
#line 101 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr); std::cerr << "mulitiplicative expression 1" << std::endl;}
#line 1909 "src/parser.tab.cpp"
    break;

  case 31:
#line 102 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(1,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 2" << std::endl;}
#line 1915 "src/parser.tab.cpp"
    break;

  case 32:
#line 103 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(2,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 3" << std::endl;}
#line 1921 "src/parser.tab.cpp"
    break;

  case 33:
#line 104 "src/parser.y"
                                                         {(yyval.expr) = new multiplicative_expression(3,(yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "mulitiplicative expression 4" << std::endl;}
#line 1927 "src/parser.tab.cpp"
    break;

  case 34:
#line 108 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr); std::cerr << "additive_expression 1" << std::endl;}
#line 1933 "src/parser.tab.cpp"
    break;

  case 35:
#line 109 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 2" << std::endl;}
#line 1939 "src/parser.tab.cpp"
    break;

  case 36:
#line 110 "src/parser.y"
                                                             {(yyval.expr) = new additive_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "additive_expression 3" << std::endl;}
#line 1945 "src/parser.tab.cpp"
    break;

  case 37:
#line 114 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "shift_expression 1" << std::endl;}
#line 1951 "src/parser.tab.cpp"
    break;

  case 38:
#line 115 "src/parser.y"
                                                       {(yyval.expr) = new shift_expression(1,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 2" << std::endl;}
#line 1957 "src/parser.tab.cpp"
    break;

  case 39:
#line 116 "src/parser.y"
                                                        {(yyval.expr) = new shift_expression(2,(yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "shift_expression 3" << std::endl;}
#line 1963 "src/parser.tab.cpp"
    break;

  case 40:
#line 120 "src/parser.y"
                                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "relational_expression 1" << std::endl;}
#line 1969 "src/parser.tab.cpp"
    break;

  case 41:
#line 121 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 2" << std::endl;}
#line 1975 "src/parser.tab.cpp"
    break;

  case 42:
#line 122 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 3" << std::endl;}
#line 1981 "src/parser.tab.cpp"
    break;

  case 43:
#line 123 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(2, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 4" << std::endl;}
#line 1987 "src/parser.tab.cpp"
    break;

  case 44:
#line 124 "src/parser.y"
                                                           {(yyval.expr) = new relational_expression(3, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "relational_expression 5" << std::endl;}
#line 1993 "src/parser.tab.cpp"
    break;

  case 45:
#line 128 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "equality_expression 1" << std::endl;}
#line 1999 "src/parser.tab.cpp"
    break;

  case 46:
#line 129 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(4, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 2" << std::endl;}
#line 2005 "src/parser.tab.cpp"
    break;

  case 47:
#line 130 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(5, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "equality_expression 3" << std::endl;}
#line 2011 "src/parser.tab.cpp"
    break;

  case 48:
#line 134 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "and_expression 1" << std::endl;}
#line 2017 "src/parser.tab.cpp"
    break;

  case 49:
#line 135 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(6, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "and_expression 2" << std::endl;}
#line 2023 "src/parser.tab.cpp"
    break;

  case 50:
#line 139 "src/parser.y"
                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "exclusive_or_expression 1" << std::endl;}
#line 2029 "src/parser.tab.cpp"
    break;

  case 51:
#line 140 "src/parser.y"
                                                             {(yyval.expr) = new relational_expression(7, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "exclusive_or_expression 2" << std::endl;}
#line 2035 "src/parser.tab.cpp"
    break;

  case 52:
#line 144 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "inclusive_or_expression 1" << std::endl;}
#line 2041 "src/parser.tab.cpp"
    break;

  case 53:
#line 145 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(8, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "inclusive_or_expression 2" << std::endl;}
#line 2047 "src/parser.tab.cpp"
    break;

  case 54:
#line 149 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_and_expression 1" << std::endl;}
#line 2053 "src/parser.tab.cpp"
    break;

  case 55:
#line 150 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(9, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_and_expression 2" << std::endl;}
#line 2059 "src/parser.tab.cpp"
    break;

  case 56:
#line 154 "src/parser.y"
                                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "logical_or_expression 1" << std::endl;}
#line 2065 "src/parser.tab.cpp"
    break;

  case 57:
#line 155 "src/parser.y"
                                                                 {(yyval.expr) = new relational_expression(10, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "logical_or_expression 2" << std::endl;}
#line 2071 "src/parser.tab.cpp"
    break;

  case 58:
#line 159 "src/parser.y"
                                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "conditional expression 1" << std::endl;}
#line 2077 "src/parser.tab.cpp"
    break;

  case 59:
#line 160 "src/parser.y"
                                                                             {(yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "conditional expression 2" << std::endl;}
#line 2083 "src/parser.tab.cpp"
    break;

  case 60:
#line 164 "src/parser.y"
                                                                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "assignment expression 1" << std::endl;}
#line 2089 "src/parser.tab.cpp"
    break;

  case 61:
#line 165 "src/parser.y"
                                                                             {(yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].number), (yyvsp[0].expr)); std::cerr << "assignment expression 2" << std::endl;}
#line 2095 "src/parser.tab.cpp"
    break;

  case 62:
#line 169 "src/parser.y"
                             {(yyval.number) = 0; std::cerr << "assignment operator 1" << std::endl;}
#line 2101 "src/parser.tab.cpp"
    break;

  case 63:
#line 170 "src/parser.y"
                             {(yyval.number) = 1; std::cerr << "assignment operator 2" << std::endl;}
#line 2107 "src/parser.tab.cpp"
    break;

  case 64:
#line 171 "src/parser.y"
                             {(yyval.number) = 2; std::cerr << "assignment operator 3" << std::endl;}
#line 2113 "src/parser.tab.cpp"
    break;

  case 65:
#line 172 "src/parser.y"
                             {(yyval.number) = 3; std::cerr << "assignment operator 4" << std::endl;}
#line 2119 "src/parser.tab.cpp"
    break;

  case 66:
#line 173 "src/parser.y"
                             {(yyval.number) = 4; std::cerr << "assignment operator 5" << std::endl;}
#line 2125 "src/parser.tab.cpp"
    break;

  case 67:
#line 174 "src/parser.y"
                             {(yyval.number) = 5; std::cerr << "assignment operator 6" << std::endl;}
#line 2131 "src/parser.tab.cpp"
    break;

  case 68:
#line 175 "src/parser.y"
                             {(yyval.number) = 6; std::cerr << "assignment operator 7" << std::endl;}
#line 2137 "src/parser.tab.cpp"
    break;

  case 69:
#line 176 "src/parser.y"
                             {(yyval.number) = 7; std::cerr << "assignment operator 8" << std::endl;}
#line 2143 "src/parser.tab.cpp"
    break;

  case 70:
#line 177 "src/parser.y"
                             {(yyval.number) = 8; std::cerr << "assignment operator 9" << std::endl;}
#line 2149 "src/parser.tab.cpp"
    break;

  case 71:
#line 178 "src/parser.y"
                             {(yyval.number) = 9; std::cerr << "assignment operator 10" << std::endl;}
#line 2155 "src/parser.tab.cpp"
    break;

  case 72:
#line 179 "src/parser.y"
                             {(yyval.number) = 10; std::cerr << "assignment operator 11" << std::endl;}
#line 2161 "src/parser.tab.cpp"
    break;

  case 73:
#line 183 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "expression 1" << std::endl;}
#line 2167 "src/parser.tab.cpp"
    break;

  case 74:
#line 184 "src/parser.y"
                                                 {(yyval.expr) = new base_expression((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "expression 2" << std::endl;}
#line 2173 "src/parser.tab.cpp"
    break;

  case 75:
#line 188 "src/parser.y"
                                   {(yyval.expr) = (yyvsp[0].expr); std::cerr << "constant_expression 0" << std::endl;}
#line 2179 "src/parser.tab.cpp"
    break;

  case 76:
#line 192 "src/parser.y"
                                      {(yyval.expr) = new declaration((yyvsp[-1].expr)); std::cerr << "declaration 0 " << std::endl;}
#line 2185 "src/parser.tab.cpp"
    break;

  case 77:
#line 193 "src/parser.y"
                                                           {(yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr));std::cerr << "declaration 1 " << std::endl;}
#line 2191 "src/parser.tab.cpp"
    break;

  case 78:
#line 197 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 0" << std::endl;}
#line 2197 "src/parser.tab.cpp"
    break;

  case 79:
#line 198 "src/parser.y"
                                                           {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 1" << std::endl;}
#line 2203 "src/parser.tab.cpp"
    break;

  case 80:
#line 199 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);std::cerr << "declaration_specifiers 2" << std::endl;}
#line 2209 "src/parser.tab.cpp"
    break;

  case 81:
#line 200 "src/parser.y"
                                                   {(yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr));std::cerr << "declaration_specifiers 3" << std::endl;}
#line 2215 "src/parser.tab.cpp"
    break;

  case 82:
#line 206 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr); std::cerr << "init_declarator_list 0 " << std::endl;}
#line 2221 "src/parser.tab.cpp"
    break;

  case 83:
#line 207 "src/parser.y"
                                                     {(yyval.expr) = new init_declarator_list((yyvsp[-2].expr),(yyvsp[0].expr)); std::cerr << "init_declarator_list 1" << std::endl;}
#line 2227 "src/parser.tab.cpp"
    break;

  case 84:
#line 211 "src/parser.y"
                       {(yyval.expr) = new init_declarator((yyvsp[0].expr)); std::cerr << "init_declarator 0 " << std::endl;}
#line 2233 "src/parser.tab.cpp"
    break;

  case 85:
#line 212 "src/parser.y"
                                       {(yyval.expr) = new init_declarator((yyvsp[-2].expr),(yyvsp[0].expr));  std::cerr << "init_declarator 1" << std::endl;}
#line 2239 "src/parser.tab.cpp"
    break;

  case 86:
#line 216 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
#line 2245 "src/parser.tab.cpp"
    break;

  case 87:
#line 217 "src/parser.y"
                   {(yyval.expr) = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}
#line 2251 "src/parser.tab.cpp"
    break;

  case 88:
#line 224 "src/parser.y"
                 {(yyval.expr) = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
#line 2257 "src/parser.tab.cpp"
    break;

  case 89:
#line 225 "src/parser.y"
                 {(yyval.expr) = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
#line 2263 "src/parser.tab.cpp"
    break;

  case 90:
#line 226 "src/parser.y"
                  {(yyval.expr) = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
#line 2269 "src/parser.tab.cpp"
    break;

  case 91:
#line 227 "src/parser.y"
                {(yyval.expr) = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
#line 2275 "src/parser.tab.cpp"
    break;

  case 92:
#line 228 "src/parser.y"
                 {(yyval.expr) = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
#line 2281 "src/parser.tab.cpp"
    break;

  case 93:
#line 229 "src/parser.y"
                  {(yyval.expr) = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
#line 2287 "src/parser.tab.cpp"
    break;

  case 94:
#line 230 "src/parser.y"
                   {(yyval.expr) = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
#line 2293 "src/parser.tab.cpp"
    break;

  case 95:
#line 231 "src/parser.y"
                   {(yyval.expr) = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
#line 2299 "src/parser.tab.cpp"
    break;

  case 96:
#line 232 "src/parser.y"
                     {(yyval.expr) = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
#line 2305 "src/parser.tab.cpp"
    break;

  case 97:
#line 235 "src/parser.y"
                      {(yyval.expr) = new type_specifier(9); std::cerr << "type_name" << std::endl;}
#line 2311 "src/parser.tab.cpp"
    break;

  case 98:
#line 260 "src/parser.y"
                                                  {(yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "specifier_qualifier_list 0" << std::endl;}
#line 2317 "src/parser.tab.cpp"
    break;

  case 99:
#line 261 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "specifier_qualifier_list 1" << std::endl;}
#line 2323 "src/parser.tab.cpp"
    break;

  case 100:
#line 301 "src/parser.y"
                                     {(yyval.expr) = new declarator((yyvsp[-1].expr), (yyvsp[0].expr));  std::cerr << "declarator 0" << std::endl;}
#line 2329 "src/parser.tab.cpp"
    break;

  case 101:
#line 302 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "declarator 1" << std::endl;}
#line 2335 "src/parser.tab.cpp"
    break;

  case 102:
#line 306 "src/parser.y"
                       {(yyval.expr) = new direct_declarator(0,*(yyvsp[0].str));std::cerr << "direct_declarator 0,IDENTIFIER : " << *(yyvsp[0].str) <<std::endl; }
#line 2341 "src/parser.tab.cpp"
    break;

  case 103:
#line 307 "src/parser.y"
                              {(yyval.expr) = new direct_declarator(1,(yyvsp[-1].expr)); std::cerr << "direct_declarator 1" << std::endl;}
#line 2347 "src/parser.tab.cpp"
    break;

  case 104:
#line 308 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(2,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 2" << std::endl;}
#line 2353 "src/parser.tab.cpp"
    break;

  case 105:
#line 309 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(3,(yyvsp[-2].expr));  std::cerr << "direct_declarator 3" << std::endl;}
#line 2359 "src/parser.tab.cpp"
    break;

  case 106:
#line 310 "src/parser.y"
                                                         {(yyval.expr) = new direct_declarator(4,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 4" << std::endl;}
#line 2365 "src/parser.tab.cpp"
    break;

  case 107:
#line 311 "src/parser.y"
                                                     {(yyval.expr) = new direct_declarator(5,(yyvsp[-3].expr),(yyvsp[-1].expr));  std::cerr << "direct_declarator 5" << std::endl;}
#line 2371 "src/parser.tab.cpp"
    break;

  case 108:
#line 312 "src/parser.y"
                                      {(yyval.expr) = new direct_declarator(6,(yyvsp[-2].expr));  std::cerr << "direct_declarator 6" << std::endl;}
#line 2377 "src/parser.tab.cpp"
    break;

  case 109:
#line 315 "src/parser.y"
              {(yyval.expr) = new pointer(0); std::cerr << "pointer 0" << std::endl;}
#line 2383 "src/parser.tab.cpp"
    break;

  case 110:
#line 317 "src/parser.y"
                        {(yyval.expr) = new pointer(1, (yyvsp[0].expr)); std::cerr << "pointer 1" << std::endl;}
#line 2389 "src/parser.tab.cpp"
    break;

  case 111:
#line 328 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_type_list 0" << std::endl;}
#line 2395 "src/parser.tab.cpp"
    break;

  case 112:
#line 333 "src/parser.y"
                                                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "parameter_list 0" << std::endl; }
#line 2401 "src/parser.tab.cpp"
    break;

  case 113:
#line 334 "src/parser.y"
                                                       {(yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "parameter_list 1" << std::endl;}
#line 2407 "src/parser.tab.cpp"
    break;

  case 114:
#line 338 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 0" << std::endl; }
#line 2413 "src/parser.tab.cpp"
    break;

  case 115:
#line 339 "src/parser.y"
                                                        {(yyval.expr) = new parameter_declaration(1, (yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "parameter_declaration 1" << std::endl; }
#line 2419 "src/parser.tab.cpp"
    break;

  case 116:
#line 340 "src/parser.y"
                                                   {(yyval.expr) = new parameter_declaration(2, (yyvsp[0].expr)); std::cerr << "parameter_declaration 2" << std::endl;  }
#line 2425 "src/parser.tab.cpp"
    break;

  case 117:
#line 344 "src/parser.y"
                                                         {(yyval.expr) = new identifier_list(*(yyvsp[0].str));std::cerr << "identifier_list 0; an IDENTIFIER: " << std::endl;}
#line 2431 "src/parser.tab.cpp"
    break;

  case 118:
#line 345 "src/parser.y"
                                                         {(yyval.expr) = new identifier_list((yyvsp[-2].expr), *(yyvsp[0].str)); std::cerr << "identifier_list 1; an IDENTIFIER: " <<   std::endl;}
#line 2437 "src/parser.tab.cpp"
    break;

  case 119:
#line 349 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);std::cerr << "type name 1" << std::endl; }
#line 2443 "src/parser.tab.cpp"
    break;

  case 120:
#line 350 "src/parser.y"
                                                         {(yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr));std::cerr << "type name 2" << std::endl;}
#line 2449 "src/parser.tab.cpp"
    break;

  case 121:
#line 354 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr);  std::cerr << "abstract_declarator 0" << std::endl;}
#line 2455 "src/parser.tab.cpp"
    break;

  case 122:
#line 355 "src/parser.y"
                                                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "abstract_declarator 1" << std::endl;}
#line 2461 "src/parser.tab.cpp"
    break;

  case 123:
#line 356 "src/parser.y"
                                                         {(yyval.expr) = new abstract_declarator((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "abstract_declarator 2" << std::endl;}
#line 2467 "src/parser.tab.cpp"
    break;

  case 124:
#line 361 "src/parser.y"
                                                                     {(yyval.expr) = (yyvsp[-1].expr);  std::cerr << "direct_abstract_declarator 0" << std::endl;}
#line 2473 "src/parser.tab.cpp"
    break;

  case 125:
#line 362 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(0);  std::cerr << "direct_abstract_declarator 1" << std::endl;}
#line 2479 "src/parser.tab.cpp"
    break;

  case 126:
#line 363 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(1, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 2" << std::endl;}
#line 2485 "src/parser.tab.cpp"
    break;

  case 127:
#line 364 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 3" << std::endl;}
#line 2491 "src/parser.tab.cpp"
    break;

  case 128:
#line 365 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 4" << std::endl;}
#line 2497 "src/parser.tab.cpp"
    break;

  case 129:
#line 366 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(4);  std::cerr << "direct_abstract_declarator 5" << std::endl;}
#line 2503 "src/parser.tab.cpp"
    break;

  case 130:
#line 367 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(5, (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 6" << std::endl;}
#line 2509 "src/parser.tab.cpp"
    break;

  case 131:
#line 368 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(6, (yyvsp[-2].expr));  std::cerr << "direct_abstract_declarator 7" << std::endl;}
#line 2515 "src/parser.tab.cpp"
    break;

  case 132:
#line 369 "src/parser.y"
                                                                     {(yyval.expr) = new direct_abstract_declarator(7, (yyvsp[-3].expr), (yyvsp[-1].expr));  std::cerr << "direct_abstract_declarator 8" << std::endl;}
#line 2521 "src/parser.tab.cpp"
    break;

  case 133:
#line 373 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr); std::cerr << "initializer 0" << std::endl;}
#line 2527 "src/parser.tab.cpp"
    break;

  case 134:
#line 374 "src/parser.y"
                                                 {(yyval.expr) = new initializer(0, (yyvsp[-1].expr)); std::cerr << "initializer 1" << std::endl;}
#line 2533 "src/parser.tab.cpp"
    break;

  case 135:
#line 375 "src/parser.y"
                                                 {(yyval.expr) = new initializer(1, (yyvsp[-2].expr)); std::cerr << "initializer 2" << std::endl;}
#line 2539 "src/parser.tab.cpp"
    break;

  case 136:
#line 379 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(0, (yyvsp[0].expr)); std::cerr << "initializer_list 0" << std::endl;}
#line 2545 "src/parser.tab.cpp"
    break;

  case 137:
#line 380 "src/parser.y"
                                                 {(yyval.expr) = new initializer_list(1, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "initializer_list 1" << std::endl;}
#line 2551 "src/parser.tab.cpp"
    break;

  case 138:
#line 384 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 0" << std::endl;}
#line 2557 "src/parser.tab.cpp"
    break;

  case 139:
#line 385 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 1" << std::endl; }
#line 2563 "src/parser.tab.cpp"
    break;

  case 140:
#line 386 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 2" << std::endl;}
#line 2569 "src/parser.tab.cpp"
    break;

  case 141:
#line 387 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 3" << std::endl;}
#line 2575 "src/parser.tab.cpp"
    break;

  case 142:
#line 388 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 4" << std::endl;}
#line 2581 "src/parser.tab.cpp"
    break;

  case 143:
#line 389 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement 5" << std::endl;}
#line 2587 "src/parser.tab.cpp"
    break;

  case 144:
#line 393 "src/parser.y"
                                     {(yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); std::cerr << "labeled_statement 0" << std::endl;}
#line 2593 "src/parser.tab.cpp"
    break;

  case 145:
#line 394 "src/parser.y"
                                                   {(yyval.expr) = new labeled_statement(1, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "labeled_statement 1" << std::endl;}
#line 2599 "src/parser.tab.cpp"
    break;

  case 146:
#line 395 "src/parser.y"
                                   {(yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); std::cerr << "labeled_statement 2" << std::endl;}
#line 2605 "src/parser.tab.cpp"
    break;

  case 147:
#line 399 "src/parser.y"
                     {(yyval.expr) = new compound_statement(0); std::cerr << "compound_statement 0" << std::endl;}
#line 2611 "src/parser.tab.cpp"
    break;

  case 148:
#line 400 "src/parser.y"
                                   {(yyval.expr) = new compound_statement(1, (yyvsp[-1].expr)); std::cerr << "compound_statement 1" << std::endl;}
#line 2617 "src/parser.tab.cpp"
    break;

  case 149:
#line 401 "src/parser.y"
                                     {(yyval.expr) = new compound_statement(2, (yyvsp[-1].expr)); std::cerr << "compound_statement 2" << std::endl;}
#line 2623 "src/parser.tab.cpp"
    break;

  case 150:
#line 402 "src/parser.y"
                                                                                                                          {(yyval.expr) = new compound_statement(3, (yyvsp[-2].expr), (yyvsp[-1].expr)); std::cerr << "compound_statement 3" << std::endl;}
#line 2629 "src/parser.tab.cpp"
    break;

  case 151:
#line 406 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr); std::cerr << "declaration list 1" << std::endl;}
#line 2635 "src/parser.tab.cpp"
    break;

  case 152:
#line 407 "src/parser.y"
                                           {(yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); std::cerr << "declaration list 2" << std::endl;}
#line 2641 "src/parser.tab.cpp"
    break;

  case 153:
#line 411 "src/parser.y"
                       {(yyval.expr) = (yyvsp[0].expr); std::cerr << "statement_list 0" << std::endl;}
#line 2647 "src/parser.tab.cpp"
    break;

  case 154:
#line 412 "src/parser.y"
                                     {(yyval.expr) = new statement_list((yyvsp[-1].expr),(yyvsp[0].expr)); std::cerr << "statement_list 1" << std::endl;}
#line 2653 "src/parser.tab.cpp"
    break;

  case 155:
#line 416 "src/parser.y"
                 {(yyval.expr) = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
#line 2659 "src/parser.tab.cpp"
    break;

  case 156:
#line 417 "src/parser.y"
                           {(yyval.expr) = new expression_statement((yyvsp[-1].expr));std::cerr << "expression_statement 1" << std::endl;}
#line 2665 "src/parser.tab.cpp"
    break;

  case 157:
#line 421 "src/parser.y"
                                             {(yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 0" << std::endl;}
#line 2671 "src/parser.tab.cpp"
    break;

  case 158:
#line 422 "src/parser.y"
                                                           {(yyval.expr) = new selection_statement(1, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 1" << std::endl;}
#line 2677 "src/parser.tab.cpp"
    break;

  case 159:
#line 423 "src/parser.y"
                                                 {(yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "selection_statement 2" << std::endl;}
#line 2683 "src/parser.tab.cpp"
    break;

  case 160:
#line 427 "src/parser.y"
                                               {(yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); std::cerr << "iteration_statement 0 " << std::endl;}
#line 2689 "src/parser.tab.cpp"
    break;

  case 161:
#line 428 "src/parser.y"
                                                       {(yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr));std::cerr << "iteration_statement 1 " << std::endl;}
#line 2695 "src/parser.tab.cpp"
    break;

  case 162:
#line 429 "src/parser.y"
                                                                             {(yyval.expr) = new iteration_statement(2, (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 2 " << std::endl;}
#line 2701 "src/parser.tab.cpp"
    break;

  case 163:
#line 430 "src/parser.y"
                                                                                       {(yyval.expr) = new iteration_statement(0, (yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr));std::cerr << "iteration_statement 3 " << std::endl;}
#line 2707 "src/parser.tab.cpp"
    break;

  case 164:
#line 435 "src/parser.y"
                         {(yyval.expr) = new jump_statement(1, "CONTINUE");std::cerr << "jump_statement 1 " << std::endl;}
#line 2713 "src/parser.tab.cpp"
    break;

  case 165:
#line 436 "src/parser.y"
                       {(yyval.expr) = new jump_statement(2, "BREAK");std::cerr << "jump_statement 2 " << std::endl;}
#line 2719 "src/parser.tab.cpp"
    break;

  case 166:
#line 437 "src/parser.y"
                       {(yyval.expr) = new jump_statement(3, "RETURN");std::cerr << "jump_statement 3 " << std::endl;}
#line 2725 "src/parser.tab.cpp"
    break;

  case 167:
#line 438 "src/parser.y"
                                   {(yyval.expr) = new jump_statement(4, (yyvsp[-1].expr));std::cerr << "jump_statement 4 " << std::endl;}
#line 2731 "src/parser.tab.cpp"
    break;

  case 168:
#line 443 "src/parser.y"
                                                   {(yyval.expr) = (yyvsp[0].expr);std::cerr << " translation_unit 1" << std::endl;}
#line 2737 "src/parser.tab.cpp"
    break;

  case 169:
#line 444 "src/parser.y"
                                                   {std::cerr << "translation_unit 2" << std::endl;(yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2743 "src/parser.tab.cpp"
    break;

  case 170:
#line 448 "src/parser.y"
                        {g_root = (yyvsp[0].expr);}
#line 2749 "src/parser.tab.cpp"
    break;

  case 171:
#line 451 "src/parser.y"
                                     {(yyval.expr) = new external_declaration(0,(yyvsp[0].expr));std::cerr << "external declaration 1" << std::endl;}
#line 2755 "src/parser.tab.cpp"
    break;

  case 172:
#line 452 "src/parser.y"
                                     {(yyval.expr) =  new external_declaration(1,(yyvsp[0].expr));std::cerr << "external declaration 2" << std::endl;}
#line 2761 "src/parser.tab.cpp"
    break;

  case 173:
#line 457 "src/parser.y"
                                                                                 {std::cerr << "function definition 1" << std::endl;(yyval.expr) = new function_definition((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2767 "src/parser.tab.cpp"
    break;

  case 174:
#line 458 "src/parser.y"
                                                                           {std::cerr << "function definition 2" << std::endl;(yyval.expr) = new function_definition((yyvsp[-1].expr), (yyvsp[0].expr));}
#line 2773 "src/parser.tab.cpp"
    break;


#line 2777 "src/parser.tab.cpp"

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
#line 462 "src/parser.y"

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
