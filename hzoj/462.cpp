/*************************************************************************
	> File Name: 462.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 10:52:56 2021
 ************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int n;
int num_male = 0, num_female = 0;
int qq_cnt = 0;
double qq_average = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char id_type;
        char id_num[20];
        cin >> id_type;
        cin >> id_num;
        cout << id_num[strlen(id_num) - 2] << endl;
        if (id_type == 'q') {
            qq_average = (qq_average * qq_cnt + stoi(id_num)) / (qq_cnt + 1);
            qq_cnt += 1;
        } else if(id_type == 'i') {
            if ((id_num[strlen(id_num) - 2] - '0') % 2) {
                num_female += 1;
            } else {
                num_male += 1;
            }
        } 
    }
    cout << num_male << " "<< num_female << " " << (int)qq_average << endl;

    return 0;
}
