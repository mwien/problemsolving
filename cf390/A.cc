#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
	int b;
	cin >> b;
	a.push_back(b);
	sum += b;
    }
    if(sum != 0) {
	cout << "YES" << endl;
	cout << 1 << endl;
	cout << 1 << " " << n << endl;
    } else {
	int ps = 0;
	bool poss = false;
	for(int i = 0; i < n-1; ++i) {
	    ps += a[i];
	    if(ps != 0) {
		cout << "YES" << endl;
		cout << 2 << endl;
		cout << 1 << " " << (i+1) << endl;
		cout << (i+2) << " " << n << endl;
		poss = true;
		break;
	    }
	}
	if(!poss) {
	    cout << "NO" << endl;
	}
    }
}
