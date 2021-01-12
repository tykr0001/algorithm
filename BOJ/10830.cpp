#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<vector<LL>> operator*(const vector<vector<LL>>& a, const vector<vector<LL>>& b) {
    vector<vector<LL>> ret(a.size(), vector<LL>(a.size(), 0));
    for (LL i = 0; i < a.size(); i++) {
        for (LL j = 0; j < a[0].size(); j++) {
            for (LL k = 0; k < b[0].size(); k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= 1000;
        }
    }
    return ret;
}

vector<vector<LL>> Ex(vector<vector<LL>> matrix, LL x) {
    vector<vector<LL>> ret(matrix.size(), vector<LL>(matrix.size(), 0));
    for(int i=0; i<ret.size(); i++){
        ret[i][i] = 1;
    }

    while(x>0){
        if(x%2){
            ret = ret * matrix;
        }
        x/=2;
        matrix = matrix * matrix;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N, B;
    cin >> N >> B;
    vector<vector<LL>> matrix(N, vector<LL>(N));
    for (LL i = 0; i < N; i++) {
        for (LL j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<LL>> answer(Ex(matrix, B));
    for (LL i = 0; i < N; i++) {
        for (LL j = 0; j < N; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}