#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long sz = (1LL << n);
    while(k != sz/2) {
	--n;
	if(k > sz/2) {
	    k -= sz/2;
	}
	sz /= 2;
    }
    cout << n << endl;
}
