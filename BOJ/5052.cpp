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
\*************  2022-03-22 15:19:19  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int n;
vector<string> str;

// Trie(∆Æ∂Û¿Ã)
// struct Trie {
//     Trie* next[10];
//     bool finish;

//     Trie() : finish(false) {
//         memset(next, 0, sizeof(next));
//     }
//     ~Trie() {
//         for (int i = 0; i < 10; i++)
//             if (next[i] != nullptr)
//                 delete next[i];
//     }
//     void Insert(const char* key) {
//         if (*key == '\0') {
//             finish = true;
//         }
//         else {
//             int cur = *key - '0';
//             if (next[cur] == nullptr)
//                 next[cur] = new Trie();
//             next[cur]->Insert(key + 1);
//         }
//     }
//     Trie* Find(const char* key) {
//         if (*key == '\0')
//             return nullptr;
//         if (finish)
//             return this;
//         int cur = *key - '0';
//         return next[cur]->Find(key + 1);
//     }
// };


class Trie {
public:
    unordered_map<char, Trie*> next;
    bool finish;

    Trie() : finish(false) { }
    ~Trie() {
        for (auto e : next) {
            delete e.second;
        }
    }
    void Insert(const string& str, int pos) {
        if (pos == str.size()) {
            finish = true;
        }
        else {
            char cur = str[pos];
            if (next.find(cur) == next.end())
                next[str[pos]] = new Trie();
            next[cur]->Insert(str, pos + 1);
        }
    }
    Trie* Find(const string& str, int pos) {
        if (pos == str.size()) {
            return nullptr;
        }
        if (finish)
            return this;
        char cur = str[pos];
        return next[cur]->Find(str, pos + 1);
    }
};


void Solve(void) {
    Trie* tree = new Trie();

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        tree->Insert(str[i], 0);
    }
    for (int i = 0; i < n; i++) {
        if (tree->Find(str[i], 0) != nullptr) {
            cout << "NO" << endl;
            delete tree;
            return;
        }
    }
    cout << "YES" << endl;
    delete tree;
}

void Init(void) {
    cin >> n;
    str.clear();
    resize(str, n);
}

int main(void) {
    Boost;
    int t; cin >> t;;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}