#include<iostream>

using namespace std;

long long c[35];

int main()
{
    int n;
    long long L;
    cin >> n >> L;
    for(int i = 0; i < n; ++i) {
	cin >> c[i];
    }
    for(int i =1; i < n; ++i) {
	if(2*c[i-1] < c[i]) c[i] = 2*c[i-1];
    }
    long long mn = (1LL << 62);
    long long rest = L;
    long long cst = 0;
    for(int i = n-1; i >= 0; --i) {
	long long nm = rest / (1LL << i);
	rest -= nm*(1LL << i);
	cst += nm*c[i];
	if(rest > 0) {
	    if(cst + c[i] < mn) {
		mn = cst + c[i];
	    }
	} else {
	    if(cst < mn) {
		mn = cst;
	    }
	}
    }
    cout << mn << endl;
}
