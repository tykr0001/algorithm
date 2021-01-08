#include <iostream>

using namespace std;

// v1 = Vs * cos(wt)
// v2 = Vr * cos(wt+theta)
// v2 = i R 
//    = C d(v1-v2)/dt * R
//    = RC * d/dt(Vs*cos(wt) - Vr*cos(wt+theta))
//    = RC * (-Vs*w*sin(wt) + Vr*w*sin(wt+theta))
//    = RC * (-Vs*w*sin(wt) + Vr*w*sin(wt)cos(theta)+cos(wt)sin(theta))
double Vs, R, C;
int T;
double w;
int main(void) {
    cin >> Vs >> R >> C >> T;
    while(T--){
        cin >> w;
    }
    return 0;
}