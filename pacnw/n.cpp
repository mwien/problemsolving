#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int min_brok = 1;
	int max_brok = k;
	for (int i=0; i<n; i++)  {
		int e;
		string d;
		cin >> e >> d;
		if (d=="SAFE")
			min_brok = max(min_brok, e);
		else
			max_brok = min(max_brok, e);
	}

	cout << min_brok + 1 << " " << max_brok - 1 <<endl;
}
