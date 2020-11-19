%{


int yylex();
int yyerror(char *);

extern int lineno;
int flag_error = 0;
int position = 0;

 #include "table-symbol.h"
FILE *out;

STentry symbolTable[132];
Function symbolFunct[200];

FILE *output;

int jump_label=0;
#define z(instruction) printf("%s\n", instruction)
#define z1(instruction, operande) printf("%s %d\n", instruction, operande)
#define zlabel(ch1, n, ch2) printf("%s%d%s\n", ch1, n, ch2)
char *section;
int is_global = 1; /*Permet de vérifier si les variables sont gloale ou locales */
int call_data = -1; /* Permet de tester si on a déja appeler section.data */
int first = 0; /* Test pour chaque fonction si on à déjà le push */

char *args[] = {"rdi","rsi","rdx","rcx","r8","r9"};
char *reg[] = {"ecx","edx","esi","eax","r8","r9"};
char *taille[] = {"","BYTE","","","DWORD","","","","QWORD"};
char *affect[] = {"ah","al","edx","ecx","eax","rsi","rdi","rcx","rax"};
char name[100];
int use_reg = 0;
int its_global =0;
int its_main = 0;
int nb_args = 0;
int its_call = 0;
int saut = 0;
int g_act = 0;
int posx = 0;
int dont_move = 0;
int adress = 0;
int save = 0;
char nameFunct[100];
int tst = 0;
int nope = 0;
int me = 0;
int its_if = 0;
int its_while = 0;
char vide[100];
int varchar = 0;
char var[100][200];
int valux[100];
int its_affect = 0;
char help[100];
%}



%union{
  int value;
  int type;
  char carac[3];
  char caractere;
  char name[32];
  char string[2];
  Bvalue litteral;
  Variable var;

}

%precedence '('
%precedence ')'
%precedence '!'
%precedence X
%precedence P
%nonassoc IF
%nonassoc ELSE
%expect 2

%token <carac> CARACTERE
%token <value> NUM
%token <name> IDENT 
%token <type> TYPE 
%token EQ
%token <caractere> ADDSUB DIVSTAR 
%token OR
%token AND 
%token ELSE
%token WHILE
%token RETURN
%token PRINT
%token IF
%token <caractere> RACC
%token PO
%token PF
%token LACC
%token READC
%token READE
%token EQUAL
%token CONST 
%token <type> VOID


%type <type>  LValue Exp EB TB FB M E T F READE READC
%type <litteral> Litteral NombreSigne

%left '='
%right error
%right ';'
%token <name> ORDERC
%token ORDER 

%%
Prog: {} DeclConsts {} DeclVars DeclFoncts {lookupFunction(symbolFunct,"main");}
    ;
DeclConsts:
       DeclConsts CONST ListConst ';' 
    |  error ';' %prec X
    |	%prec P
    ;
ListConst:
       ListConst ',' IDENT  '=' Litteral {addVar(symbolTable,$<name>3,$5.type,position,is_global,3,$5.value);}
    |  IDENT EQUAL Litteral  {addVar(symbolTable,$<name>1,$3.type,position,is_global,3,$3.value);}
    |  error Litteral 
    |  error
    |  ',' error '='
    | error '=' Litteral
    | IDENT error Litteral
    | IDENT '=' error
    ;
Litteral:
       NombreSigne {$$ = $1;}
    |  CARACTERE {$$.type = VALUE_CHAR; $$.value = $1[1];}
    ;
NombreSigne:
       NUM {$$.type = VALUE_INT; $$.value = $1;}
    |  ADDSUB NUM {$$.type = VALUE_INT; if($1 == '-'){$$.value = -$2;} else {$$.value = $2;}}
    ;

DeclVars:
       DeclVars TYPE  Declarateurs ';' {$<type>0 = $<type>2;}
    |  ;
Declarateurs:
        Declarateurs ','  Declarateur 
    |   Declarateur  
    ;
Declarateur:
       IDENT EQUAL {its_affect = 1;} F {if($<type>0 > 0 && $<type>0 <= VALUE_LONG){addVar(symbolTable,$<name>1,$<type>0,position,is_global,0,0);strncpy(var[varchar],$1,strlen($1)); varchar++;}
                                        else{addVar(symbolTable,$<name>1,$<type>-2,position,is_global,0,0);strncpy(var[varchar],$1,strlen($1)); varchar++;} } 
    |  IDENT 	 {if($<type>-2 > 0 && $<type>-2 <= VALUE_LONG){addVar(symbolTable,$<name>1,$<type>-2,position,is_global,0,0);}
                 else  {addVar(symbolTable,$<name>1,$<type>0,position,is_global,0,0); }} 
    |  IDENT '[' NUM ']'  
    |  IDENT '[' error ']' 
    |  error '['NUM ']'
    |  error ']'
    |  error '['
    |  '['error 
    |  ']' error 
    ;

