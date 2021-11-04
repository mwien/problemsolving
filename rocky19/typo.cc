#include<iostream>
#include<vector>

using namespace std;

long long const prime = 10002331;

vector<string> H[prime];
string w[1000005];
long long pw[1000005];
vector<long long> T[1000005];

bool check(string a, string b, int j) {
  if(b.size() != a.size()-1) return false;
  for(int i = 0; i < j; ++i) {
    if(a[i] != b[i]) {
      return false;
    }
  }
  for(int i = j+1; i < a.size(); ++i) {
    if(a[i] != b[i-1]) {
      return false;
    }
  }
  return true;
}


int main()
{
  pw[0] = 1;
  for(int i = 1; i < 1000005; ++i) {
    pw[i] = (pw[i-1] * 26) % prime;
  }
  long long inve = 9617626;
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> w[i];
    long long h = 0;
    T[i].resize(w[i].size());
    for(int j = 0; j < w[i].size(); ++j) {
      h = (h + (w[i][j] - 'a') * pw[j]) % prime;
      T[i][j] = h;
    }
    //cout << i << " " << h << endl;
    H[h].push_back(w[i]);
  }
  bool flag = false;
  for(int i = 0; i < n; ++i) {
    bool sflag = false;
    for(int j = 0; j < w[i].size(); ++j) {
      long long nh = ((((T[i][j] - (w[i][j] - 'a') * pw[j] + (T[i][w[i].size()-1] - T[i][j]) * inve) % prime) + prime) % prime);
      //cout << i << " " << j << " " << nh << endl;
      for(int k = 0; k < H[nh].size(); ++k) {
	if(check(w[i], H[nh][k], j)) {
	  cout << w[i] << endl;
	  flag = true;
	  sflag = true;
	  break;
	}
      }
      if(sflag) break;
    }
  }
  if(!flag) {
    cout << "NO TYPOS" << endl;
  }
}
