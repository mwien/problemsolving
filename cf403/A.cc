#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int T[100005];

int main()
{
    int n;
    cin >> n;
    int tb = 0, mx = 0;
    for(int i = 0; i < 2*n; ++i) {
	int a;
	cin >> a;
	if(T[a] == 0) {
	    ++tb;
	    mx = max(tb, mx);
	    T[a] = 1;
	} else if(T[a] == 1) {
	    --tb;
	    T[a] = 2;
	}
    }
    cout << mx << endl;
}
