/*************************************************************************
	> File Name: 167.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 09:09:02 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char A[10005];
    int N;
    char B[10005];
    scanf("%s", A);
    scanf("%d", &N);
    scanf("%s", B);
    char tmp[10005] = {0};
    strncpy(tmp, A + N - 1, strlen(A) - N + 1);
    char output[20005] = {0};
    strncpy(output, A, N - 1);
    strcat(output, B);
    strcat(output, tmp);
    int cursor = 0;
    for (cursor = 0; A[cursor] != 'a'; cursor++);
    cursor += 1;
    printf("%d\n", (int)strlen(A));
    printf("%d\n", cursor);
    printf("%s\n", output);
    return 0;
}
