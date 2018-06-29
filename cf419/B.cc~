#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

bool pal[24*60];

int main() {
  int a, b;
  char c;
  cin >> a >> c >> b;
  for(int i = 0; i < 24; ++i) {
    for(int j = 0; j < 60; ++ j) {
      string f = to_string(i), s = to_string(j);
      if(f.size() < 2) {
	f = "0" + f;
      }
      if(s.size() < 2) {
	s = "0" + s;
      }
      if(f[0] == s[1] && f[1] == s[0]) {
	pal[i*60+j] = true;
      }
    }
  }
  int cnt = 0;
  for(int i = a*60+b; ;++i) {
    if(pal[i % (24*60)]) {
      cout << cnt <<endl;
      break;
    }
    ++cnt;
  }
}
