#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int A[1005];
bool vis[1005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
	int b;
	cin >> A[i] >> b;
	if(b != n) {
	    cout << "NO" << endl;
	    return 0;
	}
    }
    sort(A, A+n-1);
    int last = -1;
    for(int i = 0; i < n-1; ++i) {
	if(A[i] <= i) {
	    cout << "NO" << endl;
	    return 0;
	}
    }
    cout << "YES" << endl;
    for(int i = 0; i < n-1; ++i) {
	if(i > 0 && A[i] == A[i-1]) {
	    for(int j = 1; j < A[i]; ++j) {
		if(!vis[j]) {
		    cout << last << " " << j << endl;
		    vis[j] = true;
		    last = j;
		    break;
		}
	    }
	}
	if(i > 0 && A[i] != A[i-1]) {
	    vis[A[i]] = true;
	    cout << last << " " << A[i] << endl;
	    last = A[i];
	}
	if(i == 0) {
	    last = A[i];
	    vis[A[i]] = true;
	}
	
    }
    cout << last << " " << n << endl;
}
