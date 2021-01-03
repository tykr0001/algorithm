#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, size = 0;
    vector<int> arr;
    cin >> N;
    
    arr.resize(N);
    arr.push_back(-1);
    for(int i=0; i<N; ++i){
        int op;
        cin >> op;
        if(op==0 && size > 0){
            int temp, j=1;
            cout << arr[1] << "\n";
            temp = arr[1] = arr[size];
            --size;
            while(j*2+1 <= size && (arr[j] < arr[j*2] || arr[j] < arr[j*2+1])){
                if(arr[j] < arr[j*2] && arr[j] < arr[j*2+1])
                    if(arr[j*2] >= arr[j*2+1]){
                        arr[j] = arr[j*2];
                        arr[j*2] = temp;
                        j*=2;
                    }
                    else{
                        arr[j] = arr[j*2+1];
                        arr[j*2+1] = temp;
                        j=j*2+1;
                    }
                else if(arr[j] < arr[j*2]){
                    arr[j] = arr[j*2];
                    arr[j*2] = temp;
                    j*=2;
                }
                else{
                    arr[j] = arr[j*2+1];
                    arr[j*2+1] = temp;
                    j=j*2+1;
                }
            }
            if(j*2==size && arr[j] < arr[j*2]){
                    arr[j] = arr[j*2];
                    arr[j*2] = temp;
                    j*=2;
            }
        }
        else if(op==0 && size == 0)
            cout << 0 << "\n";
        else{
            int temp,j;
            size++;
            j = size;
            temp = arr[j] = op;
            while(j!=1 && arr[j] > arr[j/2]){
                arr[j] = arr[j/2];
                arr[j/2] = temp;
                j/=2;
            }
        }
    }
    return 0;
}
