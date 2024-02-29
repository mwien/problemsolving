#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int a[200005];
long long T[200005][4][27];
const string mex = "XEM";
int table[27] = {1,2,1,2,2,3,1,3,1,2,2,3,2,0,0,3,0,0,1,3,1,3,0,0,1,0,0};

int mp(int x, int y) 
{
	int res = 1;
	for(int i = 0; i < y; ++i) {
		res *= x;
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> a[i];	
	}
	string s;
	cin >> s;

	for(int i = 0; i < N; ++i) {
	 T[i][0][0] = 1;
	 }
	for(int j = 1; j < 4; ++j) {
		for(int i = N-1; i >= 0; --i) {
			for(int k = 0; k < 27; ++k) {
				T[i][j][k] = T[i+1][j][k];
				int  bk = k - mp(3,j-1)*a[i]; 
				//cout << bk << endl;
				if(s[i] == mex[j-1] && bk >= 0) {
					//cout << "HII " << bk << endl;
					T[i][j][k] += T[i][j-1][bk];
				}
			}
		}
	}
/*	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 27; ++k) {
				cout << T[i][j][k];
				cout << " ";
			}
			cout << endl;
		}
		cout << "-----" << endl;
	}
*/
	long long res = 0;
	for(int i = 0; i < 27; ++i) {
		res += T[0][3][i] * table[i];
	}
	cout << res << endl;
}
