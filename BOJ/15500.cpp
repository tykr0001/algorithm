#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, cnt;
vector<int> pole[4];
vector<tuple<int,int>> answer;

// 원판 N을 i에서 j로 이동
void Move(int i, int j, int n) {
    if(pole[i].empty()){
        return;
    }
    if(pole[i].end() == find(pole[i].begin(),pole[i].end(),n)){
        return;
    }
    
    int idx = pole[i].size()-1;
    while(pole[i][idx] != n){
        pole[6 - i - j].push_back(pole[i].back());
        pole[i].pop_back();
        answer.emplace_back(i,6-i-j);
        idx--;
    }

    pole[j].push_back(n);
    pole[i].pop_back();
    answer.emplace_back(i,j);
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int inp;
        cin >> inp;
        pole[1].push_back(inp);
    }
    for(int i=N; i>0; --i){
        Move(1, 3, i);
        Move(2, 3, i);
    }

    cout << answer.size() << endl;
    for(auto iter=answer.begin(); iter!=answer.end(); iter++){
        cout << get<0>(*iter) << " " << get<1>(*iter) << endl;
    }

    return 0;
}