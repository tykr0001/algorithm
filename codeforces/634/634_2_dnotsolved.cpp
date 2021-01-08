#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;

LL t;
LL n,q;
vector<LL> a;
vector<LL> a_next;
vector<LL> w;
vector<LL> perfect_square;
LL beauty;
LL mul;

LL GCD(LL a, LL b){
    if(a<b) swap(a,b);
	while(b){
		LL r = a%b;
		a= b;
		b= r;
	}
	return a;
}

LL lcm(LL a, LL b){
    return a * b / GCD(a,b);
}

void SetPerfectSquare(){
    for(LL i=1; i <= 100000; i++){
        perfect_square.push_back(i*i);
    }
}

bool IsAdjacent(LL a, LL b){

}


// a*b == lcd * gcd
// lcd = a*b / gcd
// lcd / gcd = a*b / gcd / gcd => perfect square
// a * b == perfect square
int main(void) {
    SetPerfectSquare();
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        a.resize(n);
        a_next.clear();
        a_next.resize(n);
        beauty = 0;
        mul = 1;
        for(LL i=0; i<n; i++){
            cin >> a[i];
            for(LL j=0; perfect_square[j] <= a[i]; j++){
                if(a[i] % perfect_square[j] == 0){
                    a[i] /= perfect_square[j];
                }
            }
            mul *= a[i];
        }
        cin >> q;
        w.clear();
        w.resize(q);
        for(LL i=0; i<n; i++){
            cin >> w[i];
            for(LL i=0; i<n; i++){
                //a[i] = 
                for(LL j=0; perfect_square[j] <= a[i]; j++){
                if(a[i] % perfect_square[j] == 0){
                    a[i] /= perfect_square[j];
                }
            }
            }
        }
    }

    return 0;
}