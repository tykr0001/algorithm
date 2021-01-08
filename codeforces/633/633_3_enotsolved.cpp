#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

typedef long long LL;

LL t;

vector<tuple<LL, LL, LL>> a; // <w,h,idx>
vector<LL> answer;
int main(void) {
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;

        a.resize(n+1);
        answer.resize(n+1,-1);
        for (int i = 1; i <= n; i++) {
            int w, h;
            cin >> w >> h;
            a[i] = make_tuple(w, h, i);
        }

        sort(a.begin(), a.end());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if ((get<0>(a[i]) > get<0>(a[j]) && get<1>(a[i]) > get<1>(a[j]))
                    || (get<0>(a[i]) > get<1>(a[j]) && get<1>(a[i]) > get<0>(a[j]))) {
                    answer[get<2>(a[i])] = get<2>(a[j]);
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;

        a.clear();
        answer.clear();
    }
}