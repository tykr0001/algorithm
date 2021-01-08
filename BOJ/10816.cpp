#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    map<int, int> m;

    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        if(m.count(tmp)){
            m[tmp]++;
        }
        else{
            m[tmp] = 1;
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        if(m.count(tmp)){
            cout << m[tmp] << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    return 0;
} 