#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;

LL t;
LL n; // num of friends
LL m; // num of unique presents
LL sum;
vector<int> friends;
vector<int> present;

int main(void) {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        sum = 0;
        friends.clear();
        friends.resize(n);
        present.clear();
        present.resize(m);
        for(int i=0; i<n; i++){
            cin >> friends[i];
        }
        for(int i=0; i<m; i++){
            cin >> present[i];
        }

        sort(friends.begin(), friends.end(), greater<int>());
        int idx=0;
        for(int i=0; i<n; i++) {
            if(idx <= friends[i]-1){
                sum += present[idx];
                idx++;
            }
            else{
                sum += present[friends[i]-1];
            }
        }

        cout << sum << endl;
    }

    return 0;
}