//TAGS: DP OPTIMIZATION, DIVIDE AND CONQUER

#include<iostream>

using namespace std;

long long A[2005];
long long C[2005][2005];
long long pre[2005];
long long pres[2005];
long long T[2005][2005];

long long calcerr(long long i, long long j, long long idx, long long l)
{
    return (pres[j] - pres[i-1]) - 2*idx*(pre[j] - pre[i-1]) + l*idx*idx;
}

void optdp(int i, int jleft, int jright, int kleft, int kright)
{
    if(jleft > jright) return;
    int jmid = (jleft + jright) / 2;
    T[i][jmid] = (1LL << 62);
    int bestk = -1;
    for(int k = kleft; k <= kright && k < jmid; ++k) {
	if(T[i-1][k] + C[k+1][jmid] < T[i][jmid]) {
	    T[i][jmid] = T[i-1][k] + C[k+1][jmid];
	    bestk = k;
	}
    }
    optdp(i, jleft, jmid-1, kleft, bestk);
    optdp(i, jmid+1, jright, bestk, kright);
}

int main()
{
    int n, g, k;
    cin >> n >> g >> k;
    for(int i = 1; i <= n; ++i) {
	cin >> A[i];
    }
    for(int i = 1; i <= n; ++i) {
	pre[i] = pre[i-1] + A[i];
	pres[i] = pres[i-1] + A[i]*A[i];
    }
    if(k == 1) {
	for(int i = 1; i <= n; ++i) {
	    for(int j = i; j <= n; ++j) {
		long long l = j - i + 1;
		long long idx = i + l/2;
		C[i][j] += (idx-1 - i + 1) * A[idx] - (pre[idx-1] - pre[i-1]);
		C[i][j] += (pre[j] - pre[idx]) - (j - (idx+1) + 1) * A[idx];
	    }
	}
    }
    if(k == 2) {
	for(int i = 1; i <= n; ++i) {
	    for(int j = i; j <= n; ++j) {
		long long l = j - i + 1;
		long long idx = (pre[j] - pre[i-1]) / l;
		C[i][j] = min(calcerr(i, j, idx, l), calcerr(i, j, idx+1, l));
	    }
	}
    }
    for(int j = 1; j <= n; ++j) {
	T[1][j] = C[1][j];
    }
    for(int i = 2; i <= g; ++i) {
	optdp(i, 1, n, 1, n);
    }
    cout << T[g][n] << endl;
}
