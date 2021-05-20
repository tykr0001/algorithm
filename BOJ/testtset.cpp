#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;
vector<long long> tree;
long long Init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = Init(node * 2, start, (start + end) / 2)
            + Init(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

long long Update(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] += diff;
    }
    else {
        return tree[node] = Update(node * 2, start, (start + end) / 2, idx, diff)
                            + Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

long long Sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return Sum(node * 2, start, (start + end) / 2, left, right)
            + Sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> deleted_idx;
    vector<int> ans;
    ans.resize(n);
    arr.resize(n);
    tree.resize(int(ceil(log2(1 << n + 1) + 1)));

    for (int i = 0; i < n; i++)
        ans[i] = 1;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i].length() == 1) {
            if (cmd[i] == "C") {
                deleted_idx.emplace_back(k);
                ans[k] = 0;
                Update(1, 0, n - 1, k, 1);

                if (k < n - 1) {
                    if (Sum(0, 0, n - 1, k + 1, n - 1) != n - 1 - k - 1) {
                        k++;
                        while (ans[k] == 0)
                            k++;
                    }
                    else {
                        k--;
                        while (ans[k] == 0)
                            k--;
                    }
                }
                else {
                    k--;
                    while (ans[k] != 0)
                        k--;
                }
            }
            else {
                Update(1, 0, n - 1, deleted_idx.back(), -1);
                ans[deleted_idx.back()] = 1;
                deleted_idx.pop_back();
            }
        }
        else {
            if (cmd[i][0] == 'U') {
                k -= Sum(1, 0, n - 1, k - cmd[i][2] + '0', k);
                k -= cmd[i][2] - '0';
            }
            else {
                k += Sum(1, 0, n - 1, k - cmd[i][2] + '0', k);
                k += cmd[i][2] - '0';
            }
        }
    }
    for (int i = 0; i < n; i++)
        answer += ans[i] ? "O" : "X";
    return answer;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<string> cmd({ "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
    cout << solution(n, k, cmd);
    return 0;
}