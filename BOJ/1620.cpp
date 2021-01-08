#include <bits/stdc++.h>

using namespace std;

map<string,int> m_stoi;
vector<string> m_itos;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    m_itos.resize(N+1);
    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        m_stoi.emplace(str,i);
        m_itos[i] = str;
    }

    for(int i=1; i<=M; i++){
        string str;
        cin >> str;
        if('0' <= str[0] && str[0] <='9') { // 숫자입력
            cout << m_itos[stoi(str)] << '\n';
        }
        else { // 문자열입력
            cout << m_stoi[str] << '\n';
        }
    }

    return 0;
}