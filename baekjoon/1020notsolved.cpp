#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

int line[10] = { 6,2,5,5,4,5,6,3,7,5 }; // 각 숫자 구성 선분 갯수
int initial_line_num; // 초기 선분 갯수

int current_line_num; // 현시각 선분 갯수
int cnt;
int carry;

int main(void) {
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        initial_line_num += line[S[i] - '0'];
    }

    current_line_num = initial_line_num;
    cnt = 0;
    reverse(S.begin(), S.end());
    do {
        current_line_num -= line[S[0] - '0'];
        S[0] += 1;
        if (S[0] - '0' >= 10) {
            S[0] = '0';
            carry = 1;
        }
        else {
            carry = 0;
        }
        current_line_num += line[S[0] - '0'];
        for (int i = 1; i < S.length(); ++i) {
            if (carry) {
                current_line_num -= line[S[i] - '0'];
                S[i] += 1;
                if (S[i] - '0' >= 10) {
                    S[i] = '0s';
                    carry = 1;
                }
                else {
                    carry = 0;
                }
                current_line_num += line[S[i] - '0'];
            }
            else {
                break;
            }

        }
        if (carry) {
            for (int i = 0; i < S.length(); ++i) {
                S[i] = '0';
            }
            current_line_num = line[0] * S.length();
        }
        cnt++;
        //cout << cnt << " " << S << " " << current_line_num << endl; 
    } while (initial_line_num != current_line_num);
    cout << cnt << endl;
    return 0;
}