DeclFoncts:
       DeclFoncts DeclFonct 
    |  DeclFonct 
    ;
DeclFonct: 
      EnTeteFonct {$<type>$ = $<type>1; }  Corps  
    | error '{' 
    ;
	
EnTeteFonct:
       TYPE IDENT  {  if(++call_data == 0){
                                         declareGlobal(out,symbolTable);
                                         fprintf(out,"section .text \n");
                                         fprintf(out,"extern printf \n");
                                         fprintf(out,"extern scanf \n");
                                         fprintf(out,"global _start\n");
                                        }
                                        
                                       addFunction(symbolFunct,$2,$1,position); 
                                      if(!strcmp($2,"main")) {its_main = 1;}
                                       fprintf(out,"%s :\n",returnString(symbolFunct,$2));
                                        fprintf(out,"\t push rsp \n \t mov rbp, rsp \n");  
                                        strncpy(nameFunct,$2,strlen($2));}  PO Parametres PF 

    |  VOID  IDENT  { if(++call_data == 0){
                                         declareGlobal(out,symbolTable);
                                         fprintf(out,"section .text \n");
                                         fprintf(out,"extern printf \n");
                                         fprintf(out,"extern scanf \n");
                                         fprintf(out,"global _start\n");
                                        } 
                                       addFunction(symbolFunct,$2,$1,position);
                                       if(!strcmp($2,"main")) {its_main = 1; }
                                       fprintf(out,"%s :\n",returnString(symbolFunct,$2));
                                       fprintf(out,"\t push rsp \n \t mov rbp, rsp \n ");
                                       strncpy(nameFunct,$2,strlen($2));}  PO Parametres PF 
    |  TYPE error '(' Parametres ')'
    |  VOID error '(' Parametres ')' 
    |  error IDENT  '(' Parametres ')' 
    |  error IDENT  '(' error ')' 
    |  TYPE IDENT '(' error ')' 
    |  VOID IDENT '(' error ')'
    |  VOID error '(' error ')' 
    ;




Parametres:
       {is_global = 0; ++position;} VOID 				
    |  {is_global = 0; ++position;} ListTypVar 
    ;
ListTypVar:
       ListTypVar ',' TYPE IDENT {addArgument(symbolFunct,nameFunct,$3,$4);}
    | TYPE IDENT {addArgument(symbolFunct,nameFunct,$1,$2);}
    ;
Corps: RACC DeclConsts  DeclVars { fprintf(out,"\t sub rsp,%d\n",nbValue()*4); STentry *table;its_affect = 0;
                                  for(int i = 0; i < varchar;i++){fprintf(out,"\t push QWORD %d \n",valux[i]);}
                                  for(int i = varchar-1; i >= 0;i--){if((table = searchIdLocal(symbolTable,var[i],position,is_global)))
                                       {fprintf(out,"\t pop rax \n \t mov [rbp - %d ], %s\n", table->variableLocal.adresse,affect[table->variableLocal.type]);strncpy(var[i],vide,100);}}} SuiteInstr LACC {if(its_main == 1) { fprintf(out,"\t mov eax,1 \n \t mov ebx,0 \n \t int 0x80 \n"); its_main = 0;} fprintf(out,"\t mov rsp,rbp \n \t pop rbp \n \t ret \n ");strncpy(nameFunct,vide,100);}
    | '{' DeclConsts DeclVars SuiteInstr error  
    |  error DeclConsts DeclVars SuiteInstr '}' 
    ;

SuiteInstr: SuiteInstr  Instr  
	  | 
      ;

