#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<int> temp_vector;
    cin >> N;
    temp_vector.resize(N); 
    for(int i=0; i<N; ++i){
        cin >> temp_vector[i];
    }
    sort(temp_vector.begin(),temp_vector.end());
    cout << temp_vector[0];
    for(int i=1; i<N; ++i){
        if(temp_vector[i-1] != temp_vector[i]){
            cout << " " << temp_vector[i];
        }
    }
    return 0;
}
