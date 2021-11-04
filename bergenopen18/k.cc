#include<iostream>

using namespace std;

int T[1005][1005];
bool P[1005][1005];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for(int j = 1; j <= k; ++j) {
      int a;
      cin >> a;
      P[i][a] = true;
    }
  }
  
  for(int i = 1; i <= m; ++i) {
    int l;
    cin >> l;
    int mn = 10005;
    for(int j = 1; j <= n; ++j) {
      mn = min(T[i-1][j], mn);
    }
    for(int j = 1; j <= n; ++j) {
      T[i][j] = min(mn + 1, T[i-1][j]);
      if(!P[j][l]) T[i][j] = 10000;
    }
  }
  int res = 1005;
  for(int i = 1; i <= n; ++i) {
    res = min(res, T[m][i]);
  }
  cout << res << endl;
}
