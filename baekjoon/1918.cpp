#include<iostream>
#include<stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<char> op;
    string statement;
    cin >> statement;
    for(int i=0; i<statement.length(); ++i){
        if('A' <= statement[i] && statement[i] <= 'Z')
            cout << statement[i];
        else{
            if(op.empty()) 
                op.push(statement[i]);
            else
            switch(statement[i]){
                case '+' : 
                case '-' : 
                    while(!op.empty() && op.top() != '('){
                        cout << op.top();
                        op.pop();
                    }
                    op.push(statement[i]);
                    break;
                case '*' : 
                case '/' : 
                    while(!op.empty() && op.top() != '(' && (op.top() == '*' || op.top() == '/')){
                        cout << op.top();
                        op.pop();
                    }
                    op.push(statement[i]);
                    break;
                case '(' : 
                    op.push(statement[i]);  
                    break;
                case ')' :
                    while(!op.empty() && op.top() != '('){
                        cout << op.top();
                        op.pop();
                    }
                    op.pop();
                    break;
                default : 
                    break;
            }
        }
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
    return 0;
}
