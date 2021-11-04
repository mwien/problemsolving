#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int p[200005];
int r[200005];

int find(int x) {
    int root = x;
    while (p[root] >= 0) { // find root
        root = p[root];
    }
    while (p[x] >= 0) { // path compression
        int tmp = p[x];
        p[x] = root;
        x = tmp;
    }
    return root;
}

// return true, if sets merged and false, if already from same set
bool un(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py)
        return false; // same set -> reject edge
    if (r[px] < r[py]) { // swap so that always h[px]>=h[py]
        int tmp = px;
        px = py;
        py = tmp;
    }
    p[py] = px; // hang flatter tree as child of higher tree
    r[px] = max(r[px], r[py] + 1); // update (worst-case) height
    // if needed use count here
    // count--;
    return true;
}

int main()
{
  int n;
  cin >> n;

  for(int i = 0; i < n; ++i) {
    p[i] = -1;
  }
  
  unordered_map<int,int> t;
  vector<vector<int>> sol;
  for(int i = 0; i < n; ++i) {
    int mi;
    cin >> mi;
    int done = false;
    for(int j = 0; j < mi; ++j) {
      int a;
      cin >> a;
      if(t.find(a) == t.end()) {
	t[a] = i;
      } else {
	if(un(i, t[a])) {
	  sol.push_back({i, t[a], a});
	}
      }
    }
  }
  if(sol.size() != n-1) {
    cout << "impossible" << endl;
  } else {
    for(int i = 0; i < n-1; ++i) {
      cout << sol[i][0]+1 << " " << sol[i][1] + 1 << " " << sol[i][2] << endl;
    }
  }
}
