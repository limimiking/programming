/*************************************************************************
	> File Name: 104.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 11:46:44 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char a[5] = "";
    int has_9 = 0;
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '9')
            has_9 = 1;
    }
    if (has_9) printf("YES\n");
    else printf("NO\n");
    return 0;

}
