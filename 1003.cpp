#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;

ll arr_0[41];
ll arr_1[41];
ll fibo[41];

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (fibo[n]) {
        return fibo[n];
    }
    else {
        fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        arr_0[n] = arr_0[n - 1] + arr_0[n - 2];
        arr_1[n] = arr_1[n - 1] + arr_1[n - 2];
        return fibo[n];
    }
}

int main(void) {
    int T;
    cin >> T;
    vector<int> cases(T);
    arr_0[0] = 1;
    arr_1[0] = 0;
    arr_0[1] = 0;
    arr_1[1] = 1;
    while (T--) {
        int n;
        cin >> n;
        fibonacci(n);
        cout << arr_0[n] << " " << arr_1[n] << endl;
    }
    return 0;
}