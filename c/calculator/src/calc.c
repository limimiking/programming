/*************************************************************************
	> File Name: src/calc.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jul  5 15:35:22 2021
 ************************************************************************/

#include<stdio.h>
#include"calc.h"

#ifdef DEBUG
#define CAT(a, b) strncat(a, &b, 1), printf("%c\n", b)
#else
#define CAT(a, b) strncat(a, &b, 1)
#endif

int push(char *stack, int top, char elem) {
    stack[++top] = elem;
    #ifdef DEBUG
    printf("push %c\n", elem);
    #endif
    return top;
}

int pop(char *stack, int top, char *output) {
    if (top == -1) return -1;
    *output = stack[top];
    top--;
    #ifdef DEBUG
    printf("pop %c\n", *output);
    #endif
    return top;
}

int prior_op(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '@':
            return 3;
    }
    return 0;
}

int got_oper(char ch, char *s_operator, int s_operator_top, char *postfix) {
    char tmp;
    if (ch == '(') {
        s_operator_top = push(s_operator, s_operator_top, ch);
        return s_operator_top;
    }
    if (ch == ')') {
        while(1) {
            s_operator_top = pop(s_operator, s_operator_top, &tmp);
            if (tmp == '(') break;
            CAT(postfix, tmp);
        }
        return s_operator_top;
    } 
    while(1) {
        char op_top = s_operator[s_operator_top];
        if (op_top == '(' || s_operator_top == -1 || prior_op(ch) > prior_op(op_top)) {
            s_operator_top = push(s_operator, s_operator_top, ch);
            break;
        } else {
            s_operator_top = pop(s_operator, s_operator_top, &tmp); 
            CAT(postfix, tmp);
        }
    }
    return s_operator_top;
}

void trans(char *infix, char *postfix) {
    char s_operator[EXPR_MAX_LENGTH];
    int s_operator_top = -1;
    char ch;
    char tmp;
    char sep = '#';
    for (int i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        #ifdef DEBUG
        printf("got %c\n", ch);
        #endif
        switch(ch) {
            case ' ':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '@':
                CAT(postfix, sep);
            case '(':
            case ')':
                s_operator_top = got_oper(ch, s_operator, s_operator_top, postfix);
                break;
            default:
                CAT(postfix, ch);
                break;
        }
    }
    while(s_operator_top >= 0) {
        s_operator_top = pop(s_operator, s_operator_top, &tmp);
        CAT(postfix, tmp);
    }
    CAT(postfix, sep);
}

double calc_postfix(char *postfix) {
    double tmp = 0;
    double stack[EXPR_MAX_LENGTH];
    int top = -1;
    int decimal_state = 0; //0:begin 1:int 2:decimal
    int decimal_bits = 0;
    double num1, num2;
    for (int i = 0; i < strlen(postfix); i++) {
        #ifdef DEBUG
        printf("got %c\n", postfix[i]);
        #endif
        switch (postfix[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '#':
            case '@':
                if (decimal_state) {
                    for (int i = 0; i < decimal_bits; i++) tmp /= 10;
                    stack[++top] = tmp;
                    #ifdef DEBUG
                    printf("push %lf\n", tmp);
                    #endif
                    decimal_state = 0;
                    tmp = 0;
                    decimal_bits = 0;
                }
                break;
        }
        switch (postfix[i]) {
            case '.':
                if (decimal_state == 1) decimal_state = 2;
                else if (decimal_state == 2) {
                    printf("wrong expr!\n");
                    return NAN;
                }
                break;
            case '#':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                num1 = stack[top--];
                #ifdef DEBUG
                printf("pop to num1 %lf\n", num1);
                #endif
                if (top < 0) {
                    printf("%c wrong expr!\n", postfix[i]);
                    return NAN;
                }
                num2 = stack[top--]; 
                #ifdef DEBUG
                printf("pop to num2 %lf\n", num2);
                #endif
                if (postfix[i] == '^') {
                    stack[++top] = my_pow(num2, num1);
                } else stack[++top] = elem_arith(num2, num1, postfix[i]);
                #ifdef DEBUG
                printf("push %lf\n", stack[top]);
                #endif
                break;
            case '@':
                if (top < 0) {
                    printf("%c wrong expr!\n", postfix[i]);
                    return NAN;
                }
                num1 = stack[top--];
                #ifdef DEBUG
                printf("pop to num 1 %lf\n", num1);
                #endif
                stack[++top] = my_sqrt(num1);
                #ifdef DEBUG
                printf("push %lf\n", stack[top]);
                #endif
                break;
            default:
                if (postfix[i] < '0' || postfix[i] > '9') {
                    printf("unknown operator!\n");
                    return NAN;
                }
                if (decimal_state == 0) decimal_state = 1;
                if (decimal_state == 2) decimal_bits += 1;
                tmp = tmp * 10.0 + 1.0 * (postfix[i] - '0');
                break;
        }
    }
    return stack[top];
}
double calc(char *expr) {
    char postfix[EXPR_MAX_LENGTH] = {0};
    trans(expr, postfix);
    #ifdef DEBUG
    printf("%s\n", postfix);
    #endif
    return calc_postfix(postfix);
}
