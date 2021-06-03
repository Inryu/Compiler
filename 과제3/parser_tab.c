
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TCONST	258
#define	TELSE	259
#define	TIF	260
#define	TINT	261
#define	TRETURN	262
#define	TVOID	263
#define	TWHILE	264
#define	TPOINT	265
#define	TILLSP	266
#define	TPLUS	267
#define	TMINUS	268
#define	TSTAR	269
#define	TSLASH	270
#define	TMOD	271
#define	TASSIGN	272
#define	TADDASSIGN	273
#define	TSUBASSIGN	274
#define	TMULASSIGN	275
#define	TDIVASSIGN	276
#define	TMODASSIGN	277
#define	TOR	278
#define	TEQUAL	279
#define	TNOTEQU	280
#define	TLESS	281
#define	TOVER	282
#define	TLESSE	283
#define	TINC	284
#define	TDEC	285
#define	TOSBRA	286
#define	TCSBRA	287
#define	TCOMMA	288
#define	TOMBRA	289
#define	TCMBRA	290
#define	TOLBRA	291
#define	TCLBRA	292
#define	TSEMI	293
#define	TNUMBER	294
#define	TFLOAT	295
#define	TLONG	296
#define	TNOT	297
#define	TAND	298
#define	TOVERE	299
#define	TILLIDENT	300
#define	TONECMT	301
#define	TMULCMT	302
#define	TIDENT	303
#define	LOWER_THAN_ELSE	304

#line 1 "parser.y"

