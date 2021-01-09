#include <bits/stdc++.h>

using namespace std;

int N, Q;
string S;
int x, y;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    cin >> S;

    int L = 0;
    int U = 0;
    int R = 0;
    int D = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'D') {
            D++;
        }
        else if (S[i] == 'U') {
            U++;
        }
        else if (S[i] == 'R') {
            R++;
        }
        else {
            L++;
        }
    }
    while (Q--) {
        cin >> x >> y;
        if (abs(int(S.length() - (x + y))) % 2 || abs(x) + abs(y) > S.length()) {
            cout << -1 << '\n';
            continue;
        }
        int l = L;
        int u = U;
        int r = R;
        int d = D;

        if (x > 0) {
            r -= x;
        }
        else {
            l += x;
        }
        if (y > 0) {
            u -= y;
        }
        else {
            d += u;
        }

        int a = abs(u - d);
        int b = abs(l - r);

        int answer = 0;

        if (u + d < 0) {
            if (u < 0 && d < 0) {
                if(abs(u + d) < abs(l - r)){
                    if(l>r){
                        l-=abs(u + d);
                        cout << abs(u + d) + abs(l - ((l + r) / 2)) << '\n';
                    }
                    else{
                        r-=abs(u + d);
                        cout << abs(u + d) + abs(r - ((l + r) / 2)) << '\n';
                    }
                }
                else{
                    cout << abs(u + d) << '\n';
                }
            }
            else {
                if(abs(u + d) < abs(l - r)){
                    if(l>r){
                        l-=abs(u + d);
                        cout << min(abs(u), abs(d)) + abs(u + d) + abs(l - ((l + r) / 2)) << '\n';
                    }
                    else{
                        r-=abs(u + d);
                        cout << min(abs(u), abs(d)) + abs(u + d) + abs(r - ((l + r) / 2)) << '\n';
                    }
                }
                else{
                    cout << min(abs(u), abs(d)) + abs(u + d) << '\n';
                }
            }
            continue;
        }
        if (u + d < 0) {
            if (l < 0 && r < 0) {
                if(abs(l + r) < abs(u - d)){
                    if(u>d){
                        u-=abs(l + r);
                        cout << abs(l + r) + abs(u - ((u + d) / 2)) << '\n';
                    }
                    else{
                        d-=abs(l + r);
                        cout << abs(l + r) + abs(d - ((u + d) / 2)) << '\n';
                    }
                }
                else{
                    cout << abs(l + r) << '\n';
                }
            }
            else {
                if(abs(l + r) < abs(u - d)){
                    if(u>d){
                        u-=abs(l + r);
                        cout << min(abs(l), abs(r)) + abs(l + r) + abs(u - ((u + d) / 2)) << '\n';
                    }
                    else{
                        d-=abs(l + r);
                        cout << min(abs(l), abs(r)) + abs(l + r) + abs(d - ((l + d) / 2)) << '\n';
                    }
                }
                else{
                    cout << min(abs(l), abs(r)) + abs(u + r) << '\n';
                }
            }
            continue;
        }

        if (a % 2 == 1) {
            cout << abs(u - d) / 2 + abs(l - r) / 2 + 1 << '\n';
        }
        else {
            cout << abs(u - d) / 2 + abs(l - r) / 2 << '\n';
        }

    }
}