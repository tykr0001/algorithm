#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int LL;

int main(void) {
    LL min, max;
    cin >> min >> max;
    LL answer = max - min + 1;
    vector<bool> n(max - min + 1, true);    // 제곱ㄴㄴ수 : true
                                            // [min:max] ~ [0:max-min]
    vector<bool> p(LL(sqrt(max)) + 1, true); // 소수 : true
                                            // [0:sqrt(max)]

    
    // prime
    for (LL i = 2; i <= LL(sqrt(max)); ++i) {
        if (p[i]) {
            for (LL j = 2; i * j <= LL(sqrt(max)); ++j) {
                p[i * j] = false;
            }
        }
    }

    // 제곱ㄴㄴ수
    for (LL i = 2; i <= LL(sqrt(max)); ++i) {
        if (p[i]) {
            LL j = (min % (i*i)) ? (min / (i*i) + 1) : (min / (i*i));
            while (i * i * j <= max) {
                if(n[i * i * j - min]){
                    n[i * i * j - min] = false;
                    answer--;
                }
                j++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}