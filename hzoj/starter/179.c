/*************************************************************************
	> File Name: 179.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 30 Jun 2021 04:47:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double x = 0, y;
    double l = -20, r = 20;
    while (fabs(y = func(p, q, x)) >= EPSILON) {
        double y_l = func(p, q, l), y_r = func(p, q, r);
        if (y * y_l > 0) l = x;
        if (y * y_r > 0) r = x;
        x = (l + r) / 2;
    }
    return x;

}

double f(int p, int q, double x) {
    return p * x + q;
}
