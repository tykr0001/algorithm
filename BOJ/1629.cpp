#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A,B,C;

LL Ex(LL a, LL x){
    if(x==0){
        return 1%C;
    }
    if(x==1){
        return a%C;
    }
    LL tmp = Ex(a,x/2);
    if(x%2){
        return tmp*tmp%C*a%C;
    }
    else{
        return tmp*tmp%C;
    }
}

int main(void){
    cin >> A >> B >> C;
    cout << Ex(A,B) << endl;

    return 0;
}