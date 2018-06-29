#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 1;
    char ud = 'S', lr = 'S';
    for(int i = 0; i < n; ++i) {
	if(s[i] == 'U' || s[i] == 'D') {
	    if(ud == 'S') {
		ud = s[i];
	    } else if(ud != s[i]) {
		++cnt;
		lr = 'S';
		ud = s[i];
	    }
	} else if(s[i] == 'L' || s[i] == 'R') {
	    if(lr == 'S') {
		lr = s[i];
	    } else if(lr != s[i]) {
		++cnt;
		ud = 'S';
		lr = s[i];
	    }
	}
    }
    cout << cnt << endl;
}