SuiteBis :  RACC SuiteInstr LACC ;
Instr: 
       Exp ';' {its_call = 0;}
    |  ';'
    |  RETURN Exp ';' {if($<type>-5 == 3) {
    					            fprintf(stderr,"Error : line %d : Error, Type void function don't return anything\n",lineno);
                           return 1; 
    				          }
                       fprintf(out,"\t pop rax \n ");
                      
    				          }
    |  RETURN ';' {if($<type>-5 == 3) {
    				        fprintf(stderr,"Error : line %d : Error, Type void function don't return anything\n",lineno);
                    return 1;
    			         }}

    |  READE PO IDENT PF ';'{STentry* table = searchIdLocal(symbolTable,$3,position,is_global); 
                            if(table) {
                                    if(table->variableLocal.type != VALUE_INT && table->variableLocal.type != VALUE_LONG) { 
                                    fprintf(stderr,"Error : line %d : readc, error,its a char \n",lineno);
                                    return 1;
                                  }
                              } 
                              fprintf(out,"\t mov rax,rbp \n");
                              fprintf(out,"\t add rax, %d \n",table->variableGlobal.adresse);
                              fprintf(out,"\t mov rsi,rax \n");
                              if(table->variableLocal.type == VALUE_LONG)
                                fprintf(out,"\t mov rdi,read_long \n");
                              else
                                fprintf(out,"\t mov rdi,read_int \n");
                              fprintf(out,"\t mov rax,0 \n");
                              fprintf(out,"\t call scanf WRT ..plt\n");}

    |  READC PO IDENT PF ';'{STentry* table = searchIdLocal(symbolTable,$3,position,is_global);

                               if(table) {
                                    if(table->variableLocal.type != VALUE_CHAR) { 
                                    fprintf(stderr,"Error : line %d : readc, error,its not a char \n",lineno);
                                    return 1;
                                  }
                              }
                              else if ((table = searchIdGlobal(symbolTable,$3,position,is_global))) {
                                    if(table->variableGlobal.type != VALUE_CHAR) { 
                                         fprintf(stderr,"Error : line %d : readc, error,its not a char \n",lineno);
                                         return 1;
                                    }
                                     
                              }
                              fprintf(out,"\t mov rax,rbp \n");
                              fprintf(out,"\t add rax, %d\n",table->variableGlobal.adresse);
                              fprintf(out,"\t mov rsi,rax \n");
                              fprintf(out,"\t mov rdi,read_char \n");
                              fprintf(out,"\t mov rax,0 \n");
                              fprintf(out,"\t call scanf WRT ..plt\n");
    						        	   }

    |  PRINT { me =1;} PO Exp PF ';' { if(its_call == 0){
                                fprintf(out,"\t pop rax \n");
                              }
                              if($4 == VALUE_INT){
                                  fprintf(out,"\t mov esi, eax \n");
                                  fprintf(out,"\t mov rdi, printf_int \n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call  printf WRT ..plt \n");
                               }else if($4 == VALUE_CHAR){
                                  fprintf(out,"\t mov esi, eax \n");
                                  fprintf(out,"\t mov rdi, printf_char\n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call  printf WRT ..plt\n");
                               }else{
                                  fprintf(out,"\t mov rsi, rax \n");
                                  fprintf(out,"\t mov rdi, printf_long \n");
                                  fprintf(out,"\t mov rax,0 \n");
                                  fprintf(out,"\t call printf WRT ..plt \n");
                               }
                                 its_call = 0;
                                 me = 0;
                            }
    |  IF PO Exp PF XX Instr  {fprintf(out,"\t else%d:\n",saut-1);}
    |  IF PO Exp PF XX Instr  ELSE {fprintf(out,"\t jmp end_if%d \n \t else%d: \n",saut,saut);}  Instr  {fprintf(out,"\t end_if%d:\n",saut-1);}  
                                                 
    |  WHILE {fprintf(out,"\t while%d: \n",saut); its_while = 1;} PO Exp PF XX Instr {fprintf(out,"\t jmp while%d \t \n \t else%d: \n",saut-1,saut-1);its_while = 0;} { /*zlabel("\t jmp while",$<type>7,"");zlabel("\t end_while",$<type>7,":");*/}


    |  SuiteBis
    |  IF error Exp ')' 
    |  IF '(' Exp error  ';'
    |  READE '(' error ')' 
    |  READE error Exp ')'  
    |  READE '(' Exp error  ';'
    |  PRINT error Exp ')' 
    |  PRINT '(' Exp error  ';'
    |  error ')' 
    |  error '{'
    |  error '('
    |  '(' error ';'
    ;

  XX : {fprintf(out,"\t begin%d: \n",saut); ++saut;}
     ;

