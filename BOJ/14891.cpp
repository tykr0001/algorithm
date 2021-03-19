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
\*************  2021-03-17 04:42:59  *************/

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
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

vi gear(4);
int K;

void Rotate(int idx, int clockwise) {
    if (clockwise == 1) {
        int tmp = gear[idx] & 0b1;
        gear[idx] >>= 1;
        gear[idx] |= (tmp << 7);
    }
    else {
        int tmp = gear[idx] >> 7;
        gear[idx] <<= 1;
        gear[idx] |= tmp;
    }
    gear[idx] &= 0b11111111;
}

bool IsSamePolar(int i, int j) {
    return 0b1 & ~((gear[i] >> 5) ^ (gear[j] >> 1));
}

void Solve(void) {
    rep(i, 0, K) {
        int idx, op;
        cin >> idx >> op;
        idx--;
        switch (idx) {
        case 0:
            if (!IsSamePolar(0, 1)) {
                if (!IsSamePolar(1, 2)) {
                    if (!IsSamePolar(2, 3)) {
                        Rotate(3, -op);
                    }
                    Rotate(2, op);
                }
                Rotate(1, -op);
            }
            Rotate(0, op);
            break;

        case 1:
            if (!IsSamePolar(0, 1)) {
                Rotate(0, -op);
            }
            if (!IsSamePolar(1, 2)) {
                if (!IsSamePolar(2, 3)) {
                    Rotate(3, op);
                }
                Rotate(2, -op);
            }
            Rotate(1, op);
            break;

        case 2:
            if (!IsSamePolar(2, 3)) {
                Rotate(3, -op);
            }
            if (!IsSamePolar(1, 2)) {
                if (!IsSamePolar(0, 1)) {
                    Rotate(0, op);
                }
                Rotate(1, -op);
            }
            Rotate(2, op);
            break;

        case 3:
            if (!IsSamePolar(2, 3)) {
                if (!IsSamePolar(1, 2)) {
                    if (!IsSamePolar(0, 1)) {
                        Rotate(0, -op);
                    }
                    Rotate(1, op);
                }
                Rotate(2, -op);
            }
            Rotate(3, op);
            break;

        default:
            break;
        }
    }
    cout << (gear[0] >> 7) * 1 + (gear[1] >> 7) * 2 + (gear[2] >> 7) * 4 + (gear[3] >> 7) * 8 << endl;
}

void Init(void) {
    rep(i, 0, 4) {
        string str;
        cin >> str;
        gear[i] = stoi(str, nullptr, 2);
    }
    cin >> K;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}