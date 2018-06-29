#include<iostream>

using namespace std;

const int lim = 2000001;

int c[105];
int T[lim];
int G[lim];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> c[i];
    }
    for(int i = 1; i < lim; ++i) {
	T[i] = (1 << 30);
    }
    // optimal solution
    for(int i = 0; i < lim; ++i) {
	if(T[i] == (1 << 30)) continue;
	for(int j = 0; j < n; ++j) {
	    if(c[j] + i < lim) {
		T[i + c[j]] = min(T[i+c[j]], T[i]+1);
	    }
	}
    }
    // greedy solution
    for(int i = 0; i < lim; ++i) {
	for(int j = n-1; j >= 0; --j) {
	    if(c[j] + i < lim && G[i + c[j]] == 0) {
		G[i + c[j]] = G[i] + 1;
	    }
	}
    }
    bool can = true;
    for(int i = 1; i < lim; ++i) {
	if(G[i] != T[i]) {
	    can = false;
	    break;
	}
    }
    cout << (can ? "canonical" : "non-canonical") << endl;
}
