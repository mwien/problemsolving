//TAGS: MATH, DP

#include<iostream>
 
using namespace std;
 
const int ml = 1000000;
 
long long P[ml+1][2];
 
int main()
{
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; ++t) {
        long long n, m;
        cin >> n >> m;
        P[1][0] = 1;
        P[1][1] = 1;
        for(int i = 2; i <= n; ++i) {
            P[i][0] = (P[i-1][0] + P[i-1][1]) % m;
            P[i][1] = P[i-1][0] % m;
        }
        if(n % 2 == 0) {
            long long nfac = 1, nhfac = 1;
	    long long cnt = 0;
            for(int i = 2; i <= n/2; ++i) {
		if(i % m == 0) {
		    int tmp = i;
		    while(tmp % m == 0) {
			tmp /= m;
			++cnt;
		    }
		    nhfac = (nhfac * tmp) % m;
		} else {
		    nhfac = (nhfac * i) % m;
		}
            }
	    for(int i = n/2+1; i <= n; ++i) {
		if(i % m == 0) {
		    int tmp = i;
		    while(tmp % m == 0) {
			tmp /= m;
			--cnt;
		    }
		    nfac = (nfac * tmp) % m;
		} else {
		    nfac = (nfac * i) % m;
		}
            }

	    if(cnt < 0) {
		nfac = 0;
	    }
	    if(cnt > 0) {
		nhfac = 0;
	    }

	    //cout << nfac << " " << nhfac << endl;
            //nhfac = (nhfac * nhfac) % m;
 
            long long a = nhfac, b = m-2;
            long long x=1, y=a;
            while (b > 0) {
                if (b % 2 == 1) {
                    x = (x*y) % m; // multiplying with base
                }
                y = (y*y) % m; // squaring the base
                b /= 2;
            }
 
            long long res = x % m;
           
            long long eq = (res * nfac) % m;
            //cout << ((((eq + P[n][0] + P[n][1] - (n/2 + 1)) % m) + m) % m) << " " << eq << " " << (P[n][0] + P[n][1]) % m << endl;
            long long con = (P[n][0] + P[n][1]) % m;
            long long ol = (n/2 + 1) % m;
	    //cout << n << " ";
            cout << ((eq + con + (m - ol)) % m) << endl;
	    //cout << eq << " " << con << endl;
        } else {
            cout << (P[n][0] + P[n][1]) % m << endl;
        }
    }
}
