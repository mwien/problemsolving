#include<iostream>

using namespace std;

int main() {
    while(true) {
	long long N;
	cin >> N;
	if(N == 0) break;
	--N;
	int mod = 0;
	while(N > 2) {
	    mod += N % 3;
	    mod %= 3;
	    N /= 3;
	}
	int res = N + mod;
	res %= 3;
	if(res == 0) cout << "P" << endl;
	if(res == 1) cout << "S" << endl;
	if(res == 2) cout << "R" << endl;
    }
}
