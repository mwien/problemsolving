#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

int freq[2];

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	long long n, a, b;
	cin >> n >> a >> b;
	if(a == 1) {
	    if(((n - 1) % b) == 0) {
		cout << "Yes" << endl;
	    } else {
		cout << "No" << endl;
	    }
	} else {
	    long long x = 1;
	    bool done = false;
	    while(x <= n) {
		if(((n - x) % b) == 0) {
		    cout << "Yes" << endl;
		    done = true;
		    break;
		} 
		x *= a;
	    }
	    if(!done)
	    cout << "No" << endl;
	}
    }
}
