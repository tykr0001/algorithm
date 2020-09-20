#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string answer = "";
    
    stack<int> s;
    
    int next_number = 1;
    
    for(int i=0; i<N; ++i){
        int list;
        cin >> list;
        
        if(list >= next_number){
            while(list >= next_number){
                s.push(next_number);
                ++next_number;
                answer += "+\n";
            }
            s.pop();
            answer += "-\n";
        }
        else if(!s.empty() && list == s.top()){
            s.pop();
            answer += "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << answer;
    return 0;
}
