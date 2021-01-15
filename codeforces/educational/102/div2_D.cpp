#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long
#define pb push_back
#define Mid ((L+R)/2)
#define pi pair<int,int>
#define pii pair<pi,int>
#define deb(x) cout<<#x<<"="<<x<<endl
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
string s;
int t, n, m, mn[200200], mx[200200], pre[200200], mx1[200200], mn1[200200];
int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        s = '#' + s;
        mx1[n + 1] = mn1[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (s[i] == '+') - (s[i] == '-');
            mn[i] = min(mn[i - 1], pre[i]);
            mx[i] = max(mx[i - 1], pre[i]);
        }
        for (int i = n; i > 0; i--) {
            mx1[i] = mx1[i + 1];
            mn1[i] = mn1[i + 1];
            if (s[i] == '+') {
                mn1[i]++;
                mx1[i]++;
            }
            else {
                mn1[i]--;
                mx1[i]--;
            }
            if (mn1[i] > 0)
                mn1[i] = 0;
            if (mx1[i] < 0)
                mx1[i] = 0;
        }
        while (m--) {
            int l, r;
            cin >> l >> r;
            int Mx = mx[l - 1];
            int Mn = mn[l - 1];
            int Pre = pre[l - 1];
            Mx = max(Mx, Pre + mx1[r + 1]);
            Mn = min(Mn, Pre + mn1[r + 1]);
            Mx = max(0, Mx);
            Mn = min(0, Mn);
            //deb(Mx-Mn+1);
            cout << Mx - Mn + 1 << endl;
        }
    }
    return 0;
}