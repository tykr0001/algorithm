#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
vector<pair<int,int>> circulator;
int R, C, T;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void Simulate(vector<vector<int>>& A) {
    vector<vector<int>> tmp(A);
    // spread
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] > 0) {
                for (int k = 0; k < 4; k++) {
                    if (0 <= i + dx[k] && i + dx[k] < R && 0 <= j + dy[k] && j + dy[k] < C && A[i + dx[k]][j + dy[k]] != -1) {
                        tmp[i + dx[k]][j + dy[k]] += A[i][j] / 5;
                        tmp[i][j] -= A[i][j] / 5;
                    }
                }
            }
        }
    }

    // cout << '\n';
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << tmp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // circulation
    int i,j;
    // upper
    tie(i,j) = circulator[0];
    while(i>0){
        tmp[i][j] = tmp[i-1][j];
        i--;
    }
    while(j<C-1){
        tmp[i][j] = tmp[i][j+1];
        j++;
    }
    while(i<circulator[0].first){
        tmp[i][j] = tmp[i+1][j];
        i++;
    }
    while(j>1){
        tmp[i][j] = tmp[i][j-1];
        j--;
    }
    tmp[i][j] = 0;

    // lower
    tie(i,j) = circulator[1];
    while(i<R-1){
        tmp[i][j] = tmp[i+1][j];
        i++;
    }
    while(j<C-1){
        tmp[i][j] = tmp[i][j+1];
        j++;
    }
    while(i>circulator[1].first){
        tmp[i][j] = tmp[i-1][j];
        i--;
    }
    while(j>1){
        tmp[i][j] = tmp[i][j-1];
        j--;
    }
    tmp[i][j] = 0;

    tmp[circulator[0].first][circulator[0].second] = -1;
    tmp[circulator[1].first][circulator[1].second] = -1;
    A = tmp;

    // cout << '\n';
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
}

int main(void) {
    cin >> R >> C >> T;
    A.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if(A[i][j] == -1){
                circulator.emplace_back(i,j);
            }
        }
    }
    while (T--) {
        Simulate(A);
    }
    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(A[i][j] > 0){
                sum += A[i][j];
            }
        }
    }
    cout << sum;
    return 0;
}