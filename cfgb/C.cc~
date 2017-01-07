#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int min = 240 - k;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
	min -= 5*i;
	if(min >= 0) ++cnt;
	else {
	    break;
	}
    }
    cout << cnt << endl;
}
