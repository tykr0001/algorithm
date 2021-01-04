#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

map<char, char> table;
map<char, char> opt_table;

void TableInit(void) {
    table['A'] = 'A';
    table['E'] = '3';
    table['H'] = 'H';
    table['I'] = 'I';
    table['M'] = 'M';
    table['O'] = 'O';
    table['S'] = '2';
    table['T'] = 'T';
    table['U'] = 'U';
    table['V'] = 'V';
    table['W'] = 'W';
    table['X'] = 'X';
    table['Y'] = 'Y';
    table['Z'] = '5';
    table['b'] = 'd';
    table['d'] = 'b';
    table['i'] = 'i';
    table['l'] = 'l';
    table['m'] = 'm';
    table['n'] = 'n';
    table['o'] = 'o';
    table['p'] = 'q';
    table['q'] = 'p';
    table['r'] = '7';
    table['u'] = 'u';
    table['v'] = 'v';
    table['w'] = 'w';
    table['x'] = 'x';
    table['0'] = '0';
    table['1'] = '1';
    table['2'] = 'S';
    table['3'] = 'E';
    table['5'] = 'Z';
    table['7'] = 'r';
    table['8'] = '8';

    opt_table['B'] = 'b';
    opt_table['D'] = 'd';
    opt_table['I'] = 'i';
    opt_table['L'] = 'l';
    opt_table['M'] = 'm';
    opt_table['N'] = 'n';
    opt_table['O'] = 'o';
    opt_table['P'] = 'p';
    opt_table['Q'] = 'q';
    opt_table['R'] = 'r';
    opt_table['U'] = 'u';
    opt_table['V'] = 'v';
    opt_table['W'] = 'w';
    opt_table['X'] = 'x';
    opt_table['a'] = 'A';
    opt_table['e'] = 'E';
    opt_table['h'] = 'H';
    opt_table['s'] = 'S';
    opt_table['t'] = 'T';
    opt_table['y'] = 'Y';
    opt_table['z'] = 'Z';
}

string Optimize(string S) {
    string::iterator iter = S.begin();
    while (iter != S.end()) {
        if (opt_table.find(*iter) != opt_table.end())
            *iter = opt_table[*iter];
        if (table.find(*iter) == table.end())
            return "";
        iter++;
    }

    return S;
}

string makeQuilindrome(const string& S) {
    string ret = "";
    string::const_reverse_iterator riter = S.rbegin();
    while (riter != S.rend()) {
        ret += table[*riter++];
    }

    return ret;
}

bool isSelfQuilindrome(char c) {
    return table[c] == c;
}

bool IsQuilindrome(string S) {
    int beg = 0, end = S.length();
    if (end % 2) { // 문자열 길이가 홀수일 때,
        if (!isSelfQuilindrome(S[end / 2])) {
            return false;
        }
    }
    while (beg != end && beg != --end) {
        if (table[S[beg++]] != S[end]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    TableInit();
    string stop;
    string S, answer, reversed_string;
    int left = 0, right = 0;
    cin >> S;
    S = Optimize(S);

    if (S == "") {
        cout << -1 << endl;
        return 0;
    }

    int left_len = 0;
    int right_len = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (IsQuilindrome(S.substr(0, S.length() - i))) {   //left
            left_len = S.length() - i;
            break;
        }
        if (IsQuilindrome(S.substr(i, S.length()))) {   //right
            right_len = S.length() - i;
            break;
        }
    }

    reversed_string = makeQuilindrome(S);
    if (left_len > right_len) {
        answer = reversed_string + S.substr(left_len, S.length() - left_len);
    }
    else {
        answer = S.substr(0, S.length() - right_len) + reversed_string;
    }
    cout << answer << endl;

    return 0;
}