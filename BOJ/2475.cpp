#include <iostream>

using namespace std;

int main(void) {
    int answer = 0;
    for(int i=0; i<5; i++){
        int inp;
        cin >> inp;
        answer += inp*inp;
    }
    cout << answer%10 << endl;

    return 0;
}