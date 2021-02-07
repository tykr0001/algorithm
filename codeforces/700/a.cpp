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

int t;
string str;

// 0 => alice , 1 => bob
int flag;

void Solve(void) {
    for(int i=0; i<str.length(); i++){
        if(flag == 0){
            if(str[i] != 'a'){
                str[i] = 'a';
            }
            else{
                str[i] = 'b';
            }
            flag = 1;
        }
        else{
            if(str[i] != 'z'){
                str[i] = 'z';
            }
            else{
                str[i] = 'y';
            }
            flag = 0;
        }
    }

    cout << str << endl;
}

void Init(void) {
    cin >> str;
    flag = 0;
}

int main(void) {
    Boost;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}