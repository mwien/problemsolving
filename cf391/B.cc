#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int s[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	++s[a];
    }
    int cnt = 1;
    for(int i = 2; i <= 100000; ++i) {
	int nc = 0;
	for(int j = i; j <= 100000; j += i) {
	    if(s[j] > 0) nc += s[j];
	}
	if(nc > cnt) cnt = nc;
    }
    cout << cnt << endl;
}
