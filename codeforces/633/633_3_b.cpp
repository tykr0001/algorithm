#include <iostream>
#include <vector>

using namespace std;

int t;
int n;

int main(void) {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> candy(n);
        int sum = 0;
        int num_1 = 0;
        int num_2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> candy[i];
            sum += candy[i];
            if (candy[i] == 1) {
                num_1++;
            }
            else {
                num_2++;
            }
        }
        if (sum % 2) {
            cout << "NO" << endl;
        }
        else {
            if (n % 2) {
                if (num_1 % 2 == 0 && num_1 != 0) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
            }
            else {
                if (num_1 % 2 == 0) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
            }
        }
    }
}