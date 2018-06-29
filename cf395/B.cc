#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
	int b;
	cin >> b;
	a.push_back(b);
    }
    for(int i = 0; i < n; ++i) {
	if(i < n/2) {
	    if(i % 2 == 0) {
		cout << a[n-i-1] << " ";
	    } else {
		cout << a[i] << " ";
	    }
	} else if(i >= n/2) {
	    if((n-i) % 2 == 1) {
		cout << a[n-i-1] << " ";
	    } else {
		cout << a[i] << " ";
	    }
	}
    }
    cout << endl;
}
