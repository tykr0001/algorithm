#include<iostream>
#include<tuple>

using namespace std;

typedef long long int LLI;

LLI M, SEED, X_1, X_2, a, c;

// Extended Euclidean Algorithm
// return <x, y, d> such that ax+by = d ( d is a gcd(a,b) )
tuple<LLI, LLI, LLI> EEA(LLI a, LLI b) {
    if (b == 0) {
        return make_tuple((LLI)1, (LLI)0, (LLI)a);
    }
    LLI x, y, d;
    tie(x, y, d) = EEA(b, a % b);
    return make_tuple(y, x - (a / b) * y, d);
}

// Modular Multiplicative Inverse
// return a^-1 (mod M)
LLI ModularMulInverse(LLI a, LLI m) {
    return get<0>(EEA(a, m));
}

// Exponential
// return a^x (mod M)
LLI Exp(LLI a, LLI x) {
    if (x == 0) {
        return 1;
    }
    LLI tmp = Exp(a, x / 2);
    if (x % 2) {
        return tmp * tmp % M * a % M;
    }
    else {
        return tmp * tmp % M;
    }
}

int main(void) {
    cin >> M >> SEED >> X_1 >> X_2;
    if (SEED == X_1) {
        cout << 1 << " " << 0;
    }
    else {
        int X = X_1 - X_2;
        int Q = SEED - X_1;
        if (X < 0)
            while (X < 0) { X += M; }
        if (Q < 0)
            while (Q < 0) { Q += M; }

        // using Extended Euclidean Algorithm
        // a = (X * ModularMulInverse(Q, M)) % M;

        // using Fermat’s little theorem
        a = (X * Exp(Q, M - 2)) % M;
        while (a < 0) { a += M; }

        c = X_2 - a * X_1;
        while (c < 0) { c += M; }

        cout << a << " " << c;
    }

    return 0;
}