/*
* parser.y.- yacc source for the MiniC(HW3)
*
* Programmer - team2
*
* date -  5/26/2021
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

 int type_int=0;
 int type_void=0;
 int type_float=0;
 int param_int=0;
 int param_float=0;


extern reporterror();
extern yylex();
extern yyerror(char *s);


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		195
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 304 ? yytranslate[x] : 95)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    53,    55,    59,    61,    62,    64,    68,    72,
    75,    80,    85,    87,    88,    90,    93,    97,   101,   103,
   107,   111,   113,   117,   121,   123,   128,   133,   135,   137,
   139,   141,   142,   144,   145,   147,   150,   153,   155,   157,
   159,   161,   163,   166,   169,   171,   172,   178,   186,   192,
   196,   198,   200,   204,   208,   212,   216,   220,   224,   228,
   232,   236,   240,   244,   248,   250,   254,   258,   260,   264,
   268,   270,   274,   278,   282,   286,   288,   292,   296,   300,
   304,   308,   312,   316,   320,   322,   326,   330,   334,   338,
   340,   344,   348,   352,   356,   360,   364,   366,   369,   372,
   375,   378,   380,   385,   390,   393,   396,   398,   399,   401,
   403,   407,   409,   411,   413
};

static const short yyrhs[] = {    51,
     0,    52,     0,    51,    52,     0,    53,     0,    68,     0,
    48,    38,     0,    48,     1,     0,    54,    65,     0,    54,
    38,     0,    54,     1,     0,    55,    60,    61,     0,    56,
     0,    57,     0,    56,    57,     0,    58,     0,    59,     0,
     3,     0,     6,     0,     8,     0,    40,     0,    48,     0,
    45,     0,    41,     0,    31,    62,    32,     0,    63,     0,
     0,    64,     0,    63,    33,    64,     0,    63,    64,     1,
     0,    55,    71,     0,    34,    66,    73,    35,     0,    34,
    66,    73,     1,     0,    67,     0,     0,    68,     0,    67,
    68,     0,    55,    69,    38,     0,    55,    69,     1,     0,
    70,     0,    69,    33,    70,     0,    69,    70,     1,     0,
    71,     0,    71,    17,    39,     0,    71,    17,    10,     0,
    48,     0,    48,    36,    72,    37,     0,    48,    36,    72,
     1,     0,    45,     0,    41,     0,    39,     0,    10,     0,
     0,    74,     0,     0,    75,     0,    74,    75,     0,    74,
    68,     0,    65,     0,    76,     0,    78,     0,    79,     0,
    80,     0,    77,    38,     0,    81,     1,     0,    81,     0,
     0,     5,    31,    81,    32,    75,     0,     5,    31,    81,
    32,    75,     4,    75,     0,     9,    31,    81,    32,    75,
     0,     7,    77,    38,     0,    82,     0,    83,     0,    89,
    17,    82,     0,    89,    18,    82,     0,    89,    19,    82,
     0,    89,    20,    82,     0,    89,    21,    82,     0,    89,
    22,    82,     0,    89,    17,     1,     0,    89,    18,     1,
     0,    89,    19,     1,     0,    89,    20,     1,     0,    89,
    21,     1,     0,    89,    22,     1,     0,    84,     0,    83,
    23,    84,     0,    83,    23,     1,     0,    85,     0,    84,
    43,    85,     0,    84,    43,     1,     0,    86,     0,    85,
    24,    86,     0,    85,    25,    86,     0,    85,    24,     1,
     0,    85,    25,     1,     0,    87,     0,    86,    27,    87,
     0,    86,    44,    87,     0,    86,    26,    87,     0,    86,
    28,    87,     0,    86,    27,     1,     0,    86,    26,     1,
     0,    86,    44,     1,     0,    86,    28,     1,     0,    88,
     0,    87,    12,    88,     0,    87,    12,     1,     0,    87,
    13,    88,     0,    87,    13,     1,     0,    89,     0,    88,
    14,    89,     0,    88,    15,    89,     0,    88,    16,    89,
     0,    88,    14,     1,     0,    88,    15,     1,     0,    88,
    16,     1,     0,    90,     0,    13,    89,     0,    42,    89,
     0,    29,    89,     0,    30,    89,     0,    94,     0,    90,
    36,    81,    37,     0,    90,    31,    91,    32,     0,    90,
    29,     0,    90,    30,     0,    92,     0,     0,    93,     0,
    82,     0,    93,    33,    82,     0,    48,     0,    39,     0,
    10,     0,    31,    81,    32,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    41,    43,    44,    47,    48,    49,    50,    55,    56,    57,
    66,    68,    70,    71,    73,    74,    76,    81,    82,    83,
    86,   111,   112,   116,   118,   119,   121,   122,   123,   133,
   149,   150,   156,   157,   159,   160,   162,   167,   176,   177,
   178,   183,   184,   185,   187,   203,   214,   218,   219,   222,
   223,   224,   226,   227,   229,   230,   231,   233,   234,   235,
   236,   237,   239,   240,   246,   247,   249,   250,   252,   254,
   256,   258,   259,   260,   261,   262,   263,   264,   265,   269,
   273,   277,   281,   285,   290,   291,   292,   297,   298,   299,
   304,   305,   306,   308,   312,   317,   318,   319,   320,   321,
   323,   328,   332,   336,   344,   345,   346,   350,   351,   355,
   356,   357,   358,   361,   366,   371,   377,   378,   379,   380,
   381,   384,   385,   386,   387,   388,   390,   391,   393,   395,
   396,   399,   405,   406,   407
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TPOINT","TILLSP","TPLUS","TMINUS",
"TSTAR","TSLASH","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN",
"TMODASSIGN","TOR","TEQUAL","TNOTEQU","TLESS","TOVER","TLESSE","TINC","TDEC",
"TOSBRA","TCSBRA","TCOMMA","TOMBRA","TCMBRA","TOLBRA","TCLBRA","TSEMI","TNUMBER",
"TFLOAT","TLONG","TNOT","TAND","TOVERE","TILLIDENT","TONECMT","TMULCMT","TIDENT",
"LOWER_THAN_ELSE","mini_c","translation_unit","external_dcl","function_def",
"function_header","dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier",
"type_specifier","function_name","formal_param","opt_formal_param","formal_param_list",
"param_dcl","compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
    54,    55,    56,    56,    57,    57,    58,    59,    59,    59,
    60,    60,    60,    61,    62,    62,    63,    63,    63,    64,
    65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
    69,    70,    70,    70,    71,    71,    71,    71,    71,    72,
    72,    72,    73,    73,    74,    74,    74,    75,    75,    75,
    75,    75,    76,    76,    77,    77,    78,    78,    79,    80,
    81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
    82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
    85,    85,    85,    85,    85,    86,    86,    86,    86,    86,
    86,    86,    86,    86,    87,    87,    87,    87,    87,    88,
    88,    88,    88,    88,    88,    88,    89,    89,    89,    89,
    89,    90,    90,    90,    90,    90,    91,    91,    92,    93,
    93,    94,    94,    94,    94
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     3,     1,     0,     1,     3,     3,     2,
     4,     4,     1,     0,     1,     2,     3,     3,     1,     3,
     3,     1,     3,     3,     1,     4,     4,     1,     1,     1,
     1,     0,     1,     0,     1,     2,     2,     1,     1,     1,
     1,     1,     2,     2,     1,     0,     5,     7,     5,     3,
     1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     1,     2,     2,     2,
     2,     1,     4,     4,     2,     2,     1,     0,     1,     1,
     3,     1,     1,     1,     3
};

static const short yydefact[] = {     0,
    17,    18,    19,    20,     0,     1,     2,     4,     0,     0,
    12,    13,    15,    16,     5,     7,     6,     3,    10,    34,
     9,     8,    49,    48,    45,     0,     0,    39,    42,    14,
     0,    54,    33,    35,    52,    26,    11,    38,     0,    37,
    49,    48,    45,     0,     0,     0,    66,     0,   134,     0,
     0,     0,     0,   133,     0,   132,    58,     0,    53,    55,
    59,     0,    60,    61,    62,     0,    71,    72,    85,    88,
    91,    96,   105,   110,   117,   122,    36,    51,    50,     0,
     0,     0,    25,    27,    40,    41,    44,    43,     0,     0,
    65,     0,   118,   120,   121,     0,   119,    32,    31,    57,
    56,    63,    64,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   125,   126,   128,     0,    47,    46,    30,    24,
     0,     0,     0,    70,     0,   135,    87,    86,   110,    90,
    89,    94,    92,    95,    93,   102,    99,   101,    97,   104,
   100,   103,    98,   107,   106,   109,   108,   114,   111,   115,
   112,   116,   113,    79,    73,    80,    74,    81,    75,    82,
    76,    83,    77,    84,    78,   130,     0,   127,   129,     0,
    28,    29,    66,    66,   124,     0,   123,    67,    69,   131,
    66,    68,     0,     0,     0
};

static const short yydefgoto[] = {   193,
     6,     7,     8,     9,    31,    11,    12,    13,    14,    26,
    37,    82,    83,    84,    57,    32,    33,    15,    27,    28,
    29,    80,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
   177,   178,   179,    76
};

static const short yypact[] = {    19,
-32768,-32768,-32768,-32768,    14,    19,-32768,-32768,    69,    64,
    33,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    33,
-32768,-32768,   -26,   -11,   -10,    13,    17,-32768,    37,-32768,
   121,   382,    33,-32768,    -4,    33,-32768,-32768,   121,-32768,
-32768,-32768,    20,    60,    35,    38,   425,    40,-32768,   425,
   425,   425,   425,-32768,   425,-32768,-32768,    29,   367,-32768,
-32768,    41,-32768,-32768,-32768,    15,-32768,    81,    80,    -1,
    94,    70,   281,   364,   119,-32768,-32768,-32768,-32768,     3,
   121,    82,   231,-32768,-32768,-32768,-32768,-32768,   425,    88,
-32768,   425,-32768,-32768,-32768,    99,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    18,    71,    98,   105,   129,   144,   151,
   166,   188,   193,   215,   230,   237,   252,   274,   279,   301,
   316,   323,-32768,-32768,   425,   425,-32768,-32768,-32768,-32768,
    33,   140,   111,-32768,   124,-32768,-32768,    80,-32768,-32768,
    -1,-32768,    94,-32768,    94,-32768,    70,-32768,    70,-32768,
    70,-32768,    70,-32768,   281,-32768,   281,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   131,-32768,   118,   128,
-32768,-32768,   418,   418,-32768,   425,-32768,   168,-32768,-32768,
   418,-32768,   170,   178,-32768
};

static const short yypgoto[] = {-32768,
-32768,   179,-32768,-32768,     2,-32768,   173,-32768,-32768,-32768,
-32768,-32768,-32768,   -80,   182,-32768,-32768,     9,-32768,    36,
   106,-32768,-32768,-32768,   -59,-32768,   141,-32768,-32768,-32768,
   -46,  -108,-32768,    96,    97,   -30,   101,     4,   -18,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		473


static const short yytable[] = {   101,
    91,    10,   132,   127,   -23,    78,    96,    10,   165,   167,
   169,   171,   173,   175,    16,   103,   176,    38,   137,   -22,
   -21,     1,   106,   107,     2,    35,     3,    49,    34,    98,
    50,    93,    94,    95,    79,     1,    97,    81,     2,   128,
     3,    77,   133,    36,    87,   135,    51,    52,    53,    39,
   181,    17,   -65,    45,    40,    35,    54,    41,     4,    55,
    86,    42,    44,    99,    43,    56,     5,   100,    89,    19,
    92,   140,     4,    88,    85,   143,   145,   190,   102,   180,
    49,   112,   113,    50,    81,   139,   139,   139,   139,   139,
   139,   139,   139,   139,   139,   159,   161,   163,   142,    51,
    52,    53,    20,   104,    23,   144,    21,    49,    24,    54,
    50,    25,    55,   130,    49,   155,   157,    50,    56,   108,
   109,   110,   105,   188,   189,   134,    51,    52,    53,   146,
   136,   192,    81,    51,    52,    53,    54,   111,    49,    55,
   182,    50,   183,    54,   148,    56,    55,   123,   124,   125,
   186,   150,    56,    49,   126,   184,    50,    51,    52,    53,
    49,    41,   185,    50,   187,    42,   152,    54,    43,   194,
    55,   191,    51,    52,    53,    49,    56,   195,    50,    51,
    52,    53,    54,    30,    18,    55,   129,    90,   154,    54,
    22,    56,    55,   156,    51,    52,    53,    49,    56,   138,
    50,   141,    49,     0,    54,    50,     0,    55,   147,   149,
   151,   153,     0,    56,     0,   158,    51,    52,    53,     0,
     0,    51,    52,    53,    49,     0,    54,    50,     0,    55,
   160,    54,     0,     1,    55,    56,     2,   162,     3,    49,
    56,     0,    50,    51,    52,    53,    49,     0,     0,    50,
     0,     0,   164,    54,     0,     0,    55,     0,    51,    52,
    53,    49,    56,   131,    50,    51,    52,    53,    54,     0,
     4,    55,     0,     0,   166,    54,     0,    56,    55,   168,
    51,    52,    53,    49,    56,     0,    50,     0,    49,     0,
    54,    50,     0,    55,   114,   115,   116,     0,     0,    56,
     0,   170,    51,    52,    53,     0,     0,    51,    52,    53,
    49,     0,    54,    50,     0,    55,   172,    54,     0,     0,
    55,    56,     0,   174,     0,    49,    56,     0,    50,    51,
    52,    53,    49,     0,     0,    50,     0,     0,     0,    54,
     0,     0,    55,     0,    51,    52,    53,     0,    56,     0,
     0,    51,    52,    53,    54,     0,     0,    55,     0,     0,
     0,    54,     0,    56,    55,     0,     0,     0,     0,     1,
    56,    46,     2,    47,     3,    48,    49,     0,     0,    50,
   117,   118,   119,   120,   121,   122,    46,     0,    47,     0,
    48,    49,     0,     0,    50,    51,    52,    53,     0,     0,
    20,     0,     0,     0,   -66,    54,     4,     0,    55,     0,
    51,    52,    53,     0,    56,    20,     0,     0,     0,   -66,
    54,     0,    46,    55,    47,     0,    48,    49,     0,    56,
    50,     0,     0,     0,    49,     0,     0,    50,     0,     0,
     0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
     0,    20,     0,    51,    52,    53,    54,     0,     0,    55,
     0,     0,     0,    54,     0,    56,    55,     0,     0,     0,
     0,     0,    56
};

static const short yycheck[] = {    59,
    47,     0,    83,     1,    31,    10,    53,     6,   117,   118,
   119,   120,   121,   122,     1,     1,   125,     1,     1,    31,
    31,     3,    24,    25,     6,    36,     8,    10,    20,     1,
    13,    50,    51,    52,    39,     3,    55,    36,     6,    37,
     8,    33,    89,    31,    10,    92,    29,    30,    31,    33,
   131,    38,    38,    17,    38,    36,    39,    41,    40,    42,
     1,    45,    27,    35,    48,    48,    48,    59,    31,     1,
    31,     1,    40,    39,    39,   106,   107,   186,    38,   126,
    10,    12,    13,    13,    83,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,     1,    29,
    30,    31,    34,    23,    41,     1,    38,    10,    45,    39,
    13,    48,    42,    32,    10,   112,   113,    13,    48,    26,
    27,    28,    43,   183,   184,    38,    29,    30,    31,     1,
    32,   191,   131,    29,    30,    31,    39,    44,    10,    42,
     1,    13,    32,    39,     1,    48,    42,    29,    30,    31,
    33,     1,    48,    10,    36,    32,    13,    29,    30,    31,
    10,    41,    32,    13,    37,    45,     1,    39,    48,     0,
    42,     4,    29,    30,    31,    10,    48,     0,    13,    29,
    30,    31,    39,    11,     6,    42,    81,    47,     1,    39,
     9,    48,    42,     1,    29,    30,    31,    10,    48,   104,
    13,   105,    10,    -1,    39,    13,    -1,    42,   108,   109,
   110,   111,    -1,    48,    -1,     1,    29,    30,    31,    -1,
    -1,    29,    30,    31,    10,    -1,    39,    13,    -1,    42,
     1,    39,    -1,     3,    42,    48,     6,     1,     8,    10,
    48,    -1,    13,    29,    30,    31,    10,    -1,    -1,    13,
    -1,    -1,     1,    39,    -1,    -1,    42,    -1,    29,    30,
    31,    10,    48,    33,    13,    29,    30,    31,    39,    -1,
    40,    42,    -1,    -1,     1,    39,    -1,    48,    42,     1,
    29,    30,    31,    10,    48,    -1,    13,    -1,    10,    -1,
    39,    13,    -1,    42,    14,    15,    16,    -1,    -1,    48,
    -1,     1,    29,    30,    31,    -1,    -1,    29,    30,    31,
    10,    -1,    39,    13,    -1,    42,     1,    39,    -1,    -1,
    42,    48,    -1,     1,    -1,    10,    48,    -1,    13,    29,
    30,    31,    10,    -1,    -1,    13,    -1,    -1,    -1,    39,
    -1,    -1,    42,    -1,    29,    30,    31,    -1,    48,    -1,
    -1,    29,    30,    31,    39,    -1,    -1,    42,    -1,    -1,
    -1,    39,    -1,    48,    42,    -1,    -1,    -1,    -1,     3,
    48,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
    17,    18,    19,    20,    21,    22,     5,    -1,     7,    -1,
     9,    10,    -1,    -1,    13,    29,    30,    31,    -1,    -1,
    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,    -1,
    29,    30,    31,    -1,    48,    34,    -1,    -1,    -1,    38,
    39,    -1,     5,    42,     7,    -1,     9,    10,    -1,    48,
    13,    -1,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
    -1,    34,    -1,    29,    30,    31,    39,    -1,    -1,    42,
    -1,    -1,    -1,    39,    -1,    48,    42,    -1,    -1,    -1,
    -1,    -1,    48
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 50 "parser.y"
{
                 yyerrok;
                 reporterror(wrong_st);
           ;
    break;}
case 10:
#line 58 "parser.y"
{

                    /* type을 0(default)로 세팅 */    
                    look_tmp->type=0;
                    yyerrok;
                    reporterror(wrong_funcdef);    
                  ;
    break;}
