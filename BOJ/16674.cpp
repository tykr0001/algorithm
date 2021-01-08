#include <iostream>
#include <string>

using namespace std;

int N;

int zero;
int one;
int two;
int eight;
bool not_related;

int main(void) {
    cin >> N;

    while (N) {
        int tmp = N % 10;
        if (tmp == 1) {
            one++;
        }
        else if (tmp == 2) {
            two++;
        }
        else if (tmp == 8) {
            eight++;
        }
        else if (tmp == 0) {
            zero++;
        }
        else {
            not_related = true;
        }

        N /= 10;
    }

    if (not_related) {
        cout << 0 << endl;
    }
    else if (!zero || !one || !two || !eight) {
        cout << 1 << endl;
    }
    else if (!(zero == one && one == two && two == eight)) {
        cout << 2 << endl;
    }
    else {
        cout << 8 << endl;
    }

    return 0;
}