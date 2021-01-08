#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string buffer = "CAMBRIDGE";
	string input;
	cin >> input;
	string::iterator input_iter = input.begin();
	while (input_iter != input.end()) {
		string::iterator buffer_iter = buffer.begin();
		while (buffer_iter != buffer.end()) {
			if (*input_iter == *buffer_iter)
				break;
			buffer_iter++;
		}
		if (buffer_iter == buffer.end())
			cout << *input_iter;
		input_iter++;
	}
	return 0;
}