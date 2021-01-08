#include <iostream>
#include <cmath>

using namespace std;

int N, K;
int b[50];
int init;
int answer;

//10 000 000
//2^10 * 2^10 * 2^4
int main(void) {
    cin >> N >> K;
    
    int tmp = N;
    for (int i = 0; i < 50 && tmp > 0; i++) {
        b[i] = tmp % 2;
        init += b[i];
        tmp /= 2;
    }

    if (init <= K) {
        cout << 0 << endl;
    }
    else {
        int cnt = 0;
        int idx;
        for (int i = 49; i >= 0; i--) {
            if (b[i]) {
                cnt++;
            }
            if (K == cnt) {
                idx = i;
                break;
            }
        }

        answer = 1;
        for (int i = 0; i < idx; ++i) { 
            if (b[i] == 0) {
                answer += pow(2, i);
            }
        }
        cout << answer << endl;
    }
    return 0;
}