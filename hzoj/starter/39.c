/*************************************************************************
	> File Name: 39.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 16:49:48 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int begin, n;
    scanf("%d%d", &begin, &n);
    if (begin < 0) begin = 0;
    if (begin & 1) begin += 1;
    for (int i = 0; i < n; i++) printf("%d\n", begin + 2 * i);
    return 0;
}
