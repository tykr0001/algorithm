#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void PreOrder(const vector<vector<pair<int, int>>>& tree, int node){
    cout << char(node+'A');
    if(tree[node][0].second != INF){
        PreOrder(tree, tree[node][0].first);
    }
    if(tree[node][1].second != INF){
        PreOrder(tree, tree[node][1].first);
    }
}
void InOrder(const vector<vector<pair<int, int>>>& tree, int node){
    if(tree[node][0].second != INF){
        InOrder(tree, tree[node][0].first);
    }
    cout << char(node+'A');
    if(tree[node][1].second != INF){
        InOrder(tree, tree[node][1].first);
    }
}
void PostOrder(const vector<vector<pair<int, int>>>& tree, int node){
    if(tree[node][0].second != INF){
        PostOrder(tree, tree[node][0].first);
    }
    if(tree[node][1].second != INF){
        PostOrder(tree, tree[node][1].first);
    }
    cout << char(node+'A');
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> tree(N, vector<pair<int, int>>(2, { 0, INF }));
    for (int i = 1; i <= N; i++) {
        char src, dst_left, dst_right;
        cin >> src >> dst_left >> dst_right;
        src -= 'A';
        if (dst_left != '.') {
            dst_left -= 'A';
            tree[src][0] = { dst_left, 1 };
        }
        if (dst_right != '.') {
            dst_right -= 'A';
            tree[src][1] = { dst_right, 1 };
        }
    }

    PreOrder(tree, 0);
    cout << '\n';
    InOrder(tree, 0);
    cout << '\n';
    PostOrder(tree, 0);
    cout << '\n';

}