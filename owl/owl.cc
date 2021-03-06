#include<iostream>

using namespace std;

int qs(int N)
{
    int sum = 0;
    while(N != 0) {
	sum += (N % 10);
	N /= 10;
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
	int N;
	cin >> N;
	int fac = 1;
	int cmp = qs(N);
	int res = 0;
	while(fac <= N) {
	    if(qs(N-fac) == cmp-1) {
		res = N-fac;
		break;
	    }
	    fac *= 10;
	}
	cout << res << endl;
    }
}
