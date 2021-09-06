/*************************************************************************
	> File Name: 176.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jun 30 11:26:18 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char nvdi[1005], lufei[1005];
    char *cursor = nvdi;
    char *find;
    int cnt = 0;
    scanf("%[^\n]s", nvdi);
    getchar();
    scanf("%[^\n]s", lufei);
    while((find = strstr(cursor, lufei)) != NULL) {
        cnt++;
        cursor = find + 1;
//        if (cursor > nvdi + strlen(nvdi) - 1) break;
    }
    printf("%d\n", cnt);
    return 0;
}
