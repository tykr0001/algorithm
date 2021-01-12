#include <bits/stdc++.h>

using namespace std;

vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;

/*
* 루트를 노드를 기준으로 in-order를 좌우로 나눠서 갯수를 각각 구함(lhs, rhs)
* post-order에서 가장 먼저 나오는 lhs개의 원소가 왼쪽부분(lhs의 가장 오른쪽이 서브루트_0)
* 그 이후의 rhs가 오른쪽부분(rhs의 가장 오른쪽이 서브루트_1)
* lhs rhs가 1이 될때까지 재귀
*/
void PreOrder(int in_init, int post_init, int size) {
    if (size == 0) {
        return;
    }if (size == 1) {
        cout << post_order[post_init] << " ";
        return;
    }
    int root = post_order[post_init + size - 1];
    cout << root << " ";
    int i = in_init;
    while (i < in_init + size) {
        if (in_order[i] == root) {
            break;
        }
        i++;
    }
    int lhs = i - in_init;
    int rhs = size - lhs - 1;
    PreOrder(in_init, post_init, lhs);
    PreOrder(i + 1, post_init + lhs, rhs);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int root;
    int lhs, rhs;
    cin >> n;
    in_order.resize(n);
    post_order.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in_order[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> post_order[i];
    }

    PreOrder(0, 0, n);
    return 0;
}