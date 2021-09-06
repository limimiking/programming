/*************************************************************************
	> File Name: 178.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 30 Jun 2021 04:22:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int N;
    char str[1050000] = {0}, tmp[1050000];
    char ch = 'A';
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        sprintf(tmp, "%s%c%s", str, ch++, str);
        strcpy(str, tmp);
    }
    printf("%s\n", str);

    
    return 0;
}
