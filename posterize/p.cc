#include<iostream>
#include<algorithm>

using namespace std;

long long T[260][260];
long long f[260][260];
long long vals[260];

int main()
{
    int d, k;
    cin >> d >> k;
    int p = 256;
    for(int i = 1; i <= d; ++i) {
	int a;
	cin >> a;
	cin >> vals[a+1];
    }
    for(int i = 1; i <= p; ++i) {
	long long sum = 0;
	for(int j = 1; j < i; ++j) {
	    sum += vals[j]*(i - j)*(i - j);
	}
	f[0][i] = sum;
    }
    for(int i = 1; i <= p; ++i) {
	long long sum = 0;
	for(int j = p; j > i; --j) {
	    sum += vals[j]*(i-j)*(i -j);
	}
	f[i][p+1] = sum;
    }
    for(int i = 1; i <= p; ++i) {
	for(int j = i+1; j <= p; ++j) {
	    long long sum = 0;
	    for(int k = i; k <= j; ++k) {
		sum += min(vals[k]*(k - j)*(k - j), vals[k]*(i - k)*(i - k));
	    }
	    f[i][j] = sum;
	}
    }
    for(int i = 1; i <= p; ++i) {
	T[i][0] = f[0][i]; 
    }
    for(int i = 1; i <= p; ++i) {
	for(int j = 1; j < k; ++j) {
	    T[i][j] = (1LL << 62);
	    for(int l = 0; l < i; ++l) {
		T[i][j] = min(T[i][j], T[l][j-1] + f[l][i]);
	    }
	}
    }
    long long mn = (1LL << 62);;
    for(int i = 1; i <= p; ++i) {
	mn = min(mn, f[i][p+1] + T[i][k-1]);
	//cout << mn << " " << i << endl;
    }
    cout << mn << endl;
    for(int i = 0; i <= p; ++i) {
	for(int j = 1; j <= p+1; ++j) {
	    //cout << f[i][j] << " ";
	}
	//cout << endl;
    }
}
