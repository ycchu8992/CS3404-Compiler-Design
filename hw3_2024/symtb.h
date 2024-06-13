#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* table_lookup(char* sym, int scope, char* typ);
void print_symbol_table(int i);
char* push2symtb(char* sym, int scope, char* typ);
char* reduce_scope(char* r1, char* r2, char* r3);

int cur_scope=0;

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

char* table_lookup(char* sym, int scope, char* typ){
    if(num_symbol==0) return push2symtb(sym,scope,typ);
    for(int i=0;i<num_symbol;i++) {
        if( strcmp(symbol_table[i].name,sym)==0 && symbol_table[i].scope==scope ) {
            return symbol_table[i].name;
        }
    }
    return push2symtb(sym,scope,typ);
} 

void print_symbol_table(int i){
    FILE* fp;
    fp = fopen("symbol.c","a+");
    fprintf(fp,"\n|  Seq  | Scope |    Name    |        Type        |\n");
    fprintf(fp,"---------------------------------------------------\n");
    for(int i=0;i<num_symbol;i++) {
        fprintf(fp,"|  %2d   |   %d   |%*s%-10s|  %-12s|\n", symbol_table[i].seq_num, \
                symbol_table[i].scope, 2," ",symbol_table[i].name, symbol_table[i].type);
    }
    fclose(fp);
    return;
}

char* push2symtb(char* sym, int scope, char* typ){ //put into stack
    strcpy(symbol_table[num_symbol].name,sym);
    symbol_table[num_symbol].scope=scope;
    strcpy(symbol_table[num_symbol].type,typ);
    symbol_table[num_symbol].seq_num=num_symbol;
    num_symbol++;
    print_symbol_table(num_symbol);
    return symbol_table[num_symbol-1].name;
}

char* reduce_scope(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    cur_scope--;
    return buffer;
}