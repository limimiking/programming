/*************************************************************************
	> File Name: 477.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri Jun 18 14:13:37 2021
 ************************************************************************/

#include<iostream>
using namespace std;

int is_vowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int main() {
    char str[105];
    int ans = 0, last = -1;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (is_vowel(str[i])) {
            if (last == -1) {
                last = i;
            } else {
                ans = max(ans, i - last);
                last = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
