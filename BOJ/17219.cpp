#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    map<string,string> m;
    for(int i=0; i<N;i++){
        string a,b;
        cin >> a >> b;
        m[a] = b;
    }

    for(int j=0; j<M;j++){
        string a;
        cin >> a;
        cout << m[a] << '\n';
    }

    return 0;
}