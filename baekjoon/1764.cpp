#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> non_seen;
    vector<string> non_seen_and_heard;
    int N, M;
    cin >> N >> M;
    
    non_seen.resize(N);
    
    for(int i=0; i<N; ++i){
        cin >> non_seen[i];
    }
    
    sort(non_seen.begin(), non_seen.end());
    for(int i=0; i<M; ++i){
        string temp;
        cin >> temp;
        if(binary_search(non_seen.begin(), non_seen.end(),temp)){
            non_seen_and_heard.push_back(temp);
        }
    }
    sort(non_seen_and_heard.begin(),non_seen_and_heard.end());
    cout << non_seen_and_heard.size() << "\n";
    for(int i=0; i<non_seen_and_heard.size(); ++i){
        cout << non_seen_and_heard[i] << "\n";
    }
}
