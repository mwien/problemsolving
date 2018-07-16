// TAGS: AD HOC
// Problem: http://codeforces.com/contest/1006/problem/A

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	if(a % 2 == 1) {
	    cout << a << " ";
	} else {
	    cout << a-1 << " ";
	}
    }
    cout << endl;
}
