#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int mn = atoi(argv[1]);
    int mx = atoi(argv[2]);
    int starting_idx = atoi(argv[3]);
    int num = atoi(argv[4]);
    ofstream ofs;
    for (int i = starting_idx; i < starting_idx + num; i++) {
        string str_idx = to_string(i / 10) + to_string(i % 10);
        int a; a = rnd.next(mn, mx);
        int b; b = rnd.next(mn, mx);
        ofs.open("./data/" + str_idx + ".in");
        ofs << a << " " << b << "\n";
        ofs.close();
    }
    return 0;
}