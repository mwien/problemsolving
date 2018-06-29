#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int calc(long long n) {
    for(long long i = n/2; i <= 3*n/2+1; ++i) {
	if((2*i - n) == 0) continue; 
	for(long long j = n*i / (2*i-n); j <= 2*i*n / (2*i-n); ++j) {
	    if(j < 0) break;
	    if(i == j) continue;
	    if((2*i*j - n*j - n*i) != 0 && ((n*i*j) % (2*i*j - n*j - n*i)) == 0) {
		long long z = (n*i*j) / (2*i*j - n*j - n*i);
		if(z == i || z == j || z > 1000000000LL) {
		    continue;
		}
		cout << i << " " << j << " " << z << endl;
		return 0;
	    }
	}
    }
    return -1;
}

int main()
{
    long long n;
    cin >> n;
    if(calc(n) != 0) {
	cout << -1 << endl;
    }
}
