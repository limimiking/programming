/*************************************************************************
	> File Name: 175.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jun 30 11:15:58 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int N;
    int score;
    int You = 0, Liang = 0, Zhong = 0, Cha = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &score);
        if (score >= 90 && score <= 100) You++;
        if (score >= 80 && score <= 89) Liang++;
        if (score >= 60 && score <= 79) Zhong++;
        if (score < 60) Cha++;
    }
    printf("You %d\nLiang %d\nZhong %d\nCha %d\n", You, Liang, Zhong, Cha);
    return 0;
}
