#include<iostream>
#include<algorithm>

using namespace std;

string a[105];
long long b[105];
int n;

void outprint()
{
    for(int i = 0; i < n; ++i) {
	cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
	if(i > 0) {
	    if(a[i].size() == 1) {
		for(int j = 0; j < n; ++j) {
		    b[j] = stoll(a[j]);
		}
		string tmp = a[i];
		tmp[0] = '0';
		b[i] = stoll(tmp);
		if(!is_sorted(b, b+n)) {
		    outprint();
		    return 0;
		}
	    } else {
		for(int j = 0; j < n; ++j) {
		    b[j] = stoll(a[j]);
		}
		string tmp = a[i];
		tmp[0] = '1';
		b[i] = stoll(tmp);
		if(!is_sorted(b, b+n)) {
		    outprint();
		    return 0;
		}
		tmp = a[i];
		tmp[1] = '0';
		b[i] = stoll(tmp);
		if(!is_sorted(b, b+n)) {
		    outprint();
		    return 0;
		}
	    }
	}
	if(i < n-1) {
	    for(int j = 0; j < n; ++j) {
		b[j] = stoll(a[j]);
	    }
	    string tmp = a[i];
	    tmp[0] = '9';
	    b[i] = stoll(tmp);
	    if(!is_sorted(b, b+n)) {
		outprint();
		return 0;
	    }
	}
    }
    cout << "impossible" << endl;
}
