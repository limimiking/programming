/*************************************************************************
	> File Name: 145.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 19:59:58 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int N;
    int longest = 0;
    char name[105] = {0};
    char longest_name[105] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        if (strlen(name) > longest) {
            strcpy(longest_name, name);
            longest = strlen(name);
        }
    }
    printf("%s\n", longest_name);
    return 0;
}
