// https://open.kattis.com/problems/heritage
#include<iostream>
#include<vector>

using namespace std;


long long T[40];
vector<pair<int, int>> it[1005];
long long val[1005];

int main()
{
  int N;
  string W;
  cin >> N >> W;
  for(int i = 0; i < N; ++i) {
    string a;
    cin >> a >> val[i];
    for(int j = 0; j < W.size(); ++j) {
      if(W.substr(j, a.size()) == a) {
	it[i].push_back({j, j + a.size()});
      }
    }
  }
  T[0] = 1;
  for(int i = 1; i <= W.size(); ++i) {
    for(int j = 0; j < N; ++j) {
      for(int k = 0; k < it[j].size(); ++k) {
	if(it[j][k].second == i) {
	  T[i] = (T[i] + val[j] * T[it[j][k].first]) % 1000000007;
	}
      }
    }
  }
  cout << T[W.size()] << endl;
}
