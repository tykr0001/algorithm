#include <bits/stdc++.h>

using namespace std;

vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;

/*
* ��Ʈ�� ��带 �������� in-order�� �¿�� ������ ������ ���� ����(lhs, rhs)
* post-order���� ���� ���� ������ lhs���� ���Ұ� ���ʺκ�(lhs�� ���� �������� �����Ʈ_0)
* �� ������ rhs�� �����ʺκ�(rhs�� ���� �������� �����Ʈ_1)
* lhs rhs�� 1�� �ɶ����� ���
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