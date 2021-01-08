#include <iostream>

using namespace std;

int N, a, b;
int answer;
int main(void) {
    cin >> N >> a >> b;
    a--;
    b--;
    while (a != b) {
        a /= 2;
        b /= 2;
        answer++;
    }
    cout << answer << endl;
    return 0;
}