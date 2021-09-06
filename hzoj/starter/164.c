/*************************************************************************
	> File Name: 164.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:52:34 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", (int)(ceil((double)n / (double)m)));
    return 0;
}
