#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int mn = 100005, mni = -1;
    for(int i = 0; i < m-n+1; ++i) {
	int cnt = 0;
	for(int j = 0; j < n; ++j) {
	    if(a[j] != b[i+j]) {
		++cnt;
	    }
	}
	if(mn > cnt) {
	    mn = cnt;
	    mni = i;
	}
    }
    cout << mn << endl;
    for(int i = 0; i < n; ++i) {
	if(a[i] != b[mni + i]) {
	    cout << i + 1 << " ";
	}
    }
    cout << endl;
}
