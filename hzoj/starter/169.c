/*************************************************************************
	> File Name: 169.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 09:52:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int N;
    char dict[26];
    int dict_num[26];
    char key[30];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        getchar();
        scanf("%c", &dict[i]);
        scanf("%d", &dict_num[i]);
    }
    scanf("%s", key);
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        for (int j = 0; j < strlen(dict); j++) {
            if (key[i] == dict[j])  {
                sum += dict_num[j];
                break;
           }
        }
    }
    printf("%d\n", sum);
    
    return 0;
}
