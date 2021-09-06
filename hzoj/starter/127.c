/*************************************************************************
	> File Name: 127.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:30:50 2021
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    printf("%d\n", (int)(x * pow(1.06, n)));
    return 0;
}
