#include<iostream>

using namespace std;

int T[100005];
int Tand[100005];

int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	++T[a];
    }
    for(int i = 0; i <= 100000; ++i) {
	if(T[i] >= 2) {
	    cout << 0 << endl;
	    return(0);
	}
    }
    for(int i = 0; i <= 100000; ++i) {
	if((i & x) != i) {
	    Tand[i & x] += T[i];
	}
    }
    for(int i = 0; i <= 100000; ++i) {
	if(Tand[i] > 0 && T[i] > 0) {
	    cout << 1 << endl;
	    return(0);
	}
    }
    for(int i = 0; i <= 100000; ++i) {
	if((i & x) == i) {
	    Tand[i & x] += T[i];
	}
    }
    for(int i = 0; i <= 100000; ++i) {
	if(Tand[i] > 1) {
	    cout << 2 << endl;
	    return(0);
	}
    }
    cout << -1 << endl;
}
