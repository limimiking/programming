/*************************************************************************
	> File Name: 118.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jul 12 16:57:49 2021
 ************************************************************************/

#include<stdio.h>

char zodiac[12][20] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};

int main() {
    int year;
    scanf("%d", &year);
    year -= 1900;
    year %= 12;
    year = year >= 0 ? year : 12 + year;
    printf("%s\n", zodiac[year]);
    return 0;
}
