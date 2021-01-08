#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main(void) {
    int a, b;
    cin >> a >> b;
    int gcd = GCD(a, b);
    cout << gcd << endl;
    cout << a * b / gcd << endl;
}