case 18:
#line 81 "parser.y"
{type_int=1;;
    break;}
case 19:
#line 82 "parser.y"
{type_void=1;;
    break;}
case 20:
#line 83 "parser.y"
{type_float=1;;
    break;}
case 21:
#line 88 "parser.y"
{

                  /* type이 identifier about parse error또는 
                  not defined identifier/function로 설정된 경우 */
                  if(look_id->type==0||look_id->type==5){
                        
                        /* void인지 int인지 float인지에 따라 function type 설정*/
                        if(type_void==1){
                              look_id->type=4; /* function, return type=void */
                        }else if(type_int==1){
                              look_id->type=8; /* function, return type=int */
                        }else if(type_float==1){
                              look_id->type=9; /* function, return type=float */
                        }
                    
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        look_tmp=look_id;
                  }
                  ;
    break;}
case 29:
#line 123 "parser.y"
{
                    yyerrok;
                    reporterror(nocomma);
             ;
    break;}
case 30:
#line 133 "parser.y"
{
                  if(type_int==1){ /* int로 설정된 경우 */
                        param_int=1; 
                        look_id->type=10;  /* integer scalar parameter */
                  }else if(type_float==1){ /* float으로 설정된 경우 */
                        param_float=1;
                        look_id->type=11; /* float scalar parameter */
                  }
                  type_int=0;
                  type_void=0;
                  type_float=0;
                  param_int=0;
                  param_float=0;

;
    break;}
