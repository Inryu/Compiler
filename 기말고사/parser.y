%{
/*
* parser.y.- yacc source for the MiniC(HW3)
*
* Programmer - team2
*
* 1871040이유정 / 1871026 신인류 / 1876136 박가현
*
* date -  6/05/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"
 int type_int=0;
 int type_void=0;
 int type_float=0;
 
 int type_char=0;
 int type_string=0;
 int param_int=0;
 int param_float=0;
 int param_char=0;
 int param_string=0;
 char scope[100]="\0";
extern reporterror();
extern yylex();
extern char *yytext;
extern yyerror(char *s);
extern append(char *dst, char c);
%}
%token TCONST TELSE TIF TINT TRETURN  TVOID TWHILE TPOINT TILLSP
%token TPLUS TMINUS TSTAR TSLASH TMOD TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN TOR TEQUAL TNOTEQU TLESS TOVER TLESSE TINC TDEC
%token TOSBRA TCSBRA TCOMMA TOMBRA TCMBRA TOLBRA TCLBRA TSEMI
%token TNUMBER TFLOAT TLONG TNOT TAND TOVERE TILLIDENT TONECMT TMULCMT
%token TIDENT TSTRING TCHAR TCHARVAR TSTRINGVAR
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE
%%
mini_c : translation_unit 
         ;         
translation_unit    : external_dcl            
         | translation_unit external_dcl
         ;
external_dcl    
            : function_def         
           | declaration
           | TIDENT TSEMI
           | TIDENT error{
                 yyerrok;
                 reporterror(wrong_st);
           };
               
function_def      : function_header compound_st
                  |function_header TSEMI
                  |function_header error /* function definition error*/
                  {
                    /* type을 0(default)로 세팅 */    
                    look_tmp->type=0;
                    yyerrok;
                    reporterror(wrong_funcdef);    
                  }
         ;      
function_header    : dcl_spec function_name formal_param   
         ;
dcl_spec       : dcl_specifiers   
         ;   
dcl_specifiers       : dcl_specifier         
          	    | dcl_specifiers dcl_specifier   
         ;
dcl_specifier       : type_qualifier      
         | type_specifier
         ;         
type_qualifier       : TCONST
         ;            
      /* type_specifier 종류에 따라, 해당 type변수를 1로 설정*/
type_specifier    : TINT {type_int=1;}           
          | TVOID {type_void=1;}
          | TFLOAT {type_float=1;}
          | TCHAR {type_char=1;}
          | TSTRING {type_string=1;}
         ;
               
function_name    : TIDENT                  
                  {
	      strcpy(scope,preyytext);
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
                        }else if(type_char==1){ /* function, return type=char */
                              look_id->type=14;
                        }else if(type_string==1){ /* function, return type=string */
                              look_id->type=15;
                        }
                    
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                  }
                  }
                  /* ill identifier, too long identifier인 경우, scanner에서 에러 발생시킴*/
                  |TILLIDENT
                  |TLONG;
          
            
formal_param       : TOSBRA opt_formal_param TCSBRA
         ;   
opt_formal_param    : formal_param_list      
            |   
         ;         
formal_param_list    : param_dcl 
             | formal_param_list TCOMMA param_dcl
             | formal_param_list param_dcl error {
                    yyerrok;
                    reporterror(nocomma);
             } 
             
            
         ;
                  /* 파라미터인 경우 */
param_dcl       : dcl_spec declarator{
                  if(type_int==1){ /* int로 설정된 경우 */
                        param_int=1; 
                        look_id->type=10;  /* integer scalar parameter */
						strcpy(look_id->scope, scope);
                  }else if(type_float==1){ /* float으로 설정된 경우 */
                        param_float=1;
                        look_id->type=11; /* float scalar parameter */
                        strcpy(look_id->scope, scope);
                  }else if(type_char==1){
                        param_char=1;
                        look_id->type=16;                        
                        strcpy(look_id->scope, scope);
                  }
                  else if(type_string==1){
                        param_string=1;
                        look_id->type=17;                        
                       strcpy(look_id->scope, scope);
                  }
                  type_int=0;
                  type_void=0;
                  type_float=0;
                  type_char=0;
                  type_string=0;
                  param_int=0;
                  param_float=0;
                  param_char=0;
                  param_string=0;
	      look_tmp=look_id;
}    
         ;   
compound_st       : TOMBRA opt_dcl_list opt_stat_list TCMBRA
                  | TOMBRA opt_dcl_list opt_stat_list error
                  {
                        yyerrok;
                        reporterror(nobrace); /* no brace error */
                  }
         ;
opt_dcl_list       : declaration_list   
         |   
         ;         
declaration_list    : declaration         
         | declaration_list declaration 
         ;   
declaration       : dcl_spec init_dcl_list TSEMI{
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                  }
                  | dcl_spec init_dcl_list error{
                        look_tmp->type=0; /* identifier about parse error*/
                        yyerrok;
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        type_char=0;
                        type_string=0;
                        reporterror(nosemi); /* no semicolon error */
                  }
         ;
init_dcl_list       : init_declarator         
         | init_dcl_list TCOMMA init_declarator 
         | init_dcl_list init_declarator error {
                    yyerrok;
                    reporterror(nocomma);
             } 
         ;   
init_declarator    : declarator            
          | declarator TASSIGN TNUMBER 
          | declarator TASSIGN TPOINT    
          | declarator TASSIGN TCHARVAR
          | declarator TASSIGN TSTRINGVAR
         ;
