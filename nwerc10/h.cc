#include<iostream>

using namespace std;

int main()
{
    int s;
    cin >> s;
    for(int S = 0; S < s; ++S) {
	string a;
	cin >> a;
	int n = a.size();
	int sum = 0;
	int last = n-1;
	for(int i = 0; i < n; ++i) {
	    sum += min(a[i] - 'A', 'Z' - a[i] + 1); ;
	    if(a[i] != 'A') {
		last = i;
	    }
	}
	int first = 0;
	for(int i = n; i > 0; --i) {
	    if(a[i] != 'A') {
		first = i;
	    }
	}
	int mn = min(last, n-first);
	for(int i = 0; i < n; ++i) {
	    if(a[i] != 'A') {
		mn = min(2*(n - i) + last, mn);
		last = i;
	    }
	}
	for(int i = n; i >= 0; --i) {
	    if(a[i] != 'A') {
		mn = min(2*i + (n - first), mn);
		first = i;
		
	    }
	}
	cout << sum + mn << endl;
    }
}
