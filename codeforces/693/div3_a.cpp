#include <iostream>

using namespace std;

int t;
int n;
int w, h;
int cnt_w;
int cnt_h;

int main(void) {
    cin >> t;
    while (t--) {
        cin >> w >> h >> n;
        cnt_w = w % 2 == 0 ? 1 : 0;
        cnt_h = h % 2 == 0 ? 1 : 0;
        while (cnt_w != 0) {
            if (w % 2 == 0) {
                w /= 2;
                cnt_w *= 2;
            }
            else {
                break;
            }
        }
        while (cnt_h != 0) {
            if (h % 2 == 0) {
                h /= 2;
                cnt_h *= 2;
            }
            else {
                break;
            }
        }
        if(cnt_w == 0){
            cnt_w = 1;
        }
        if(cnt_h == 0){
            cnt_h = 1;
        }
        if (cnt_w * cnt_h >= n) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}