#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> cache(N, 1);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                cache[i] = max(cache[i], cache[j] + 1);
            }
        }
    }
    sort(cache.rbegin(),cache.rend());
    cout << cache[0] << endl;
    return 0;
}