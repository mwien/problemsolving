#include<iostream>

using namespace std;

int c[1005];
long long T[1005][1005];

long long hi = (1LL << 60);

int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
	cin >> c[i];
    }
    for(int i = 0; i <= N; ++i) {
	for(int j = 0; j <= N; ++j) {
	    T[i][j] = hi;
	}
    }
    T[2][1] = c[2];
    for(int j = 1; j <= N; ++j) {
	for(int i = N; i >= 1; --i) {
	    long long a = hi, b = hi;
	    if(i + j <= N) b = T[i+j][j];
	    if(i - j >= 1) a = T[i-j][j-1];
	    long long cb = min(a,b);
	    if(cb != hi) {
		T[i][j] = cb + c[i];
	    }
	}
    }

    // for(int i = 0; i <= N; ++i) {
    // 	for(int j = 0; j <= N; ++j) {
    // 	    cout << T[j][i] << " ";
    // 	}
    // 	cout << endl;
    // }
    long long res = hi;
    for(int j = 1; j <= N; ++j) {
	res = min(res, T[N][j]);
    }
    cout << res << endl;
}
