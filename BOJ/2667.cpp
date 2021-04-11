#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'

using namespace std;
using pii = pair<int, int>;

template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... sizes>
void resize(T& container, int _size, sizes... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }

int N;
vector<string> graph;
vector<vector<bool>> visited;
vector<int> house_num;

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

bool CheckBound(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

void BFS(const pii& init) {
    int num = 1;
    queue<pii> sq;
    sq.emplace(init);
    visited[init.fi][init.se] = true;
    while (!sq.empty()) {
        pii node = sq.front();
        sq.pop();

        for (int k = 0; k < 4; k++) {
            int i = node.fi + di[k];
            int j = node.se + dj[k];
            if (CheckBound(i, j) && graph[i][j] == '1' && !visited[i][j]) {
                num++;
                sq.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    house_num.emplace_back(num);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    resize(graph, N);
    resize(visited, N, N);
    // visited.resize(N, vector<bool>(N));
    // visited = vector<vector<bool>>(N, vector<bool>(N));
    cin >> graph;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == '1' && !visited[i][j]) {
                BFS({ i,j });
            }
        }
    }
    sort(house_num);
    cout << house_num.size() << endl;
    for (int& num : house_num) {
        cout << num << endl;
    }
}