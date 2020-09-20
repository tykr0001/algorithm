#include<iostream>
#define PERIOD 1500000
#define DIV 1000000

using namespace std;

int main(void){
    long long n;
    int* fibo = new int[PERIOD+1];
    fibo[0] = 0;
    fibo[1] = 1;
    cin >> n;
    if(n>PERIOD) n %= PERIOD;
    for(int i=2; i<=n; ++i){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % DIV;
    }
    cout << fibo[n] << endl;
    
    return 0;
}
