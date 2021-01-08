#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int M,N,L,answer=0;
    cin >> M >> N >> L;
    int gun[M];
    for(int i=0; i<M; ++i){
        cin >> gun[i];
    }
    sort(gun,gun+M);
    for(int i=0; i<N; ++i){
        int x,y;
        cin >> x >> y;
        if(y>L) continue;
        int upper = x+L-y, lower = x-L+y, low = 0, high = M-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(lower <= gun[mid] && gun[mid] <= upper){
                answer++;
                break;
            }
            else if(gun[mid] < lower){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    cout << answer;
}
