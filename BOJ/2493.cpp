#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int N;
    vector<int> arr;
    vector<int> answer;
    cin >> N;
    arr.resize(N);
    answer.resize(N);
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    for(int i=N-1; i>=0; --i){
        for(int j=i-1; j>=0; --j){
            if(arr[i] < arr[j]){
                answer[i] = j+1;
                break;
            }
        }
    }
    
    for(int i=0; i<N; ++i){
        cout << answer[i] << " ";
    }
}
