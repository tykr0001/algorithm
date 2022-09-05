#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int min_a = atoi(argv[1]);
    int max_a = atoi(argv[2]);
    int min_b = atoi(argv[3]);
    int max_b = atoi(argv[4]);
    int starting_idx = atoi(argv[5]);
    int num = atoi(argv[6]);
    ofstream ofs;
    for (int i = starting_idx; i < starting_idx + num; i++) {
        string str_idx = "";
        if(i<10) str_idx = "00" + to_string(i);
        else if(i<100) str_idx = "0" + to_string(i);
        else str_idx = to_string(i);
        int a; a = rnd.next(min_a, max_a);
        int b; b = rnd.next(min_b, max_b);
        string seed = "";
        for(int j=0; j<10; j++) {
            int c = rnd.next(1,61);
            if(1<=c && c<=9) seed += to_string(c);
            else if (10<=c && c<=35) seed += char(c-10+'A');
            else if (36<=c && c<=61) seed += char(c-36+'a');
        }
        ofs.open("./data/" + str_idx + ".in");
        ofs << a << " " << b << "\n";
        ofs << seed << "\n";
        ofs.close();
    }
    return 0;
}