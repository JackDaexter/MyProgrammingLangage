
#ifndef __HEADER__
#define __HEADER__

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VALUE_INT 4
#define VALUE_CHAR 1
#define VALUE_VOID 0
#define VALUE_LONG 8
#define VARIABLE 1000
#define FUNCT 1001
#define VAR 1002
#define TABLEAU 0
#define MAXNAME 32
#define MAXSYMBOLS 256
#define MAXARG 25



typedef struct {
      int type;
      int value;
      int operation;
      char charValue; 
      char name[MAXNAME];
}Variable;

typedef struct {
      int type;
      int value;
      char arg[100];
      char carac[3];
} Bvalue;

typedef struct {
  Bvalue argument[MAXARG];
	int type;
	char name[MAXNAME];
	int position;
	int valeur;
	int adresse;
  int isConst;
  int nbargs;
} VariableGlobal;

typedef struct {
    VariableGlobal vfunction;
}Function;

typedef struct {
    VariableGlobal variableGlobal;
    VariableGlobal variableLocal;	
    int type;
    char division;
    char addition;
    char caractere;
} STentry;


int addFunction(Function *symbolTable, const char name[], int type,int position);
int lookupFunction(Function *symbolTable, const char name[]);
int addVar(STentry *symbolTable, const char name[], int type,int position,int is_global,int const,int valeur);
int lookup(STentry *symbolTable, const char name[],int position,int lineno);
int getadress(STentry *local,const char name[]);
int nbValue();
int getNbArgument(Function * funct, const char name[]);
char *returnString(Function *functionName,char name[]);
void alloueEspace(FILE *out,STentry *allouer,int position);
int getArgument(Function *Funct, const char name[],const char namearg[]);
void declareGlobal(FILE *out,STentry *symbolTable);
void operation(STentry *symbol,Variable value1, Variable value2, char op,int opEnCours);
int addArgument(Function *funct, const char name[],int type,char *arg);
STentry *searchIdLocal(STentry *symbolTable, const char name[],int position,int is_global);
STentry *searchIdGlobal(STentry *symbolTable, const char name[],int position,int is_global);

#endif