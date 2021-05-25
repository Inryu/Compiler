%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_int =0;
int type_void=0;
int type_float=0;

int param_int=0;
int param_float=0;


extern reporterror();
extern yylex();
extern yyerror(char *s);

%}

%token TCONST TELSE TIF TINT TRETURN  TVOID TWHILE TPOINT
%token TPLUS TMINUS TSTAR TSLASH TMOD TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN TOR TEQUAL TNOTEQU TLESS TOVER TLESSE TINC TDEC
%token TOSBRA TCSBRA TCOMMA TOMBRA TCMBRA TOLBRA TCLBRA TSEMI
%token TNUMBER TFLOAT TLONG TNOT TAND TOVERE TILLIDENT TONECMT TMULCMT
%token TIDENT TGREATE
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE


%%
mini_c : translation_unit 
         ;         
translation_unit    : external_dcl            
         | translation_unit external_dcl
         ;
external_dcl       : function_def         
           | declaration
         ;            
function_def      : function_header compound_st
                  |function_header TSEMI
                  |function_header error
                  {
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
type_specifier    : TINT {type_int=1;}           
          | TVOID {type_void=1;}
          | TFLOAT {type_float=1;}
         ;
               
function_name    : TIDENT
                  
                  {
                  if(look_id->type==0||look_id->type==5){
                        
                        if(type_void==1){
                              look_id->type=4;
                        }else if(type_int==1){
                              look_id->type=8;
                        }else if(type_float==1){
                              look_id->type=9;
                        }
                    
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        look_tmp=look_id;
                  }
}
      ;            
formal_param       : TOSBRA opt_formal_param TCSBRA
         ;   
opt_formal_param    : formal_param_list      
            |   
         ;         
formal_param_list    : param_dcl 
             | formal_param_list TCOMMA param_dcl    
         ;
param_dcl       : dcl_spec declarator{
                  if(type_int==1){
                        param_int=1;
                        look_id->type=10;
                  }else if(type_float==1){
                        param_float=1;
                        look_id->type=11;
                  }
                  type_int=0;
                  type_void=0;
                  type_float=0;
                  param_int=0;
                  param_float=0;

}    
         ;   
compound_st       : TOMBRA opt_dcl_list opt_stat_list TCMBRA
                  | TOMBRA opt_dcl_list opt_stat_list error
                  {
                        yyerrok;
                        reporterror(nobrace);
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
                  }
                  | dcl_spec init_dcl_list error{
                        look_tmp->type=0;
                        yyerrok;
                        type_int=0;
                        type_void=0;
                        type_float=0;
                        reporterror(nosemi);
                  }
         ;
init_dcl_list       : init_declarator         
         | init_dcl_list TCOMMA init_declarator 
         ;   
init_declarator    : declarator            
          | declarator TASSIGN TNUMBER 
          | declarator TASSIGN TPOINT    
         ;
declarator    : TIDENT{
                  if(look_id->type==0){
                        if(type_int==1){
                              if(param_int==1){
                                    look_id->type=10;
                              }
                              else{look_id->type=1;}
                        }
                        else if(type_void==1)
                              look_id->type=2;
                        else if(type_float==1){
                              if(param_float==1){
                                    look_id->type=11;
                              }
                              else{look_id->type=6;}
                        }     
                  }
                  look_tmp=look_id;

            }               
            | TIDENT TOLBRA opt_number TCLBRA 
            {
                  if(look_id->type==0){
                        if(type_int==1)look_id->type=3;
                        else if(type_float==1) look_id->type=7;                      
                  }

                   look_tmp=look_id;

            }  
            |TIDENT TOLBRA opt_number error{
                  yyerrok;
                  reporterror(nobracket);
            }
         ;
opt_number       : TNUMBER 
              | TPOINT        
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
                        reporterror(nosemi);
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
      ;
logical_or_exp    : logical_and_exp         
      | logical_or_exp TOR logical_and_exp    
      ;
logical_and_exp    : equality_exp            
          | logical_and_exp TAND equality_exp 
         ;   
equality_exp       : relational_exp         
         | equality_exp TEQUAL relational_exp    
         | equality_exp TNOTEQU relational_exp 
         ;   
relational_exp    : additive_exp          
      | relational_exp TOVER additive_exp    
      | relational_exp TLESS additive_exp    
      | relational_exp TGREATE additive_exp    
      | relational_exp TLESSE additive_exp 
      ;   
additive_exp    : multiplicative_exp         
      | additive_exp TPLUS multiplicative_exp    
      | additive_exp TMINUS multiplicative_exp    
      ;
multiplicative_exp    : unary_exp            
             | multiplicative_exp TSTAR unary_exp    
             | multiplicative_exp TSLASH unary_exp    
             | multiplicative_exp TMOD unary_exp    
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
                        look_id->type=5;

            }            
              | TNUMBER       
              | TPOINT     
              | TOSBRA expression TCSBRA
         ;
%%

