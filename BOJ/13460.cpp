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
\*************  2021-02-06 05:05:36  *************/

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

int N, M;
v<string> board;
int answer;

void DFS(v<string> cur_board, int depth, int op) {
    if (depth == 10) {
        return;
    }
    bool is_blue_dropped = false;
    switch (op) {
    case 0: //left
        for (int i = 1; i < N - 1; i++) {
            int idx = 1;
            bool hole = false;
            for (int j = 1; j < M - 1; j++) {
                if (cur_board[i][j] == 'R') {
                    if (hole) {
                        cur_board[i][j] == '.';
                    }
                    else if (cur_board[i][idx] == 'R' || cur_board[i][idx] == 'B') {
                        if (idx != j) {
                            idx++;
                            while (cur_board[i][idx] == '#' && idx < M - 1) {
                                idx++;
                            }
                            if (idx != j) {
                                cur_board[i][idx] == 'R';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[i][idx] = '.') {
                        cur_board[i][idx] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx++;
                        while (cur_board[i][idx] == '#' && idx < M - 1) {
                            idx++;
                        }
                    }
                }

                if (cur_board[i][j] == 'B') {
                    if (hole) {
                        is_blue_dropped = true;
                        break;
                    }
                    else if (cur_board[i][idx] == 'R' || cur_board[i][idx] == 'B') {
                        if (idx != j) {
                            idx++;
                            while (cur_board[i][idx] == '#' && idx < M - 1) {
                                idx++;
                            }
                            if (idx != j) {
                                cur_board[i][idx] == 'B';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[i][idx] = '.') {
                        cur_board[i][idx] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx++;
                        while (cur_board[i][idx] == '#' && idx < M - 1) {
                            idx++;
                        }
                    }
                }

                if (cur_board[i][j] == 'O') {
                    hole = true;
                }

                if(cur_board[i][j] == '#') {
                    idx = j + 1;
                }
            }
            if (is_blue_dropped)
                break;
        }
        break;

    case 1: //right
        for (int i = N - 2; i > 0; i--) {
            int idx = M - 2;
            bool hole = false;
            for (int j = M - 2; j > 0; j--) {
                if (cur_board[i][j] == 'R') {
                    if (hole) {
                        cur_board[i][j] == '.';
                    }
                    else if (cur_board[i][idx] == 'R' || cur_board[i][idx] == 'B') {
                        if (idx != j) {
                            idx--;
                            while (cur_board[i][idx] == '#' && idx > 0) {
                                idx--;
                            }
                            if (idx != j) {
                                cur_board[i][idx] == 'R';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[i][idx] = '.') {
                        cur_board[i][idx] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx--;
                        while (cur_board[i][idx] == '#' && idx > 0) {
                            idx--;
                        }
                    }
                }
                if (cur_board[i][j] == 'B') {
                    if (hole) {
                        is_blue_dropped = true;
                        break;
                    }
                    else if (cur_board[i][idx] == 'R' || cur_board[i][idx] == 'B') {
                        if (idx != j) {
                            idx--;
                            while (cur_board[i][idx] == '#' && idx > 0) {
                                idx--;
                            }
                            if (idx != j) {
                                cur_board[i][idx] == 'B';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[i][idx] = '.') {
                        cur_board[i][idx] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx--;
                        while (cur_board[i][idx] == '#' && idx > 0) {
                            idx--;
                        }
                    }
                }
                if (cur_board[i][j] == 'O') {
                    hole = true;
                }
                
                if(cur_board[i][j] == '#') {
                    idx = j - 1;
                }
            }
            if (is_blue_dropped)
                break;
        }
        break;

    case 2: //up
        for (int j = 1; j < M - 1; j++) {
            int idx = 1;
            bool hole = false;
            for (int i = 1; i < N - 1; i++) {
                if (cur_board[i][j] == 'R') {
                    if (hole) {
                        cur_board[i][j] == '.';
                    }
                    else if (cur_board[idx][j] == 'R' || cur_board[idx][j] == 'B') {
                        if (idx != i) {
                            idx++;
                            while (cur_board[idx][j] == '#' && idx < N - 1) {
                                idx++;
                            }
                            if (idx != i) {
                                cur_board[idx][j] == 'R';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[idx][j] == '.') {
                        cur_board[idx][j] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx++;
                        while (cur_board[idx][j] == '#' && idx < N - 1) {
                            idx++;
                        }
                    }
                }
                if (cur_board[i][j] == 'B') {
                    if (hole) {
                        is_blue_dropped = true;
                        break;
                    }
                    else if (cur_board[idx][j] == 'R' || cur_board[idx][j] == 'B') {
                        if (idx != j) {
                            idx++;
                            while (cur_board[idx][j] == '#' && idx < N - 1) {
                                idx++;
                            }
                            if (idx != i) {
                                cur_board[idx][j] == 'B';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[idx][j] == '.') {
                        cur_board[idx][j] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx++;
                        while (cur_board[idx][j] == '#' && idx < N - 1) {
                            idx++;
                        }
                    }
                }
                if (cur_board[i][j] == 'O') {
                    hole = true;
                }
                
                if(cur_board[i][j] == '#') {
                    idx = i + 1;
                }
            }
            if (is_blue_dropped)
                break;
        }
        break;

    case 3: //down
        for (int j = M - 2; j > 0; j--) {
            int idx = N - 2;
            bool hole = false;
            for (int i = N - 2; i > 0; i--) {
                if (cur_board[i][j] == 'R') {
                    if (hole) {
                        cur_board[i][j] == '.';
                    }
                    else if (cur_board[idx][j] == 'R' || cur_board[idx][j] == 'B') {
                        if (idx != i) {
                            idx--;
                            while (cur_board[idx][j] == '#' && idx > 0) {
                                idx--;
                            }
                            if (idx != i) {
                                cur_board[idx][j] == 'R';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[idx][j] == '.') {
                        cur_board[idx][j] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx--;
                        while (cur_board[idx][j] == '#' && idx > 0) {
                            idx--;
                        }
                    }
                }
                if (cur_board[i][j] == 'B') {
                    if (hole) {
                        is_blue_dropped = true;
                        break;
                    }
                    else if (cur_board[idx][j] == 'R' || cur_board[idx][j] == 'B') {
                        if (idx != j) {
                            idx--;
                            while (cur_board[idx][j] == '#' && idx > 0) {
                                idx--;
                            }
                            if (idx != i) {
                                cur_board[idx][j] == 'B';
                                cur_board[i][j] == '.';
                            }
                        }
                    }
                    else if (cur_board[idx][j] == '.') {
                        cur_board[idx][j] = cur_board[i][j];
                        cur_board[i][j] = '.';
                        idx--;
                        while (cur_board[idx][j] == '#' && idx > 0) {
                            idx--;
                        }
                    }
                }
                if (cur_board[i][j] == 'O') {
                    hole = true;
                }
                
                if(cur_board[i][j] == '#') {
                    idx = i - 1;
                }
            }
            if (is_blue_dropped)
                break;
        }
        break;

    default:
        break;
    }

    if (!is_blue_dropped) {
        bool flag = false;
        
        // cout << endl;
        // cout << op << ',' << depth + 1 << endl;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cur_board[i][j] == 'R') {
                    flag = true;
                }
                // cout << cur_board[i][j];
            }
            // cout << endl;
        }
        if (flag) {
            DFS(cur_board, depth + 1, 0);
            DFS(cur_board, depth + 1, 1);
            DFS(cur_board, depth + 1, 2);
            DFS(cur_board, depth + 1, 3);
        }
        else {
            answer = depth + 1;
        }
    }
}

void Solve(void) {
    DFS(board, 0, 0);
    DFS(board, 0, 1);
    DFS(board, 0, 2);
    DFS(board, 0, 3);
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}