#include<iostream>

using namespace std;

int a[9][50000][8];

int fac(int f) {
    if(f > 1)
	return f * fac(f-1);
    return 1;
}

int main()
{
    int N;
    cin >> N;
    a[1][0][0] = 1;
    for(int i = 2; i <= N; ++i) {
	int p = fac(i-1);
	int ind = i-1;
	for(int j = 0; j < p; ++j) {
	    for(int k = 0; k < i; ++k) {
		int sec = 0;
		for(int l = 0; l < i-1; ++l, ++sec) {
		    if(l == ind) ++sec;
		    a[i][j*i + k][sec] = a[i-1][j][l];
		}
		a[i][j*i+k][ind] = i;
		if(k == i-1) continue;
		if(j % 2 == 0) --ind;
		else ++ind;
	    }
	}
    }
    int p = fac(N);
    for(int i = 0; i < p; i++) {
	for(int j = 0; j < N; j++) {
	    if(j != 0) cout << " ";
	    cout << a[N][i][j];
	}
	cout << endl;
    }
}
