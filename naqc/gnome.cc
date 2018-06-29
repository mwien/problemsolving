#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> &a) {
  bool res = true;
  for(int i = 1; i < a.size(); ++i) {
    if(a[i] <= a[i-1]) res = false;
  }
  return res;
}

int main()
{
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; ++t) {
    int n;
    cin >> n;
    vector <int> b;
    for(int i = 0; i < n; ++i) {
      int c;
      cin >> c;
      b.push_back(c);
    }
    for(int i = 1; i < n-1; ++i) {
      vector<int> a;
      for(int j = 0; j < n; ++j) {
	if(j != i) {
	  a.push_back(b[j]);
	}
      }
      if(check(a)) {
	cout << i + 1 << endl;
	break;
      }
    }
  }
}
