#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* reduce_nonterminal(char* r1);
char* reduce_terminal(char* r1);
char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal(char* r1, char* r2);
char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_terminal(char* r1, char* r2);
char* reduce_nonterminal_terminal(char* r1, char* r2);
char* reduce_terminal_nonterminal(char* r1, char* r2);
char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal_terminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_for_stmt(char* r1);
char* reduce_for_expr(char* r1, char* r2, char* r3);
char* reduce_unary_prefix_expr(char* r1, char* r2);
char* reduce_unary_postfix_expr(char* r1, char* r2);
char* reduce_factor_expr(char* r1);
char* reduce_func_invoc_expr(char* r1, char* r2);
char* reduce_type_casting_expr(char* r2, char* r4);

char* reduce_nonterminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    free(r1);
    return buffer;                           
}

char* reduce_terminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    return buffer;                           
}

char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r3);
    return buffer;
}

char* reduce_terminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    return buffer;
}

char* reduce_nonterminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    return buffer;
}

char* reduce_terminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r2);
    return buffer;
}

char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r3);
    return buffer;
}

char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    free(r3);
    return buffer;    
}

char* reduce_nonterminal_nonterminal_terminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r2);
    return buffer;    
}

char* reduce_nonterminal_nonterminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r2);
    free(r3);
    return buffer;    
}

char* reduce_for_stmt(char* r1){
    size_t l = strlen("<stmt>");
    size_t n1 = strlen(r1);
    size_t r = strlen("</stmt>");
    char* buffer = (char*)malloc(l+r+n1+1);
    strcpy(buffer,"<stmt>");
    strcat(buffer,r1);
    strcat(buffer,"</stmt>");
    free(r1);   
    return buffer;
} 

char* reduce_for_expr(char* r1, char* r2, char* r3){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t n3 = strlen(r3);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,r3);
    strcat(buffer,"</expr>");
    free(r1);
    free(r3);
    return buffer;
}

char* reduce_unary_prefix_expr(char* r1, char* r2){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,"</expr>");
    free(r2);
    return buffer;
}

char* reduce_unary_postfix_expr(char* r1, char* r2){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,"</expr>");
    free(r1);
    return buffer;
}

char* reduce_factor_expr(char* r1){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,"</expr>");
    free(r1);
    return buffer;
}

char* reduce_func_invoc_expr(char* r1, char* r2){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,"</expr>");
    free(r1);
    free(r2);
    return buffer;
}

char* reduce_type_casting_expr(char* r2, char* r4){ 
    size_t l = strlen("<expr>");
    size_t lp = strlen("(");
    size_t n2 = strlen(r2);
    size_t n4 = strlen(r4);
    size_t rp = strlen(")");
    size_t r = strlen("</expr>");   
    char* buffer = (char*)malloc(l+lp+r+rp+n2+n4+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,"(");
    strcat(buffer,r2);
    strcat(buffer,")");
    strcat(buffer,r4);
    strcat(buffer,"</expr>");
    free(r2);
    free(r4);
    return buffer;
}