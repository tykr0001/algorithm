#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1'000LL, "n");
    inf.readSpace();
    for (int i = 1; i <= n; i++) {
        int a = inf.readInt(1, 10'000LL, "a");
        inf.readEoln();
    }
    inf.readEof();

    return 0;
}