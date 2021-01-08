#include <iostream>
#include <cmath>

using namespace std;

int main (void){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    cout << min(min(x,w-x),min(y,h-y));

    return 0;
}