#include<iostream>
#include<vector>

using namespace std;

int T[2005][2005];
int P[2005][2005];

int main()
{
  int C, n;
  while(cin >> C) {
    cin >> n;
    for(int i = 0; i <= n; ++i) {
      for(int j = 0; j <= C; ++j) {
	T[i][j] = -1;
	P[i][j] = -1;
      }
    }
    T[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
      int v, w;
      cin >> v >> w;
      for(int j = 0; j <= C; ++j) {
	T[i][j] = T[i-1][j];
	P[i][j] = j;
      }
      for(int j = w; j <= C; ++j) {
	if(T[i-1][j - w] + v > T[i][j]) {
	  T[i][j] = T[i-1][j-w] + v;
	  P[i][j] = j-w;
	}
      }
    }
    int mx = -1, mxi = -1;
    for(int i = 0; i <= C; ++i) {
      if(mx < T[n][i]) {
	mx = T[n][i];
	mxi = i;
      }
    }
    int j = mxi;
    vector<int> res;
    for(int i = n; i >= 0; --i) {
      if(P[i][j] == -1) {
	break;
      }
      if(P[i][j] != j) {
	res.push_back(i-1);
	j = P[i][j];
      }
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
}
