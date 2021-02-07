/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2021-01-15 22:56:51  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector 
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int n;
int i;
vi a;

void Solve(void) {
    int lo = 1, hi = n;
    int mid = (hi + lo) / 2;

    printf("? %d", 1);
    scanf("%d", &a[1]);
    printf("? %d", n);
    scanf("%d", &a[n]);

    while (lo < hi) {
        mid = (lo + hi) / 2;
        printf("? %d", mid);
        scanf("%d", &a[mid]);

        if (abs(a[lo] - a[mid]) < abs(a[hi] - a[mid])) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    printf("! %d", mid);
}

void Init(void) {
    scanf("%d", &n);
    a.clear();
    a.resize(n + 1);
}

int main(void) {
    Init();
    Solve();
    return 0;
}