#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N,M;
int set = INT32_MAX;
int one = INT32_MAX;
int answer = 0;

int main(void){
    cin >> N >> M;

    for(int i=0;i<M;++i){
        int s,o;
        cin >> s >> o;
        set = min(set, s);
        one = min(one, o);
    }

    if(set>=6*one){
        cout << N*one << endl;
    }
    else{
        cout << (N/6)*set + ((N%6)*one > set ? set : (N%6)*one) << endl;
    }

    return 0;
}