/*************************************************************************
	> File Name: calculator.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 16:51:18 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"input.h"
#include"elem_arith.h"
#include"my_pow.h"
#include"my_sqrt.h"
#include"calc.h"
#include"output.h"

#ifdef STD
#define POW pow
#define SQRT sqrt
#else
#define POW my_pow
#define SQRT my_sqrt
#endif

int main() {
    char **exprs;
    int n;
    n = input(&exprs);
    if (n < 0) return n;
    output(exprs, n);

    for (int i = 0; i < n; i++) free(exprs[i]);
    free(exprs);
//    printf("1 + 2 = %d\n", (int)(add(1, 2)));
//    printf("1.5 + 2 = %g\n", (add(1.5, 2)));
//    printf("-1 + 2 = %d\n", (int)(add(-1, 2)));
//    printf("1 - 2 = %d\n", (int)(sub(1, 2)));
//    printf("1.2 - 2 = %g\n", (sub(1.2, 2)));
//    printf("2 - 2 = %d\n", (int)(sub(2, 2)));
//    printf("3 - 2 = %d\n", (int)(sub(3, 2)));
//    printf("-1 - 2 = %d\n", (int)(sub(-1, 2)));
//    printf("3 * 2 = %d\n", (int)(multiply(3, 2)));
//    printf("(-3) * 2 = %d\n", (int)(multiply(-3, 2)));
//    printf("(-3.5) * 2 = %g\n", (multiply(-3.5, 2)));
//    printf("(-3) * (-2) = %d\n", (int)(multiply(-3, -2)));
//    printf("3 / 2 = %g\n", (divide(3, 2)));
//    printf("(-3) / (-2) = %g\n", (divide(-3, -2)));
//    printf("3 / 0 = %g\n", (divide(3, 0)));
//    printf("0 ^ 0 = %lf\n", POW(0, 0));
//    printf("1.1 ^ 0 = %lf\n", POW(1.1, 0));
//    printf("-1.1 ^ 0 = %lf\n", POW(-1.1, 0));
//    printf("NAN ^ 0 = %lf\n", POW(NAN, 0));
//    printf("INF ^ 0 = %lf\n", POW(INFINITY, 0));
//    printf("0 ^ 1 = %lf\n", POW(0, 1));
//    printf("1.1 ^ 1 = %lf\n", POW(1.1, 1));
//    printf("-1.1 ^ 1 = %lf\n", POW(-1.1, 1));
//    printf("NAN ^ 1 = %lf\n", POW(NAN, 1));
//    printf("INF ^ 1 = %lf\n", POW(INFINITY, 1));
//    printf("0 ^ NAN = %lf\n", POW(0, NAN));
//    printf("1.1 ^ NAN = %lf\n", POW(1.1, NAN));
//    printf("-1.1 ^ NAN = %lf\n", POW(-1.1, NAN));
//    printf("NAN ^ NAN = %lf\n", POW(NAN, NAN));
//    printf("INF ^ NAN = %lf\n", POW(INFINITY, NAN));
//    printf("NAN ^ 1.1 = %lf\n", POW(NAN, 1.1));
//    printf("NAN ^ -1.1 = %lf\n", POW(NAN, -1.1));
//    printf("NAN ^ INFINITY = %lf\n", POW(NAN, INFINITY));
//    printf("1.1 ^ INFINITY = %lf\n", POW(1.1, INFINITY));
//    printf("1.1 ^ -INFINITY = %lf\n", POW(1.1, -INFINITY));
//    printf("0.9 ^ INFINITY = %lf\n", POW(0.9, INFINITY));
//    printf("0.9 ^ -INFINITY = %lf\n", POW(0.9, -INFINITY));
//    printf("1 ^ INFINITY = %lf\n", POW(1, INFINITY));
//    printf("-1 ^ INFINITY = %lf\n", POW(-1, INFINITY));
//    printf("-1 ^ -INFINITY = %lf\n", POW(-1, -INFINITY));
//    printf("-1.1 ^ 10 = %lf\n", POW(-1.1, 10));
//    printf("-1.1 ^ 3 = %lf\n", POW(-1.1, 3));
//    printf("-1.1 ^ 1.5 = %lf\n", POW(-1.1, 1.5));
//    printf("1.1 ^ 10 = %lf\n", POW(1.1, 10));
//    printf("1.1 ^ 3 = %lf\n", POW(1.1, 3));
//    printf("1.1 ^ 1.5 = %lf\n", POW(1.1, 1.5));
//    printf("1.1 ^ -1.5 = %lf\n", POW(1.1, -1.5));
//    printf("1.1 ^ -3 = %lf\n", POW(1.1, -3));
//    printf("1.1 ^ -10 = %lf\n", POW(1.1, -10));
//    printf("-1.1 ^ -1.5 = %lf\n", POW(-1.1, -1.5));
//    printf("-1.1 ^ -3 = %lf\n", POW(-1.1, -3));
//    printf("-1.1 ^ -10 = %lf\n", POW(-1.1, -10));
//    printf("INF ^ 1.5 = %lf\n", POW(INFINITY, 1.5));
//    printf("INF ^ 1.5 = %lf\n", POW(INFINITY, 1.5));
//    printf("INF ^ -1.5 = %lf\n", POW(INFINITY, -1.5));
//    printf("-INF ^ 1.5 = %lf\n", POW(-INFINITY, 1.5));
//    printf("-INF ^ -1.5 = %lf\n", POW(-INFINITY, -1.5));
//    printf("10 ^ 10 = %lf\n", POW(10, 10));
//    printf("10 ^ -10 = %lf\n", POW(10, -10));
//    printf("-10 ^ -10 = %lf\n", POW(-10, -10));
//    printf("-10 ^ 10 = %lf\n", POW(-10, 10));
//
//    printf("sqrt(4.0) = %lf\n", SQRT(4.0));
//    printf("sqrt(16.0) = %lf\n", SQRT(16.0));
//    printf("sqrt(123.4) = %lf\n", SQRT(123.4));
//    printf("sqrt(-16.0) = %lf\n", SQRT(-16.0));
    
//    char *test1 = "12.3+23.4*(1.1^3-@5.7)-6.6*7.7";
//    char *test2 = "12.3+ 3^3 - 3.0/ 2 + 23.4*(1.1^3-@5.7)-6.6*7.7";
//    char *test3 = "12^3+@23.4*(1.1^3-@5.7)-6.6*7.7";
//    char *test4 = "12^3++@23.4*(1.1^3-@5.7)-6.6*7.7";
//    char *test5 = "12^3+@23..4*(1.1^3-@5.7)-6.6*7.7";
//    char *test6 = "-12^3+@23.4*(1.1^3-@5.7)-6.6*7.7";
//    printf("%s = %lf\n\n", test1, calc(test1));
//    printf("%s = %lf\n\n", test2, calc(test2));
//    printf("%s = %lf\n\n", test3, calc(test3));
//    printf("%s = %lf\n\n", test4, calc(test4));
//    printf("%s = %lf\n\n", test5, calc(test5));
//    printf("%s = %lf\n\n", test6, calc(test6));

    return 0;
}

