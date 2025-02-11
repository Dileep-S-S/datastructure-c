#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 30
struct stack {
    char st[MAX];
    int top;
};

void push(struct stack *st, char ch) {
    if (st->top == MAX - 1) {
        return;
    }
    st->st[++(st->top)] = ch;
}

char pop(struct stack *st) {
    if (st->top == -1) {
        return '#'; 
    }
    return st->st[(st->top)--];
}
int stackprec(char c){
    switch (c){
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':
        case '%':return 5;
        case '(':return 0;
        case '#':return -1;
        default :return 8;
    }
}
int infixprec(char c){
    switch (c){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '^':
        case '%':return 6;
        case '(':return 9;
        case ')':return 0;
        default :return 7;
    }
} 

void infixtopostfix(char infix[],char postfix[]){
    int i=0;
    int j=0;
    struct stack *S=(struct stack*)malloc(sizeof(struct stack));;
    S->top=-1;
    push(S,'#');
    char symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(isalnum(symbol)){
            postfix[j++]=symbol;
        }else if(symbol=='('){
            push(S,symbol);
        }else if(symbol == ')'){
            while(S->st[S->top]!='#'&&S->st[S->top]!='('){
                postfix[j++]=pop(S);
            }
            pop(S);
        }else{
            while(stackprec(S->st[S->top])>=infixprec(symbol)){
                postfix[j++]=pop(S);
            }
            push(S,symbol);
        }
    }
    while(S->st[S->top]!='#'){
        postfix[j++]=pop(S);
    }
    postfix[j]='\0';
    return ;
}

void postfixevaluation(char postfix[])
{
    char stack[30];
    int op1,op2;
    int res;
    char ch;
    int top=-1;
    for(int i=0;i<strlen(postfix);i++){
        ch=postfix[i];
        if(isdigit(ch)){
            stack[++top]=ch-'0';
        }
        else{
            if(top<1){
                printf("The given expression is wrong \n");
            }
            else{
                op1=stack[top--];
                op2=stack[top--];
                switch(ch){
                    case '+':res = op2+op1; break;
                    case '-':res = op2-op1; break;
                    case '/':res = op2/op1; break;
                    case '*':res = op2*op1; break;
                    case '%':res = op2%op1; break;
                    default :printf("invalid operator %c\n", ch);  
                }
                stack[++top] = res;
            }
        }
    }
    printf("the result is %d\n",res);
}
void main(){
    char infix[30];
    char postfix[30];
    printf("enter the infix expression : ");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    postfixevaluation(postfix);
}