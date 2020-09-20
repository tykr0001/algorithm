#include<iostream>

using namespace std;

int cup[3] = { 1,0,0 };
int temp;

void swap(const char op) {
	switch (op) {
		case 'A' :
			temp = cup[0];
			cup[0] = cup[1];
			cup[1] = temp;
			break;
		case 'B' :
			temp = cup[1];
			cup[1] = cup[2];
			cup[2] = temp;
			break;
		case 'C' :
			temp = cup[2];
			cup[2] = cup[0];
			cup[0] = temp;
			break;
	}
}

int main(void) {
	string op;
	cin >> op;

	for (int i = 0; i < op.length(); ++i) {
		swap(op[i]);
	}

	if (cup[0] == 1) cout << 1;
	else if (cup[1] == 1) cout << 2;
	else if (cup[2] == 1) cout << 3;
}