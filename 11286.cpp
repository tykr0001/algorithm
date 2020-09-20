#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

int abs(int num){
    if(num>0) return num;
    else return -num;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int N, size = 0;
    vector<int> arr;
    cin >> N;
    
    arr.resize(N);
    arr.push_back(-1);
    for(int i=0; i<N; ++i){
        int op;
        cin >> op;
        /* debugging
        if(i<N/2) op = rand()%200 - 100;
        else op = 0;
        */
        if(op==0 && size > 0){
            int temp, j=1;
            cout << arr[1] << "\n";
            temp = arr[1] = arr[size];
            --size;
            while(j*2+1 <= size && (abs(arr[j]) >= abs(arr[j*2]) || abs(arr[j]) >= abs(arr[j*2+1]))){
                if(abs(arr[j]) >= abs(arr[j*2]) && abs(arr[j]) >= abs(arr[j*2+1]))
                    if(abs(arr[j*2]) < abs(arr[j*2+1])){
                        if(abs(arr[j]) != abs(arr[j*2]) || (abs(arr[j]) == abs(arr[j*2])) && (arr[j] > arr[j*2])){
                            arr[j] = arr[j*2];
                            arr[j*2] = temp;
                            j*=2;
                        }
                        else break;
                    }
                    else if(abs(arr[j*2]) > abs(arr[j*2+1])){
                        if(abs(arr[j]) != abs(arr[j*2+1]) || (abs(arr[j]) == abs(arr[j*2+1])) && (arr[j] > arr[j*2+1])){
                            arr[j] = arr[j*2+1];
                            arr[j*2+1] = temp;
                            j=j*2+1;
                        }
                        else break;
                    }
                    else{
                        if(arr[j*2] <= arr[j*2+1]){
                            if(abs(arr[j]) != abs(arr[j*2]) || (abs(arr[j]) == abs(arr[j*2])) && (arr[j] > arr[j*2])){
                                arr[j] = arr[j*2];
                                arr[j*2] = temp;
                                j*=2;
                            }
                            else break;
                        }
                        else{
                            if(abs(arr[j]) != abs(arr[j*2+1]) || (abs(arr[j]) == abs(arr[j*2+1])) && (arr[j] > arr[j*2+1])){
                                arr[j] = arr[j*2+1];
                                arr[j*2+1] = temp;
                                j=j*2+1;
                            }
                            else break;
                        }
                    }
                else if(abs(arr[j]) >= abs(arr[j*2])){
                    if(abs(arr[j]) != abs(arr[j*2]) || (abs(arr[j]) == abs(arr[j*2])) && (arr[j] > arr[j*2])){
                        arr[j] = arr[j*2];
                        arr[j*2] = temp;
                        j*=2;
                    }
                    else break;
                }
                else{
                    if(abs(arr[j]) != abs(arr[j*2+1]) || (abs(arr[j]) == abs(arr[j*2+1])) && (arr[j] > arr[j*2+1])){
                        arr[j] = arr[j*2+1];
                        arr[j*2+1] = temp;
                        j=j*2+1;
                    }
                    else break;
                }
            }
            if(j*2==size && abs(arr[j]) >= abs(arr[j*2])){
                if(abs(arr[j]) != abs(arr[j*2]) || (abs(arr[j]) == abs(arr[j*2])) && (arr[j] > arr[j*2])){
                    arr[j] = arr[j*2];
                    arr[j*2] = temp;
                    j*=2;
                }
            }
        }
        else if(op==0 && size == 0)
            cout << 0 << "\n";
        else{
            int temp,j;
            size++;
            j = size;
            temp = arr[j] = op;
            while(j!=1 && (abs(arr[j]) < abs(arr[j/2]) || (abs(arr[j]) == abs(arr[j/2])) && (arr[j] < arr[j/2]))){
                arr[j] = arr[j/2];
                arr[j/2] = temp;
                j/=2;
            }
        }
    }
    return 0;
}
