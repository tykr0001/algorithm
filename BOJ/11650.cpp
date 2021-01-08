#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}