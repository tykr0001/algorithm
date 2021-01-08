#include <iostream>

using namespace std;

bool IsBigger(string a, string b) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] > b[i]) {
            return true;
        }
        else if (a[i] < b[i]) {
            return false;
        }
    }
    return false;
}

string MakePalindrome(string s) {
    int idx = s.length() / 2;
    if (s.length() % 2) { //홀수
        for (int i = idx; i >= 0; --i) {
            s[idx + i] = s[idx - i];
        }
    }
    else { //짝수
        for (int i = idx; i >= 0; --i) {
            s[idx + i] = s[idx - i - 1];
        }
    }
    return s;
}

int main(void) {
    string s, palindrome;
    cin >> s;
    palindrome = MakePalindrome(s);
    if (IsBigger(palindrome, s)) {
        cout << palindrome << endl;
    }
    else{
        string sub_s;
        if (s.length() % 2) {
            sub_s = s.substr(0, s.length() / 2 + 1);
        }
        else {
            sub_s = s.substr(0, s.length() / 2);
        }

        int carry = 1;
        for(int i=sub_s.length()-1; i>=0; --i){
            sub_s[i] += carry;
            if(sub_s[i] > '9'){
                sub_s[i] -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }

        if(carry){
            cout << 1;
            for(int i=0; i<s.length()-1;++i){
                cout << 0;
            }
            cout << 1 << endl;
            return 0;
        }
        
        string answer;
        answer = MakePalindrome(sub_s);
        if (s.length() % 2) {
            answer = MakePalindrome(sub_s+sub_s.substr(0,sub_s.length()-1));
        }
        else {
            answer = MakePalindrome(sub_s+sub_s);
        }
        cout << answer << endl;
    }
    return 0;
}