#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int l[1005];
int r[1005];
vector<int> g;
int p;

int findpg(int c, vector<int> &ps) {
  ps.clear();
  for(int i = 0; i < g.size(); ++i) {
    if(g[i] >= l[c] && g[i] <= r[c]) {
      ps.push_back(g[i]);
    }
  }
  return ps.size();
}

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  cin >> p;
  for(int i = 0; i < p; ++i) {
    int a;
    cin >> a;
    g.push_back(a);
  }
  for(int i = 0; i < n; ++i) {
    vector<int> ps;
    if(findpg(i, ps) >= 3) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  vector<int> np;
  for(int i = 0; i < n; ++i) {
    vector<int> ps;
    while(findpg(i, ps) < 2) {
      // end poss
      if(find(ps.begin(), ps.end(), r[i]) == ps.end()) {
	vector<int> nps;
	if(i == n-1 || findpg(i+1, nps) < 2) {
	  g.push_back(r[i]);
	  np.push_back(r[i]);
	  continue;
	}
      }
      for(int j = l[i]+1; j < r[i]; ++j) {
	if(find(ps.begin(), ps.end(), j) == ps.end()) {
	  g.push_back(j);
	  np.push_back(j);
	  break;
	}
      }
    }
  }
  cout << np.size() << endl;
  for(int i = 0; i < np.size(); ++i) {
    cout << np[i] << " ";
  }
  cout << endl;
}
