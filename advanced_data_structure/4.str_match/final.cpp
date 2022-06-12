/*************************************************************************
	> File Name: 1.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Apr 25 19:58:34 2022
 ************************************************************************/

#include<stdlib.h>
#include<string.h>
using namespace std;

int quick_mod(int a, int b, int c) {
    int ans = 1, tmp = a;
    while (b) {
        if (b & 1) ans = ans * tmp % c;
        tmp = tmp * tmp % c;
        b >>= 1;
    }
}

int brute_one_match(const char *s, const char *t) {
    for (int j = 0; t[j]; j++) {
        if (s[j] == t[j]) continue;
        return 0;
    }
    return 1;
}

int *getNext(const char* t, int *n) {
    int len = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (*n));  // current position match fail then jump here
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;

    }
    return next;

}

int kmp(const char *s, const char *t) {
    int len = strlen(t);
    int *next = getNext(t, &len);
    for (int i = 0, j = -1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == '\0') {
            free(next);
            return i - len + 1;
        }
    }
    free(next);
    return -1;
}

int hash_match(const char *s, const char *t) {
    int len = strlen(t), base = 31, P = 9973, nbase = quick_mod(base, len, P);
    int h = 0, th = 0;
    for (int i = 0; t[i]; i++) th = (th * base + t[i]) % P;
    for (int i = 0; s[i]; i++) {
        h = (h * base + s[i]) % P;
        if (i >= len) h = (h - (s[i - len] * nbase % P) + P) % P;
        if (i + 1 < len) continue;
        if (h != th) continue;
        if (brute_one_match(s + i - len + 1, t)) return i - len + 1;
    }
    return -1;
}
