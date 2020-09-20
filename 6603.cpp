#include<iostream>
#include<vector>

using namespace std;

int combination(vector<int>& arr, vector<bool>& mask, int k, int index, int level) {
	if (level == 6) {
		for (int i = 0; i < k; ++i) {
			if (mask[i] == true) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}
	else if (index == k) {
		return -1;
	}
	else {
		for (int i = index; i < k; ++i) {
			mask[i] = true;
			combination(arr, mask, k, i+1, level+1);
			mask[i] = false;
		}
	}
	return 0;
}

int main(void) {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> arr(k);
		vector<bool> mask(k, false);
		for (int i = 0; i < k; ++i) {
			cin >> arr[i];
		}

		combination(arr,mask,k,0,0);
		cout << endl;
	}
	return 0;
}