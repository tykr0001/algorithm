#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int mnn = atoi(argv[1]);
    int mxn = atoi(argv[2]);
    int mna = atoi(argv[3]);
    int mxa = atoi(argv[4]);
    int starting_idx = atoi(argv[5]);
    int num = atoi(argv[6]);
    ofstream ofs;
    for (int i = starting_idx; i < starting_idx + num; i++) {
        string str_idx = "";
        if(i<10) str_idx = "00" + to_string(i);
        else if(i<100) str_idx = "0" + to_string(i);
        else str_idx = to_string(i);
        int n; n = rnd.next(mnn, mxn);
        ofs.open("./data/" + str_idx + ".in");
        ofs << n << "\n";
        for(int j=0; j<n; j++) {
            int a; a = rnd.next(mna, mxa);
            ofs << a << "\n";
        }
        
        ofs.close();
    }
    return 0;
}