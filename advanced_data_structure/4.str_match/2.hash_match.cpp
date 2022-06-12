/*************************************************************************
	> File Name: 1.brute_match.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Apr 26 11:10:30 2022
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 10000
#define DEFAULT_LEN 40
char s[MAX_N + 5], t[MAX_N + 5];

#define TEST(func) { \
    printf("--------------\n"); \
    char temp_s[MAX_N + 5]; \
    sprintf(temp_s, "%s(\"%s\", \"%s\") = %3d\n", #func, s, t, func(s, t)); \
    int n = DEFAULT_LEN - strlen(temp_s); \
    while (n-- >= 0) printf(" "); \
    printf("%s", temp_s); \
}

bool brute_one_match(const char *s, const char *t) {
    printf("brute_one_match called to match %s and %s\n", s, t);
    for (int i = 0; t[i]; i++) {
        if (s[i] != t[i]) return false;
    }
    printf("match success\n");
    return true;
}

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        if (brute_one_match(s + i, t)) return i;
    }
    return -1;
}

int quick_mod(int a, int b, int c) {
    // a ** b % c
    int ans = 1, tmp = a;
    while (b) {
        if (b & 1) ans = ans * tmp % c;
        tmp = tmp * tmp % c;
        b >>= 1;
    }
    return ans;
}

int hash_match(const char *s, const char *t) {
    int len = strlen(t), base = 31, P = 9973, nbase = quick_mod(base, len, P);
    int h = 0, th = 0;
    for (int i = 0; t[i]; i++) th = (th * base + t[i]) % P;
    
    for (int i = 0; s[i]; i++) {
        h = (h * base + s[i]) % P;
        if (i >= len) h = (h - (s[i - len] * nbase % P) + P) % P; 
        if (i + 1 < len) continue;
        // i == len - 1
        if (h != th) continue;
        // h == th, start brute match
        if (brute_one_match(s + i - len + 1, t)) return i - len + 1;
        // note: anchor is on the end of window
    }
    return -1;
}

int main() {
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force);
        TEST(hash_match);
    }
//    printf("%c|%c|%c|%c\n", s[1], s[4], s[5], s[6]);

    return 0;
}

