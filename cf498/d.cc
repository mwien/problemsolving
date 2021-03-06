// TAGS: AD HOC
// Problem: http://codeforces.com/contest/1006/problem/D

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int Ta[100005][26];
int Tb[100005][26];

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < n/2; ++i) {
	++Ta[i][a[i]-'a'];
	++Ta[i][a[n-i-1]-'a'];
	++Tb[i][b[i]-'a'];
	++Tb[i][b[n-i-1]-'a'];
    }
    for(int i = 0; i < n/2; ++i) {
	int cnta = 0, cntb = 0, cntc = 0;
	for(int j = 0; j < 26; ++j) {
	    int tmp = min(Tb[i][j], Ta[i][j]);
	    Tb[i][j] -= tmp;
	    Ta[i][j] -= tmp;
	    if(Tb[i][j] % 2 == 1) {
		++cntb;
	    }
	    if(Ta[i][j] % 2 == 1) {
		++cnta;
	    }
	}
	if(cntb == 0) cnt += cnta / 2;
	else if(cnta == 0)  cnt += cntb;
	else cnt += cnta;
    }

    if(n % 2 == 1) {
	if(a[n/2] != b[n/2]) ++cnt;
    }
    cout << cnt << endl;
}
