/*************************************************************************
	> File Name: 166.c
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
    int cnt = 1;
    for (int cursor = strlen(output) - 1; output[cursor] != 'x'; cursor--) cnt += 1;
    printf("%d\n", (int)strlen(A) > 100 ? 100 : (int)strlen(A));
    printf("%s\n", output);
    printf("%d\n", cnt);
    return 0;
}
