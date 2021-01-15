#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> ascend_cache(N, 1);
    vector<int> descend_cache(N, 1);
    vector<int> bitonic_cache(N, 0);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                ascend_cache[i] = max(ascend_cache[i], ascend_cache[j] + 1);
            }
        }
    }
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(arr[i]>arr[j]){
                descend_cache[i] = max(descend_cache[i], descend_cache[j] + 1);
            }
        }
    }
    for(int i=0; i<N; i++){
        bitonic_cache[i] = ascend_cache[i] + descend_cache[i] - 1;
    }
    sort(bitonic_cache.rbegin(), bitonic_cache.rend());
    cout << bitonic_cache[0] << endl;
    return 0;
}