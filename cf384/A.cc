#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string ap;
    cin >> ap;
    char h = ap[a-1], g = ap[b-1];
    int mn = n;
    for(int i = 0; i < n; ++i) {
	if(h == ap[i] && (abs(b-1-i) < mn)) {
	    mn = abs(b-1-i);
	}
	if(g == ap[i] && (abs(a-1-i) <mn)) {
	    mn = abs(a-1-i);
	}
    }
    cout << mn << endl;
}
