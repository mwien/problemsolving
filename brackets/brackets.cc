#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{   
    int N;
    long long M;
    cin >> N >> M;
    vector<vector<long long>> T (N+1, vector<long long>(N+1));
    T[0][0] = 0;
    T[0][1] = 0;
    T[0][2] = 0;
    T[1][0] = 0;
    T[1][1] = 1;
    T[1][2] = 0;
    T[2][0] = 1;
    T[2][1] = 0;
    T[2][2] = 1;
    for(int i = 3; i <= N; ++i) {
	for(int j = 0; j <= min(N, i); ++j) {
	    if(j == 0 && i >= 2 && i-2 >= j) T[i][j] = T[i-2][j];
	    else if(j > 0 && i < 2) T[i][j] = T[i-1][j-1];
	    else if(j > 0 && i-2 >= j) T[i][j] = (T[i-2][j] + T[i-1][j-1]) % (1L << 61);
	    else if(j > 0) T[i][j] = T[i-1][j-1];
	    else T[i][j] = 0;
	}
    }
    int open = 0;
    for(int i = 0; i < N; ++i) {
	long long lowp = T[N-i-1][open];
	if(N-i-1 > open) cout << N-i-1 << " " << open << " " << T[N-i-1][open] << endl;
	if(lowp <= M) {
	    ++open;
	    cout << "(";
	} else {
	    --open;
	    M -= lowp;
	    cout << ")";
	}
    }
    cout << endl;
}
