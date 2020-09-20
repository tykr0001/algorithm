#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        
        char c;
        int n;
        multiset<int> v;
        
        while (k--) {
            cin >> c >> n;
            if (c == 'I') {
                v.insert(n);
            }
            else if (c == 'D' && v.size() > 0) {
                if (n == -1) {
                    v.erase(v.begin());
                }
                else {
                    multiset<int>::iterator it = v.end();
                    it--;
                    v.erase(it);
                }
            }
        }

        if (v.size() == 0) {
            printf("EMPTY\n");

        } else {
            multiset<int>::iterator it = v.end();
            it--;
            printf("%d %d\n", *it, *v.begin());
        }
    }
    return 0;
}
