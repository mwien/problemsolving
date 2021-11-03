#include<iostream>

using namespace std;

int main()
{
    long long u, v;
    cin >> u >> v;
    if(u == 0 && v == 0) {
	cout << 0 << endl;
	return 0;
    }
    if(u == v) {
	cout << 1 << " " << u << endl;
	return 0;
    }
    long long diff = v - u;
    if(diff < 0) {
	cout << -1 << endl;
    } else {
	long long hl = diff / 2;
	if(((u + hl) ^ hl) == u) {
	    cout << 2 << endl;
	    cout << u + hl << " " << hl << endl;
	    return 0;
	}
	if(u + (diff / 2) + (diff/2) == v) {
	    cout << 3 << endl;
	    cout << u << " " << (diff / 2) << " " << (diff / 2) << endl;
	    return 0;
	}
	cout << -1 << endl;
    }
}
