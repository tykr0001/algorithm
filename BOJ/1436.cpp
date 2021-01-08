#include <iostream>
#include <string>
using namespace std;

bool IsInclude(int n){
    string tmp = to_string(n);
    size_t idx = tmp.find("666");
    return 0<= idx && idx < tmp.size();
}

int main(void){
    int N;
    cin >> N;
    for(int i=666; i<INT32_MAX;i++){
        if(IsInclude(i)){
            N--;
            if(N==0){
                cout << i;
                return 0;
            }
        }
    }
}