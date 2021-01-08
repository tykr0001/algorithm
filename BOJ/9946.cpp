#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int count=1;
	string input, output;
	cin >> input >> output;

	while (input != "END" || output != "END") {
		sort(input.begin(), input.end());
		sort(output.begin(), output.end());

		if (input == output)
			cout << "Case " << count++ << ": " << "same" << endl;
		else
			cout << "Case " << count++ << ": " << "different" << endl ;
		cin >> input >> output;
	}
	return 0;
}