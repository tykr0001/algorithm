#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int> h;
vector<int> zone; // i-1~i ������
vector<int> max_zone; // 0-i �ִ뱸����
vector<int> round_trip; // 0~i �պ���
int dp[1000000001]; // i�� ����

int N, T;


// T�ϵ��� �� �� �ִ� idx = T/2
int main(void){
    bool flag = false;
    cin >> N >> T;
    h.resize(N);
    zone.resize(N); 
    max_zone.resize(N); 

    cin >> h[0];
    
    zone[0] = 0;
    max_zone[0] = 0;
    round_trip[0] = 0;
    for(int i=1; i<N; i++){
        cin >> h[i];
        zone[i] = h[i]-h[i-1];
        max_zone[i] = max(max_zone[i-1], zone[i]);
        round_trip[i] = round_trip[i-1] + zone[i];
    }
    //DP(T);
}