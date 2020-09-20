#include<iostream>
#include<queue>
#include<string>

using namespace std;

class queue_class{
	queue<int> my_queue;
public:
	void my_operator(const string& str_my_operator);
};

void queue_class::my_operator(const string& str_my_operator){
	if(str_my_operator=="push"){
		int input_n;
		cin >> input_n;
		my_queue.push(input_n);
		return;
	}
	if(str_my_operator=="pop"){
		my_operator("front");
		if(!my_queue.empty()) my_queue.pop();
		return;
	}
	if(str_my_operator=="size"){
		cout << my_queue.size() << endl;
		return;
	}
	if(str_my_operator=="empty"){
		cout << my_queue.empty() << endl;
		return;
	}
	if(str_my_operator=="front"){
		if(!my_queue.empty()) cout << my_queue.front() << endl;
		else cout << -1 << endl;
		return;
	}
	if(str_my_operator=="back"){
		if(!my_queue.empty()) cout << my_queue.back() << endl;
		else cout << -1 << endl;
		return;
	}
	return;
}

int main(void){
	queue_class my_class;
	string str_my_operator;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> str_my_operator;
		my_class.my_operator(str_my_operator);
	}
}
