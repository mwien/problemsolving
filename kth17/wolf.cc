#include<iostream>

using namespace std;

bool av[14][4];

int main()
{
    int n;
    cin >> n;
    if(n < 26) {
	cout << "impossible\n";
	return 0;
    }
    if(n > 26) {
	cout << "possible\n";
	return 0;
    }
    for(int i = 0; i < n; ++i) {
	int a;
	string b;
	cin >> a >> b;
	if(b == "C") av[a][0] = true;
	if(b == "D") av[a][1] = true;
	if(b == "H") av[a][2] = true;
	if(b == "S") av[a][3] = true;
    }
    for(int j = 0; j < 4; ++j) {
	int mb = 0;
	int hw = 13;
	for(int i = 1; i <= 13; ++i) {
	    if(av[i][j]) mb = i;
	}
	for(int i = 13; i >= 1; --i) {
	    if(!av[i][j]) hw = i;
	}

	if(mb > hw) {
	    cout << "possible\n";
	    return 0;
	}
    }
    cout << "impossible\n";
}
