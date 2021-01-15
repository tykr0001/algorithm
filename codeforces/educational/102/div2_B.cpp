#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

typedef long long LL;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        string a;
        string b;
        string multi_a;
        string multi_b;
        cin >> a >> b;
        int len_a = a.length();
        int len_b = b.length();
        int lcd = len_a * len_b / gcd(len_a, len_b);
        for (int i = 0; i < lcd / len_a; i++) {
            multi_a += a;
        }
        for (int i = 0; i < lcd / len_b; i++) {
            multi_b += b;
        }

        if (multi_a == multi_b) {
            cout << multi_a << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}