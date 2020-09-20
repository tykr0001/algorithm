#include<iostream>
#include<deque>
#include<string>

using namespace std;

class deque_class{
	deque<int> my_deque;
public:
	void my_operator(const string& str_my_operator);
};

void deque_class::my_operator(const string& str_my_operator){
	if(str_my_operator=="push_front"){
		int input_n;
		cin >> input_n;
		my_deque.push_front(input_n);
		return;
	}
	if(str_my_operator=="push_back"){
		int input_n;
		cin >> input_n;
		my_deque.push_back(input_n);
		return;
	}
	if(str_my_operator=="pop_front"){
		my_operator("front");
		if(!my_deque.empty()) my_deque.pop_front();
		return;
	}
	if(str_my_operator=="pop_back"){
		my_operator("back");
		if(!my_deque.empty()) my_deque.pop_back();
		return;
	}
	if(str_my_operator=="size"){
		cout << my_deque.size() << endl;
		return;
	}
	if(str_my_operator=="empty"){
		cout << my_deque.empty() << endl;
		return;
	}
	if(str_my_operator=="front"){
		if(!my_deque.empty()) cout << my_deque.front() << endl;
		else cout << -1 << endl;
		return;
	}
	if(str_my_operator=="back"){
		if(!my_deque.empty()) cout << my_deque.back() << endl;
		else cout << -1 << endl;
		return;
	}
	return;
}

int main(void){
	deque_class my_class;
	string str_my_operator;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> str_my_operator;
		my_class.my_operator(str_my_operator);
	}
}
