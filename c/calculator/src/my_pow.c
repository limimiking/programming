/*************************************************************************
	> File Name: pow.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun 04 Jul 2021 08:25:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include"my_pow.h"

double my_pow(double x, double y) {
    if (y == 0) return 1.0;
    if (y == 1) return x;
    if (x == 1) return 1.0;
    if (isnan(y)) return NAN;
    if (isnan(x)) return NAN;
    if (fabs(x) > 1 && y > 0 && isinf(y)) return INFINITY;
    if (fabs(x) > 1 && y < 0 && isinf(y)) return 0.0;
    if (fabs(x) < 1 && y > 0 && isinf(y)) return 0.0;
    if (fabs(x) < 1 && y < 0 && isinf(y)) return INFINITY;
    if (x == -1 && isinf(y)) return 1.0;
    if (x == 0 && y > 0) return 0.0;
    if (x == 0 && y < 0) return INFINITY;
    if (isinf(x) && y > 0) return INFINITY;
    if (isinf(x) && y < 0) return 0.0;
    if (x < 0 && fmod(y, 1.0) == 0.0) return (int)y & 1 ? -my_pow(-x, y) : my_pow(-x, y);
    if (x < 0 && fmod(y, 1.0) != 0.0) return NAN;
    return exp(y * log(x));
}
