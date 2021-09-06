/*************************************************************************
	> File Name: 151.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 26 15:08:41 2021
 ************************************************************************/

#include<stdio.h>

int single_hand(char ming, char lihua) {
    if (ming == lihua) return 0;
    if (ming == 'Y' && lihua == 'H'
        || ming == 'O' && lihua == 'Y'
        || ming == 'H' && lihua =='O') return 1;
    return -1;
}
int main() {
    char ming_left, ming_right, lihua_left, lihua_right;
    scanf("%c %c", &ming_left, &ming_right);
    getchar();
    scanf("%c %c", &lihua_left, &lihua_right);
    int ming_left_lihua_left = single_hand(ming_left, lihua_left);
    if (ming_left_lihua_left == 1) {
        int ming_left_lihua_right = single_hand(ming_left, lihua_right);
        if (ming_left_lihua_right != -1) {
            printf("MING\n");
            return 0;
        }
        int ming_right_lihua_right = single_hand(ming_right, lihua_right);
        if (ming_right_lihua_right == 1) {
            printf("MING\n");
            return 0;
        }
    }
    if (ming_left_lihua_left == 0) {
        int ming_right_lihua_right = single_hand(ming_right, lihua_right);
        if (ming_right_lihua_right == 1) {
            printf("MING\n");
            return 0;
        }
        if (ming_right_lihua_right == 0) {
            printf("TIE\n");
            return 0;
        }
    }
    if (ming_left_lihua_left == -1) {
        int ming_right_lihua_left = single_hand(ming_right, lihua_left);
        int ming_right_lihua_right = single_hand(ming_right, lihua_right);
        if (ming_right_lihua_left == 1 && ming_right_lihua_right != -1) {
            printf("MING\n");
            return 0;
        } 
    }
    printf("LIHUA\n");
    return 0;
}
