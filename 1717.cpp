#include<iostream>
#include<list>

using namespace std;

class tree{
	tree(int _num): top(this), parent_node(this), num(_num) {}
	void merge(tree& otherset);
	bool find(tree& otherset);
private:
	tree* top;
	tree* parent_node;
	int num;
};

void tree::merge(tree& otherset)
{
	otherset.parent_node = this->top;
}

bool tree::find(tree& otherset)
{
	return otherset.top == this->top;
}
	

int main(void)
{
	int n,m,command,a,b;
	cin >> n >> m;
	tree** arr = new tree*[n+1];
 	for(int i=0; i<n+1; ++i){
 		*arr[i] = tree(i);
 	}
 	for(int i=0; i<m; ++i){
		cin >> command >> a >> b;
		if(command == 0){
			(*arr[a]).merge(*arr[b]);
		}
		if(command == 1){
			if((*arr[a]).find(*arr[b]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
 	}
 	return 0;
}














