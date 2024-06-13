#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* install_id(char* tok);
char* check_id_exist(char* tok);
void StackTable(int i);
char* reduce_scope(char* r1, char* r2, char* r3);

struct symbol{
    int seq_num;
    char name[40];
    int scope;
    int type;
    int parameter;
    struct symbol* next;
};

int top=0;
int cur_scope=0;

struct symbol stack[295];


char* check_id_exist(char* tok){
    if(top==0) return install_id(tok);
    for(int i=0;i<top;i++) if(strcmp(stack[i].name,tok)==0 && stack[i].scope==cur_scope) return stack[i].name;
    return install_id(tok);
}

void StackTable(int i){
    FILE* fp;
    fp = fopen("stack.c","a");
    fprintf(fp,"|  %d  |   %d   |   %s\n", i, cur_scope, stack[i].name);
    fclose(fp);
    return;
}

char* install_id(char* tok){ //put into stack
    strcpy(stack[top].name,tok);
    top++;
    StackTable(top-1);
    return stack[top-1].name;
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