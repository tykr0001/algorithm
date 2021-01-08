#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int n, carry;
    string f_current, f_next, temp;
    f_current = "0";
    f_next = "1";
    
    cin >> n;
    
    for(int i = 0, j ; i < n ; ++i){
    	temp = "";
    	carry = 0;

		for(j = 0 ; j < f_current.size() ; ++j){
  			temp += (f_current[j] - '0' + f_next[j] - '0' + carry) % 10 + '0';
  			carry = (f_current[j] - '0' + f_next[j] - '0' + carry) / 10;
		}
		
		if(f_next.size() > f_current.size()){
			if(f_next[j] - '0' + carry >= 10){
				temp += (f_next[j] - '0' + carry) / 10 + '0';
				temp +=	'1';
			}
			else{
				temp += f_next[j] + carry;
			}
		}
		else{
			if(carry != 0){
				temp += carry + '0';
			}
		}
		
		f_current = f_next;
		f_next = temp;
		
			
	reverse(f_current.begin(), f_current.end());
	cout << f_current << endl;
	reverse(f_current.begin(), f_current.end());
	}

	
    return 0;
}
