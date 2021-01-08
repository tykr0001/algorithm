#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    string answer;
    if (m == 0) {
        cout << 0;
        return 0;
    }
    while (m) {
        int tmp = m % n;
        switch (tmp) {
        case 10:
            answer += 'A';
            break;
        case 11:
            answer += 'B';
            break;
        case 12:
            answer += 'C';
            break;
        case 13:
            answer += 'D';
            break;
        case 14:
            answer += 'E';
            break;
        case 15:
            answer += 'F';
            break;
        default:
            answer += tmp + '0';
            break;
        }
        m /= n;
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}