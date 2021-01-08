#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
int answer;
vector<int> A;
vector<int> B;

int main(void) {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        answer += A[i] * B[i];
    }
    cout << answer << endl;
}