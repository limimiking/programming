/*************************************************************************
	> File Name: 265.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 08 Sep 2021 08:45:11 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

bool pairs(char l, char r) {
    if (l == '(' && r == ')') return true;
    if (l == '[' && r == ']') return true;
    if (l == '{' && r == '}') return true;
    return false;
}

int main() {
    int max_length = 0;
    stack<int> s;
    string brackets;
    cin >> brackets;
    brackets = "x" + brackets;
    s.push(0);

    for (int i = 1; i <= brackets.length(); i++) {
        char c = brackets[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(i);
        }
        else if (pairs(brackets[s.top()], c)) {
            s.pop();
            max_length = max(i - s.top(), max_length);
        } else {
            s.push(i);
        }
    }
    cout << max_length <<endl;

    return 0;
}
