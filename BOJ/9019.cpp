#include <bits/stdc++.h>

using namespace std;

int D(int n) {
    return 2 * n % 10000;
}
int S(int n) {
    return (n + 9999) % 10000;
}
int L(int n) {
    return (n * 10 + n / 1000) % 10000;
}
int R(int n) {
    return n % 10 * 1000 + n / 10;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        string answer;
        cin >> A >> B;
        queue<pair<int, string>> q;
        vector<bool> is_visited(10000, false);

        q.emplace(A, "");
        is_visited[A] = true;

        while (!q.empty()) {
            int n;
            string op;
            tie(n, op) = q.front();
            q.pop();

            if (!is_visited[D(n)]) {
                is_visited[D(n)] = true;
                q.emplace(D(n), op + 'D');
                if(D(n)==B){
                    answer = op + 'D';
                    break;
                }
            }
            if (!is_visited[S(n)]) {
                is_visited[S(n)] = true;
                q.emplace(S(n), op + 'S');
                if(S(n)==B){
                    answer = op + 'S';
                    break;
                }
            }
            if (!is_visited[L(n)]) {
                is_visited[L(n)] = true;
                q.emplace(L(n), op + 'L');
                if(L(n)==B){
                    answer = op + 'L';
                    break;
                }
            }
            if (!is_visited[R(n)]) {
                is_visited[R(n)] = true;
                q.emplace(R(n), op + 'R');
                if(R(n)==B){
                    answer = op + 'R';
                    break;
                }
            }
        }
        cout << answer << endl;
    }
}

// #include <bits/stdc++.h>

// using namespace std;

// int A, B;
// string answer;
// queue<pair<int, string>> q;
// vector<bool> is_visited;

// int D(int n) {
//     return 2 * n % 10000;
// }
// int S(int n) {
//     return (n + 9999) % 10000;
// }
// int L(int n) {
//     return (n * 10 + n / 1000) % 10000;
// }
// int R(int n) {
//     return n % 10 * 1000 + n / 10;
// }

// int (*fp[4])(int) = { D,S,L,R };
// char op_char[4] = { 'D','S','L','R' };

// bool operation(const int idx, const int n, const string& str) {
//     int v = fp[idx](n);
//     if (!is_visited[v]) {
//         is_visited[v] = true;
//         q.emplace(v, str + op_char[idx]);
//         if (v == B) {
//             answer = str + op_char[idx];
//             return true;
//         }
//     }
//     return false;
// }

// int main(void) {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> A >> B;
//         answer = "";
//         queue<pair<int, string>> empty;
//         swap(q,empty);
//         q.emplace(A, "");
//         is_visited.clear();
//         is_visited.resize(10000, false);
//         is_visited[A] = true;

//         while (!q.empty()) {
//             int n;
//             string op;
//             tie(n, op) = q.front();
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 if (operation(i, n, op)) {
//                     break;
//                 }
//             }
//         }
//         cout << answer << endl;
//     }
// }