#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string AddString(string a, string b);
string SubtractString(string a, string b);
string MultiplyString(string a, string b);
string DevideString(string a, string b);
string ModuloString(string a, string b);
string ConvertNotation(string target, int n);
bool IsPalindrome(string target);
bool IsNotSmaller(string a, string b);

int main(void) {
    string decimal_str;
    string n_notation_str = "";
    cin >> decimal_str;
    for (int i = 2; i <= 10; i++) {
        n_notation_str = ConvertNotation(decimal_str, i);
        if (IsPalindrome(n_notation_str)) {
            cout << i << " " << n_notation_str << endl;
        }
    }
    if (n_notation_str == "") {
        cout << "NIE" << endl;
    }
    return 0;
}

// return a + b (not concatenate)
string AddString(string a, string b) {
    string ret = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) {
        a.resize(b.length(), '0');
    }
    else {
        b.resize(a.length(), '0');
    }

    for (int i = 0; i < a.length(); ++i) {
        int tmp = a[i] - '0' + b[i] - '0' + carry;
        if (tmp >= 10) {
            tmp -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ret += tmp + '0';
    }
    if (carry == 1)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}

// only if a >= b
// return a - b
string SubtractString(string a, string b) {
    string ret = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) {
        a.resize(b.length(), '0');
    }
    else {
        b.resize(a.length(), '0');
    }

    for (int i = 0; i < a.length(); ++i) {
        int tmp = (a[i] - '0') - (b[i] - '0') + carry;
        if (tmp < 0) {
            tmp += 10;
            carry = -1;
        }
        else {
            carry = 0;
        }
        ret += tmp + '0';
    }
    while (ret[ret.length() - 1] == '0') {
        ret.pop_back();
    }
    if(ret.empty()){
        ret.push_back('0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// return a * b
string MultiplyString(string a, string b) {
    if (b == "1") {
        return a;
    }
    string tmp = MultiplyString(a, DevideString(b, "2"));
    if ((b[b.length() - 1] - '0') % 2) {
        tmp = AddString(AddString(tmp, tmp), a);
    }
    else {
        tmp = AddString(tmp, tmp);
    }
    return tmp;
}

// return quotient of a / b
string DevideString(string a, string b) {
    string cnt = "0";
    while (IsNotSmaller(a, b)) {
        a = SubtractString(a, b);
        cnt = AddString(cnt, "1");
    }
    return cnt;
}

// return remainder of a / b
string ModuloString(string a, string b) {
    return SubtractString(a, MultiplyString(DevideString(a, b), b));
}

// target must be Decimal
// return n-Notation of target
string ConvertNotation(string target, int n) {
    // todo - 2
    string ret = "";
    string n_str = to_string(n);
    string quotient = target;
    //string m = SubtractString(target, MultiplyString(quotient,n_str));
    string m;
    while(quotient != "0"){
        m = ModuloString(quotient, n_str);
        quotient = DevideString(quotient, n_str);
        ret += m;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

bool IsPalindrome(string target) {
    // todo - 1
    for (int i = 0; i < target.length(); i++) {
        if (target[i] != target[target.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

// return a >= b
bool IsNotSmaller(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    else {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return true;
    }
}