Exp :  LValue EQUAL { g_act = 1; if(posx == 1){dont_move = 1;} else {dont_move = 0;} save = adress; if(posx != 2) {nope = 1;}} Exp { 
         STentry* table = searchIdLocal(symbolTable,help,position,is_global);
         if ($1 == VALUE_CHAR  && $4 == VALUE_LONG) {
              fprintf(stderr,"line %d : Warning conversion to ‘char’ from ‘long int’ may alter its value\n",lineno);
              $1 = $4;
              table->variableLocal.type = $4;
            
         } 
  		  else if ($1 == VALUE_INT && $4 == VALUE_LONG) {
               fprintf(stderr,"line %d : Warning conversion to ‘int’ from ‘long int’ may alter its value\n",lineno);
               $1 = $4;
                table->variableLocal.type = $4;
           } 
  		  else if ($1 == VALUE_CHAR && $4 == VALUE_INT){
  	         fprintf(stderr,"line %d : warning: conversion to ‘char’ from ‘int’ may alter its value \n",lineno);
             $1 = $4;
              table->variableLocal.type = $4;
  	 	   }
         strncpy(help,vide,100);
         
         fprintf(out,"\t pop rcx\n");
         
         if(dont_move == 1){
           fprintf(out,"\t mov [%s], %s \n ",name,affect[$1 -1]);
         }

        else if(nope == 1){
            fprintf(out,"\t mov QWORD [rbp - %d],rcx \n ",save);
         }
         else{
           fprintf(out,"\t mov QWORD [rbp + %d],%s \n ",save,affect[$1 -1]);
         }
        nope = 0;
         its_global = 0;
         g_act = 0;
          tst = 0;

    }
    |  LValue error Exp 
    |  LValue '=' error  
    |  LArray '=' Bloc {}  
    |  LArray '=' error {}  
    |  EB 
    ;

EB  :  EB OR TB 
    |  TB { $$ = $1;}
    ;

TB  :  TB AND FB
    |  FB { $$ = $1; }
    ;
FB  :  FB EQ M 
    |  M { $$ = $1; }
    ;
M   :  M ORDERC E {{  fprintf(out,"\t pop rcx \n \t pop rax \n");     
                          if (!strcmp($2, ">")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jng else%d \n",saut);
                          }
                         else if (!strcmp($2, "<=")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jg else%d \n",saut);
                         }
                         else if (!strcmp($2, "<")){
                            fprintf(out," \t cmp rax,rcx\n");
                            fprintf(out,"\t jnl else%d \n",saut);
                         }
                         else if (!strcmp($2, ">=")){
                            fprintf(out,"\t cmp rax,rcx\n");
                            fprintf(out,"\t jl else%d \n",saut);
                         }

                        }} 
    |  E { $$ = $1;}
    ;
E   :  E ADDSUB T {   if ($1 == VALUE_LONG || $3 == VALUE_LONG){               
                          if($3 == VALUE_LONG)
                              $$ = $3; 
                          else if ($1 == VALUE_LONG)
                                       $$ = $1; 
                        }
                        else if ($1 == VALUE_INT ||$3  == VALUE_INT){
                               if($3 == VALUE_INT)
                                    $$ = $3; 
                                else if ($1 == VALUE_INT)
                                    $$ = $1; 
                        }
                        if($2 == '+'){
                           fprintf(out,"\t pop rcx\n ");
                           fprintf(out,"\t pop rax \n");
                           fprintf(out,"\t add rax,rcx \n");
                           fprintf(out,"\t push rax\n ");
                        }
                        else{
                           fprintf(out,"\t pop rcx \n ");
                           fprintf(out,"\t pop rax \n ");
                           fprintf(out,"\t sub rax, rcx \n");
                           fprintf(out,"\t push rax\n ");
                        }
                        
                    }

    |  T { $$ = $1; }
    ;    
T   :  T DIVSTAR F { if ($1 == VALUE_LONG || $3 == VALUE_LONG){               
                          if($3 == VALUE_LONG)
                              $$ = $3; 
                          else if ($1 == VALUE_LONG)
                                       $$ = $1; 
                        }
                        else if ($1 == VALUE_INT || $3 == VALUE_INT){
                               if($3 == VALUE_INT)
                                    $$ = $3; 
                                else if ($1 == VALUE_INT)
                                    $$ = $1; 
                        }
                         if($2 == '*'){
                           fprintf(out,"\t pop rcx\n ");
                           fprintf(out,"\t pop rax \n");
                           fprintf(out,"\t  imul rax,rcx \n");
                           fprintf(out,"\t push rax \n");
                        }
                        else if($2 == '/'){
                           fprintf(out,"\t pop rcx\n");
                           fprintf(out,"\t mov rdx, 0\n");
                           fprintf(out,"\t pop rax\n");
                           fprintf(out,"\t idiv rcx \n");
                           fprintf(out,"\t push rax \n");
                        }
                         else if($2 == '%'){
                           fprintf(out,"\t pop rcx\n");
                           fprintf(out,"\t mov rdx, 0\n");
                           fprintf(out,"\t pop rax\n");
                           fprintf(out,"\t idiv rcx \n");
                           fprintf(out,"\t push rdx \n");
                        }
                      } 

    |  F { $$ = $1; }
    ;

