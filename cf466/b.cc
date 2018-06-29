#include<iostream>

using namespace std;

int main()
{
    long long n, k, A, B;
    cin >> n >> k >> A >> B;
    long long cost = 0;
    if(k == 1) cout << (n-1) * A << endl;
    else {
	while(n > 1) {
	    long long tm = (n-1) * A;
	    long long nt = (n%k) * A;
	    if(nt == 0) nt = (n - n/k)*A;
	    if((n%k) == 0) {
		if(tm <= B && tm <= nt) {
		    cout << cost + tm << endl;
		    return 0;
		} else if(B < nt) {
		    n /= k;
		    cost += B;
		} else {
		    n /= k;
		    cost += nt;
		}
	    } else {
		if(tm <= nt) {
		    cout << cost + tm << endl;
		    return 0;
		} else {
		    n -= (n%k);
		    cost += nt;
		}
	    }
	}
    }
    cout << cost << endl;
}
