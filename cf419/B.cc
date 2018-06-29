#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int fw[200001];

int read(int index) {
   int sum = 0;
   while (index > 0) {
      sum += fw[index];
      index -= (index & -index);
   }
   return sum;
}

void update(int index, int addValue, int size) {
   while (index <= size) {
      fw[index] += addValue;
      index += (index & -index);
   }
}

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<pair<int, int>> rc;
  for(int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    rc.push_back({a, 0});
    rc.push_back({b, 1});
  }
  sort(rc.begin(), rc.end());
  int open = 0;
  int ind = 0;
  for(int i = 1; i <= 200000; ++i) {
    if(ind >= rc.size()) break;
    while(ind < rc.size() && rc[ind].first == i && rc[ind].second ==0) {
      ++open;
      ++ind;
    }
    if(open >= k) {
      update(i, 1, 200000);
    }
    while(ind < rc.size() && rc[ind].first == i && rc[ind].second ==1) {
      --open;
      ++ind;
    }
  }
  for(int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << read(b) - read(a-1) << endl;
  }
}
