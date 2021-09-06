/*************************************************************************
	> File Name: 182.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 02:29:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main() {
    int n;
    int largest = INT32_MIN;
    int tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp > largest) largest = tmp;
    }
    printf("%d\n", largest);
    return 0;
}
