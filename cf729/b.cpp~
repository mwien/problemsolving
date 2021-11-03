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
	int n;
	cin >> n;
	freq[0] = 0;
	freq[1] = 0;
	for(int i = 0; i < 2*n; ++i) {
	    int a;
	    cin >> a;
	    ++freq[a%2];
	}
	if(freq[0] == freq[1]) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
    }
}
