/*************************************************************************
	> File Name: 124.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:04:16 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int education, rank, age, work;
    scanf("%d%d%d%d", &education, &rank, &age, &work);
    if ((rank <= 50 || education >= 1) && (age <= 25 || work >= 5))
        printf("ok\n");
    else
        printf("pass\n");
    return 0;
}
