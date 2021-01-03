#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<tuple<int, int>> A(N); // tuple<val,idx>
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A[i] = make_tuple(tmp, i);
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i) {
        B[get<1>(A[i])] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }

    return 0;
}