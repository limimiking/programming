/*************************************************************************
	> File Name: 181.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 02:15:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char str[10000];
    scanf("%[^\n]s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
    }
    printf("%s\n", str);
    return 0;
}
