#include<bits/stdc++.h>
 
using namespace std;

#define F first
#define S second
#define ll long long
#define pb push_back
#define Mid ((L+R)/2)
#define pi pair<int,int>
#define pii pair<pi,int>
#define deb(x) cout<<#x<<"="<<x<<endl
#define boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

typedef long long LL;

int main() {
    boost;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 1)cout << 1 <<'\n';
        else {
            int i;
            for (i = 1; i <= (2 * k - n - 1); i++) {
                cout << i << " ";
            }
            int h = k - i + 1;
            while (h > 0) {
                cout << k << " ";
                k--;
                h--;
            }
            cout << endl;
        }
    }
}