declarator    : TIDENT{
                  if(look_id->type==0){
                        /* scalar : int인지 void인지 float인지에 따라*/
                        if(type_int==1){
                              look_id->type=1; /* integer scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_void==1){
                              look_id->type=2; /* void scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_float==1){
                              look_id->type=6; /* float scalar variable */
                              strcpy(look_id->scope, scope);
                        }
                        else if(type_char==1){
                              look_id->type=12; /* char scalar variable */
                              strcpy(look_id->scope, scope);
                        }     
                        else if(type_string==1){
                              look_id->type=13; /* string scalar variable */
                              strcpy(look_id->scope, scope);
                        }          
                  }
                  look_tmp=look_id;
            }               
            | TIDENT TOLBRA opt_number TCLBRA 
            {
                  /* array : int인지 float인지에 따라*/
                  if(look_id->type==0){
                        if(type_int==1)look_id->type=3; /* array integer variable */
                        else if(type_float==1) look_id->type=7;  /* array float variable */            
                  }
                   look_tmp=look_id;
            }  
            |TIDENT TOLBRA opt_number error{
                  yyerrok;
                  reporterror(nobracket); /* no bracekt error */
            }
            |TILLIDENT
            |TLONG;
         
opt_number       : TNUMBER 
              | TPOINT  /* float형 숫자 */      
              |   
         ;         
opt_stat_list       : statement_list      
          |   
         ;         
statement_list       : statement         
          | statement_list statement    
          | statement_list declaration
         ;
statement       : compound_st         
            | expression_st         
            | if_st            
            | while_st            
            | return_st         
            ;
expression_st    : opt_expression TSEMI
                  | expression error
                  {
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                  }
      ;   
opt_expression    : expression            
      |
      ;               
if_st          : TIF TOSBRA expression TCSBRA statement  %prec LOWER_THAN_ELSE
         | TIF TOSBRA expression TCSBRA statement TELSE statement
         ;
while_st       : TWHILE TOSBRA expression TCSBRA statement    
         ;
return_st       : TRETURN opt_expression TSEMI
         ;
expression       : assignment_exp   
         ;   
assignment_exp    : logical_or_exp         
      | unary_exp TASSIGN assignment_exp
      | unary_exp TADDASSIGN assignment_exp    
      | unary_exp TSUBASSIGN assignment_exp    
      | unary_exp TMULASSIGN assignment_exp    
      | unary_exp TDIVASSIGN assignment_exp    
      | unary_exp TMODASSIGN assignment_exp   
      | unary_exp TASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }  
      | unary_exp TADDASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }     
      | unary_exp TSUBASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }      
      | unary_exp TMULASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }     
      | unary_exp TDIVASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }     
      | unary_exp TMODASSIGN error{
            yyerrok;
            reporterror(wrong_st);
      }  
      ;
logical_or_exp    : logical_and_exp         
      | logical_or_exp TOR logical_and_exp  
      |  logical_or_exp TOR error{
            yyerrok;
            reporterror(wrong_st);
      }  
      ;
logical_and_exp    : equality_exp            
          | logical_and_exp TAND equality_exp 
          | logical_and_exp TAND error{
            yyerrok;
            reporterror(wrong_st);
      }   
         ;   
equality_exp       : relational_exp         
         | equality_exp TEQUAL relational_exp    
         | equality_exp TNOTEQU relational_exp 
          | equality_exp TEQUAL error{
            yyerrok;
            reporterror(wrong_st);
      }       
         | equality_exp TNOTEQU error{
            yyerrok;
            reporterror(wrong_st);
      }   
         ;   
relational_exp    : additive_exp          
      | relational_exp TOVER additive_exp
      | relational_exp TOVERE additive_exp     
      | relational_exp TLESS additive_exp    
      | relational_exp TLESSE additive_exp 
       | relational_exp TOVER  error{
            yyerrok;
            reporterror(wrong_st);
      }   
     
      | relational_exp TLESS  error{
            yyerrok;
            reporterror(wrong_st);
      }           
      | relational_exp TOVERE  error{
            yyerrok;
            reporterror(wrong_st);
      }          
      | relational_exp TLESSE  error{
            yyerrok;
            reporterror(wrong_st);
      }        
      ;   
additive_exp    : multiplicative_exp         
      | additive_exp TPLUS multiplicative_exp
      | additive_exp TPLUS error{
            yyerrok;
            reporterror(wrong_st);
      } 
      | additive_exp TMINUS multiplicative_exp  
      | additive_exp TMINUS error {
            yyerrok;
            reporterror(wrong_st);
      };
multiplicative_exp    : unary_exp            
             | multiplicative_exp TSTAR unary_exp
             | multiplicative_exp TSLASH unary_exp  
             | multiplicative_exp TMOD unary_exp  
              | multiplicative_exp TSTAR  error{
            yyerrok;
            reporterror(wrong_st);
      }        
             | multiplicative_exp TSLASH  error{
            yyerrok;
            reporterror(wrong_st);
      }        
  
             | multiplicative_exp TMOD  error{
            yyerrok;
            reporterror(wrong_st);
      }        
    
         ;
unary_exp       : postfix_exp      
            | TMINUS unary_exp            
            | TNOT unary_exp            
            | TINC unary_exp         
            | TDEC unary_exp
         ;         
postfix_exp       : primary_exp            
               | postfix_exp TOLBRA expression TCLBRA    
               | postfix_exp TOSBRA opt_actual_param TCSBRA    
               | postfix_exp TINC
               | postfix_exp TDEC
         ;         
opt_actual_param    : actual_param            
           |      
         ;         
actual_param       : actual_param_list   
         ;      
actual_param_list    : assignment_exp         
            | actual_param_list TCOMMA assignment_exp
        
         ;
primary_exp   : TIDENT
            {
                  if(look_id->type==0)
                        look_id->type=5; /* not defined identifier/function */
            }            
              | TNUMBER       
              | TPOINT     
              | TOSBRA expression TCSBRA
              | TCHARVAR
              | TSTRINGVAR
                          
         ;
%%
