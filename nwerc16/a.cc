#include<iostream>
#include<string>

using namespace std;

pair<int, int> T[40][40][400][10];

string S[40];

int n, m;

void backtrack(int left, int right, int idx, int dig)
{
    if(idx == m || left > right) return;
    int besti = T[left][right][idx][dig].second;
    // set string values according to best solution
    for(int j = left; j <= besti; ++j) {
	S[j][idx] = '0' + dig;
    }
    backtrack(left, besti, idx + 1, 0);
    backtrack(besti+1, right, idx, dig + 1);
}


int solve(int left, int right, int idx, int dig)
{
    if(idx == m || left > right) return 0;
    if(T[left][right][idx][dig].first != -1) return T[left][right][idx][dig].first;
    int mn = 50*500;
    int mni = -1;
    for(int i = left-1; i <= right; ++i) {
	if(dig == 9 && i < right) continue;
	int a = 0;
	// cost of setting in string range [left, i] at index idx to dig
	for(int j = left; j <= i; ++j) {
	    if(S[j][idx] != ('0' + dig)) a += 1;
	}
	// recursive cost calculation
	a += solve(left, i, idx + 1, 0);
	a += solve(i+1, right, idx, dig+1);
	if(a < mn) {
	    mn = a;
	    mni = i;
	}
    }
    // after computation, set memoization table, also set mni for backtracking later
    T[left][right][idx][dig] = {mn, mni};
    return mn;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
	cin >> S[i];
    }

    // init memoization table T
    for(int i = 0; i < n; ++i) {
	for(int j = i; j < n; ++j) {
	    for(int k = 0; k < m; ++k) {
		for(int l = 0; l < 10; ++l) {
		    T[i][j][k][l] = {-1, -1};
		}
	    }
	}
    }
    solve(0, n-1, 0, 0);
    backtrack(0, n-1, 0, 0);
    for(int i = 0; i < n; ++i) {
	cout << S[i] << endl;
    }
}
