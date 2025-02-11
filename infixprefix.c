#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

struct stack {
    char s[MAX];
    int top;
};

void push(struct stack *st, char ch) {
    if (st->top == MAX - 1) {
        return;
    }
    st->s[++(st->top)] = ch;
}

char pop(struct stack *st) {
    if (st->top == -1) {
        return '#'; 
    }
    return st->s[(st->top)--];
}

int stackprec(char c) {
    switch (c) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 3;
        case '^': case '$': return 6;
        case ')': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int infixprec(char c) {
    switch (c) {
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 4;
        case '^': case '$': return 5;
        case '(': return 0;
        case ')': return 9;
        default: return 7;
    }
}



// Function to convert infix to prefix
void infixtoprefix(char infix[], char prefix[]) {
    struct stack st;
    st.top = -1;
    push(&st, '#'); 

    strrev(infix);

    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) { // Operand directly added
            prefix[j++] = symbol;
        } else if (symbol == ')') {  // Push right parenthesis to stack
            push(&st, symbol);
        } else if (symbol == '(') {  // Pop until right parenthesis is found
            while (st.s[st.top] != '#' && st.s[st.top] != ')') {
                prefix[j++] = pop(&st);
            }
            pop(&st); // Remove ')'
        } else {  // Operator handling
            while (stackprec(st.s[st.top]) >= infixprec(symbol)) {
                prefix[j++] = pop(&st);
            }
            push(&st, symbol);
        }
    }

    while (st.s[st.top] != '#') {
        prefix[j++] = pop(&st);
    }
    prefix[j] = '\0';

    strrev(prefix); // Reverse the final result
}

// Function to evaluate prefix expression
int evaluatePrefix(char prefix[]) {
    int stack[MAX];
    int top = -1;

    strrev(prefix); // Reverse prefix for evaluation
    int i, op1, op2;

    for (i = 0; prefix[i] != '\0'; i++) {
        char ch = prefix[i];

        if (isdigit(ch)) { // Push operand to stack
            stack[++top] = ch - '0';
        } else { // Operator: Pop two elements and apply operation
            if (top < 1) {
                printf("Invalid Expression\n");
                return -1;
            }
            op1 = stack[top--];
            op2 = stack[top--];

            switch (ch) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    stack[++top] = op1 / op2; break;
                case '%': stack[++top] = op1 % op2; break;
                default: printf("Invalid Operator\n"); return -1;
            }
        }
    }
    return stack[top]; // Final result
}

// Main function
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixtoprefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);
    
    int result = evaluatePrefix(prefix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
