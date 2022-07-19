#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> sorted_arr;
unordered_map<int,int> idx;
int ans;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    
    for(int i=0; i<n; i++) {
        if(sorted_arr[i] != arr[i]) {
            swap(idx[arr[i]], idx[sorted_arr[i]]);
            swap(arr[i], arr[idx[arr[i]]]);
            ans++;
        }
    }
    
    cout << ans << '\n';

    return 0;
}