/*************************************************************************
	> File Name: 266.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 10 Sep 2021 04:36:15 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main () {
	stack<char> s_opt;
	stack<int> s_num;
	string expr;
	cin >> expr;
	for (char ch : expr) {
		switch (ch) {
			case '(':
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				s_opt.push(ch);
				break;
				

		}

	}
	
    return 0;
}
