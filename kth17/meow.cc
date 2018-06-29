#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int mx = 1;
    for(int i = 2; ;++i) {
	long long div = n;
	bool poss = true;
	for(int j = 0; j < 9; ++j) {
	    div /= i;
	}
	if(div == 0) break;
	div = n;
	for(int j = 0; j < 9; ++j) {
	    if(div % i == 0) {
		div /= i;
	    } else {
		poss = false;
		break;
	    }
	}
	if(poss) mx = i;
    }
    cout << mx << endl;
}
