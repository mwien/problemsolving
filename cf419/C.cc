#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int grid[101][101];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  string out = "";
  int mv = 0;
  if(m > n) {
    for(int i = 0; i < n; ++i) {
      int mn = 1000;
      for(int j = 0; j < m; ++j) {
	mn = min(mn, grid[i][j]);
      }
      for(int j = 0; j < mn; ++j) {
	out += "row " + to_string(i+1) + "\n";
	++mv;
      }
      for(int j = 0; j < m; ++j) {
	grid[i][j] -= mn;
      }
    }
    for(int i = 0; i < m; ++i) {
      int mn = 1000;
      for(int j = 0; j < n; ++j) {
	mn = min(mn, grid[j][i]);
      }
      for(int j = 0; j < mn; ++j) {
	out += "col " + to_string(i+1) + "\n";
	++mv;
      }
      for(int j = 0; j < n; ++j) {
	grid[j][i] -= mn;
      }
    }
  } else {
    for(int i = 0; i < m; ++i) {
      int mn = 1000;
      for(int j = 0; j < n; ++j) {
	mn = min(mn, grid[j][i]);
      }
      for(int j = 0; j < mn; ++j) {
	out += "col " + to_string(i+1) + "\n";
	++mv;
      }
      for(int j = 0; j < n; ++j) {
	grid[j][i] -= mn;
      }
    }
    for(int i = 0; i < n; ++i) {
      int mn = 1000;
      for(int j = 0; j < m; ++j) {
	mn = min(mn, grid[i][j]);
      }
      for(int j = 0; j < mn; ++j) {
	out += "row " + to_string(i+1) + "\n";
	++mv;
      }
      for(int j = 0; j < m; ++j) {
	grid[i][j] -= mn;
      }
    }
  }
  bool poss = true;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(grid[i][j] != 0) {
	poss = false;
	break;
      }
    }
  }
  if(poss) {
    cout << mv << endl;
    cout << out;
  } else {
    cout << -1 << endl;
  }
}
