#include<iostream>

using namespace std;

int main()
{
    string t;
    cin >> t;
    int n = t.size();
    for(int i = 0; i < n/3; ++i) {
	if(t[i] == t[i+n/3]) {
	    cout << t[i];
	} else {
	    cout << t[i+2*n/3];
	}
    }
    cout << endl;
}
