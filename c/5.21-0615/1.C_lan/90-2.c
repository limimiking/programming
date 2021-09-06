/*************************************************************************
	> File Name: 90-2.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 19:40:38 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    char num[12];
    scanf("%s",num);
    for (int i = 0; i < strlen(num); i++) {
        printf("%c\n", num[i]);
    }
    return 0;
}