case 32:
#line 151 "parser.y"
{
                        yyerrok;
                        reporterror(nobrace); /* no brace error */
                  ;
    break;}
case 37:
#line 162 "parser.y"
{
                        type_int=0;
                        type_void=0;
                        type_float=0;
                  ;
    break;}
case 38:
#line 167 "parser.y"
{
                        look_tmp->type=0; /* identifier about parse error*/
                        yyerrok;
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        reporterror(nosemi); /* no semicolon error */
                  ;
    break;}
case 41:
#line 178 "parser.y"
{
                    yyerrok;
                    reporterror(nocomma);
             ;
    break;}
case 45:
#line 187 "parser.y"
{
                  if(look_id->type==0){

                        /* scalar : int인지 void인지 float인지에 따라*/
                        if(type_int==1){
                              look_id->type=1; /* integer scalar variable */
                        }
                        else if(type_void==1)
                              look_id->type=2; /* void scalar variable */
                        else if(type_float==1){
                              look_id->type=6; /* float scalar variable */
                        }     
                  }
                  look_tmp=look_id;

            ;
    break;}
case 46:
#line 204 "parser.y"
{
                  /* array : int인지 float인지에 따라*/
                  if(look_id->type==0){
                        if(type_int==1)look_id->type=3; /* array integer variable */
                        else if(type_float==1) look_id->type=7;  /* array float variable */            
                  }

                   look_tmp=look_id;

            ;
    break;}
case 47:
#line 214 "parser.y"
{
                  yyerrok;
                  reporterror(nobracket); /* no bracekt error */
            ;
    break;}
case 64:
#line 241 "parser.y"
{
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                  ;
    break;}
case 79:
#line 265 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 80:
#line 269 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 81:
#line 273 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 82:
#line 277 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 83:
#line 281 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 84:
#line 285 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 87:
#line 292 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 90:
#line 299 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 94:
#line 308 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 95:
#line 312 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 101:
#line 323 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 102:
#line 328 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 103:
#line 332 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 104:
#line 336 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 107:
#line 346 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 109:
#line 351 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 114:
#line 361 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 115:
#line 366 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 116:
#line 371 "parser.y"
{
            yyerrok;
            reporterror(wrong_st);
      ;
    break;}
case 132:
#line 400 "parser.y"
{
                  if(look_id->type==0)
                        look_id->type=5; /* not defined identifier/function */

            ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 410 "parser.y"


