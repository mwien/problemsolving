#include<iostream>
#include<algorithm>

using namespace std;

int fr[405];
int g[405][405];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < n; ++j) {
	    cin >> g[i][j];
	}
    }
    fr[0] = 10;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < n; ++j) {
	    if(fr[j] == 0) continue;
	    for(int k = 0; k < n; ++k) {
		fr[k] = max(fr[k], g[k][j]);
	    }
	}
    }
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
	sum += fr[i];
    }
    cout << sum << endl;
}