F   :  ADDSUB F { if($1 == '-') $$ = -$2; 
                  else $$ = $2; }
    |  '!' F { $$ = $2; }
    |  PO Exp PF { $$ = $2;}
    |  LValue    {$$ = $1; if(its_global == 0 && posx == 0) {fprintf(out,"\t push QWORD [rbp - %d] \n ",adress);} 
                           else if (posx == 2 && tst == 0 && g_act != 1){ fprintf(out,"\t push QWORD [rbp + %d] \n ",adress);}
                           else if (me == 1 && posx == 1) {fprintf(out,"\t push QWORD [%s] \n ",name);}}
    |  NUM 	 { $$ = VALUE_INT; if(its_affect == 0){fprintf(out,"\t push QWORD %d\n",$1);} else{valux[varchar] = $1;}}
    |  CARACTERE {$$ = VALUE_CHAR; fprintf(out,"\t push BYTE %s \n",$1);}
    |  IDENT PO Arguments  PF {  int nbargg =  getNbArgument( symbolFunct,$1);
                                 //printf("On a %d argument \n",nbarr);
                                 if(lookupFunction(symbolFunct,$1) == 0){
                                    fprintf(stderr,"Error : This function doesn't exist.\n");
                                    return 1;
                                  }
                                  else if(nbargg != nb_args){

                                     fprintf(stderr,"Error : Error nb Argument : The function %s have %d arguments. Expect %d \n",$1,nb_args,nbargg);
                                     return 1;
                                  }
                                   fprintf(out,"\t call %s \n",$1);
                                   its_call = 1;
                                   nb_args = 0;
                                }
    | PO TYPE PF F { if($2 <= VALUE_LONG) { $4 = $2;}}
                          
    ;
LValue	:  IDENT {STentry* table = searchIdLocal(symbolTable,$1,position,is_global);
                  int funct;

    		          if(table) {
                          strncpy(help,$1,strlen($1));
                          $$ = table->variableLocal.type;
                          //printf("\t push %d \n",
                          adress = table->variableLocal.adresse;  
                          its_global = 0;
                          posx = 0;
                    }
                    else if (( funct =  getArgument(symbolFunct,nameFunct,$1)) != -1) {
                          posx = 2;
                          adress = 8 + (8 * (funct+1));
                          if(g_act == 1){
                            tst = 1;
                            fprintf(out," \t push QWORD [rbp + %d ] \n",adress);
                          }
                          $$ = VALUE_LONG;
                  }
                  else if ((table = searchIdGlobal(symbolTable,$1,position,is_global))) {
                          if(g_act != 1 && table->variableLocal.type == VALUE_CHAR){
                            table->variableLocal.type = VALUE_INT;
                          }
                         $$ = table->variableGlobal.type;
                         its_global = 1;
                         strncpy(name,table->variableGlobal.name,strlen(table->variableGlobal.name));
                         if( g_act == 1){
                             its_global = 2;
                             if(table->variableGlobal.isConst == 3){
                               /*fprintf(stderr,"Error : You cannot change const variable %s \n",$1);
                                return 1;*/
                             }
                            fprintf(out,"\t push QWORD [%s] \n",table->variableGlobal.name);
                          }
                          else if(its_if == 1 || its_while ==1){
                            fprintf(out,"\t push QWORD [%s] \n",table->variableGlobal.name);
                          }
                          else{
                            posx = 1;

                          }
                      }
                  
                  else{
                    fprintf(stderr,"Error : The variable %s have not be init \n",$1);
                    return 1;
                  }

                  }
                 
      			   

	;
LArray  :  LValue Array 
        |  error Array 
        ;
Array : '[' NUM ']' 
      |	'[' NUM ']' Array  
      | '[' error ']' Array 
      |  error NUM ']'
      ;
Bloc : '{' Element '}'
     | error Element '}'
     | '{' error '}'
     | '{' Element error ';' 
     | error ';'
     ;
Element: NUM 
       | NUM ',' Element
       | Bloc  
       | Bloc ',' Element
       | error ',' Element
       | Bloc ',' error
       ;
Arguments:
       ListExp 
    | ;
ListExp:
       ListExp ',' Exp {nb_args++;}

    |  Exp {nb_args++;}
    ;

%%


int main(){  
  out = fopen("output.asm","w");

  yyparse();
  return flag_error;
}

int yyerror(char *s){
        //IF ERROR RETURN 1 ELSE RETURN 0
	printf("Syntaxe error line %d \n",lineno);
    flag_error = 1; //ERROR 
       
	return 0;
}
