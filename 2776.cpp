#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; ++i){
        int N, M;
        vector<int> note1;
        cin >> N;
        note1.resize(N);
        for(int j=0; j<note1.size(); ++j){
            cin >> note1[j];
        }
        sort(note1.begin(),note1.end());
        cin >> M;
        for(int j=0; j<M; ++j){
            int temp;
            cin >> temp;
            if(binary_search(note1.begin(),note1.end(),temp)){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
