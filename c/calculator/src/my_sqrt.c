/*************************************************************************
	> File Name: my_sqrt.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 05 Jul 2021 12:33:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include"my_sqrt.h"

double my_sqrt(double x) {
    if (x < 0) return NAN;
    double root = x, last;
    do {
        last = root;
        root = (root + x / root) / 2;
    } while (fabs(root - last) > 1e-6);
    return root;
    
}
