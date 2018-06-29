#include<iostream>
#include<string>
#include<vector>

using namespace std;

int conv(char a) {
  return (a == ' ' ? 0 : a - 'a' + 1);
}

int main()
{
  int n;
  cin >> n;
  for(int tc = 0; tc < n; ++tc) {
    char cs;
    cin >> cs;
    string ln;
    getline(cin, ln);
    ln.erase(ln.begin());
    if(cs == 'e') {
      vector<int> out;
      out.push_back(ln[0] - 'a' + 1);
      for(int i = 1; i < ln.size(); ++i) {
	if(ln[i] == ' ') {
	  out.push_back(out[i-1]);
	} else {
	  out.push_back(ln[i] - 'a' + 1 + out[i-1]);
	}
      }
      string res = "";
      for(int i = 0; i < out.size(); ++i) {
	if((out[i] % 27) == 0) {
	  res += " ";
	} else {
	  res += 'a' + (out[i] % 27) - 1;
	}
      }
      cout << res << endl;
    } else if(cs == 'd') {
	vector<int> out;
	out.push_back(ln[0] - 'a' + 1);
	for(int i = 1; i < ln.size(); ++i) {
	  out.push_back(conv(ln[i]) - conv(ln[i-1]) + 27);
	}
	string res = "";
	for(int i = 0; i < out.size(); ++i) {
	  if(out[i] % 27 == 0) {
	    res += " ";
	  } else {
	    res += 'a' + (out[i] % 27) - 1;
	  }
	}
	cout << res << endl;
      }
  }
}
