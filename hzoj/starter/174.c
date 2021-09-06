/*************************************************************************
	> File Name: 174.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jun 30 10:14:35 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void strrp(char *src, char *sub, char *rp, char *dst) {
    int sub_length = strlen(sub);
    char *cursor = src;
    char *find = NULL; 
    while ((find = strstr(cursor, sub)) != NULL) {
        strncat(dst, cursor, find - cursor);
        strcat(dst, rp);
        cursor = find + sub_length;
    }
    strcat(dst, cursor);
}
int main() {
    char url[1000005] = {0}; 
    char new_url[3000005] = {0};
    scanf("%[^\n]s", url);
    strrp(url, " ", "%20", new_url); 
    printf("%s\n", new_url);
    return 0;
}
