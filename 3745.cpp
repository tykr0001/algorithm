#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        int N, next_num;
        vector<int> vec;
        cin >> N;
        if(cin.eof())
            break;
        cin >> next_num;
        vec.push_back(next_num);
        for(int i=1; i<N; ++i){
            cin >> next_num;
            if(vec.back() < next_num)
                vec.push_back(next_num);
            else {
                vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), next_num);
                *iter = next_num;
            }
        }
        cout << vec.size() << "\n";
    }
}
    
