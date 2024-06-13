#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void symbol_table_format();
char* table_lookup(char* sym, int scope, char* typ);
void print_symbol_table(int i);
char* push2symtb(char* sym, int scope, char* typ);

struct symbol{
    int seq_num;
    int scope;
    char type[40];
    //int parameter;
    char name[40];
    //struct symbol* next;
};

int num_symbol=0;

struct symbol symbol_table[295];

void symbol_table_format(){
    FILE* fp;
    fp = fopen("symbol.c","a");
    fprintf(fp,"|  Seq  | Scope |   Type   |    Name    \n");
    fprintf(fp,"---------------------------------------\n");
    fclose(fp);
}

char* table_lookup(char* sym, int scope, char* typ){
    if(num_symbol==0) {
        symbol_table_format();
        return push2symtb(sym,scope,typ);
    }
    for(int i=0;i<num_symbol;i++) {
        if( strcmp(symbol_table[i].name,sym)==0 && symbol_table[i].scope==scope ) {
            return symbol_table[i].name;
        }
    }
    return push2symtb(sym,scope,typ);
} 

void print_symbol_table(int i){
    FILE* fp;
    fp = fopen("symbol.c","a");
    fprintf(fp,"|  %2d   |   %d   |   %s   |   %s\n", symbol_table[i].seq_num, symbol_table[i].scope, symbol_table[i].type, symbol_table[i].name);
    fclose(fp);
    return;
}

char* push2symtb(char* sym, int scope, char* typ){ //put into stack
    printf("%s\n",typ);
    strcpy(symbol_table[num_symbol].name,sym);
    symbol_table[num_symbol].scope=scope;
    strcpy(symbol_table[num_symbol].type,typ);
    symbol_table[num_symbol].seq_num=num_symbol;
    print_symbol_table(num_symbol);
    num_symbol++;
    return symbol_table[num_symbol-1].name;
}
