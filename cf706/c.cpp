#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
	int n;
	cin >> n;
	vector<long long> mnr, mns;
	for(int i = 0; i < 2*n; ++i) {
	    int x, y;
	    cin >> x >> y;
	    if(x == 0) mnr.push_back(abs(y));
	    if(y == 0) mns.push_back(abs(x));
	}
	sort(mnr.begin(), mnr.end());
	sort(mns.begin(), mns.end());
	double res = 0;
	for(int i = n-1; i >= 0; --i) {
	    res += sqrt(mnr[i]*mnr[i] + mns[i]*mns[i]);
	}
	printf("%.15f\n", res);
    }
}
