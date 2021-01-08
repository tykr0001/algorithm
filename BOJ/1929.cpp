#include <iostream>

using namespace std;

int M, N;
bool not_prime[1000001];

void Eratos() {
    for (int i = 2; i * i <= N; i++) {
        if (!not_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                not_prime[j] = true;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    Eratos();
    not_prime[1] = true;
    for (int i = M; i <= N; i++) {
        if (!not_prime[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}