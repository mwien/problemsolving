#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int a[10];

int main()
{
	for(int i = 0; i < 8; ++i) {
		cin >> a[i];	
	}
	for(int i = 1; i < 8; ++i) {
		if(a[i] < a[i-1]) {
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i = 0; i < 8; ++i) {
		if(a[i] < 100 || a[i] > 675) {
			cout << "No" << endl;
			return 0;
		}
		if(a[i] % 25 != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
