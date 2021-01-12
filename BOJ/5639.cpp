#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void PostOrder(int pre_low, int size) {
    if(size == 0){
        return;
    }
    if (size == 1) {
        cout << tree[pre_low] << '\n';
        return;
    }
    int root = tree[pre_low];
    int i = pre_low + 1;
    while (i < pre_low + size) {
        if (root < tree[i])
            break;
        i++;
    }
    PostOrder(pre_low + 1, i - pre_low - 1);
    PostOrder(i, pre_low + size - i);
    cout << root << '\n';
}

void Solve(void) {
    PostOrder(0, tree.size());
}

void Input(void) {
    int inp = 0;
    tree.reserve(10001);
    while (true) {
        cin >> inp;
        if (cin.eof())
            break;
        tree.emplace_back(inp);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Input();
    Solve();

    return 0;
}