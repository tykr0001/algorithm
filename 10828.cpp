#include<iostream>
#include<stack>
#include<string>

using namespace std;

class stack_class{
	stack<int> my_stack;
public:
	void my_operator(const string& str_my_operator);
};

void stack_class::my_operator(const string& str_my_operator){
	if(str_my_operator=="push"){
		int input_n;
		cin >> input_n;
		my_stack.push(input_n);
	}
	if(str_my_operator=="pop"){
		my_operator("top");
		if(!my_stack.empty()) my_stack.pop();
	}
	if(str_my_operator=="size"){
		cout << my_stack.size() << endl;
	}
	if(str_my_operator=="empty"){
		cout << my_stack.empty() << endl;
	}
	if(str_my_operator=="top"){
		if(!my_stack.empty()) cout << my_stack.top() << endl;
		else cout << -1 << endl;
	}
}

int main(void){
	stack_class my_class;
	string str_my_operator;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> str_my_operator;
		my_class.my_operator(str_my_operator);
	}
}
