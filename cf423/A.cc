#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int vt = b;
    int vo = a;
    int st = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
	int in;
	cin >> in;
	if(in == 1) {
	    if(vo > 0) {
		--vo;
	    } else if(vt > 0) {
		--vt;
		++st;
	    } else if(st > 0) {
		--st;
	    } else {
		++cnt;
	    }
	}
	if(in == 2) {
	    if(vt > 0) {
		--vt;
	    } else {
		++cnt;
		++cnt;
	    }
	}
    }
    cout << cnt << endl;
}
