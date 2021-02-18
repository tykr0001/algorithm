#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0 => init, 1 => '['
int state = 0;
int cnt = 0;
string str;
string answer;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        switch (state) {
        case 0:
            if (str[i] == '[') {
                state = 1;
                cnt++;
            }
            else{
                answer += str[i];
            }
            break;
        case 1:
            if(str[i] == '[') {
                cnt++;
            }
            else if(str[i] == ']') {
                cnt--;
                if(cnt == 0){
                    state = 0;
                }
            }
            break;
        default:
            break;
        }
    }
    cout << answer;
    return 0;
}