/*************************************************************************
	> File Name: elem_arith.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 17:47:27 2021
 ************************************************************************/

#include<stdio.h>
#include"elem_arith.h"

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b; 
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
}

double elem_arith(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("error, %g can't divide %g\n", a, b);
                return NAN;
            }
            return a / b;
    }
}
