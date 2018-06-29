#include<iostream>
#include<string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  bool odd = true;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; j+=2) {
      bool pal = true;
      for(int k = 0; k <= j-i; ++k) {
	if(s[i+k] != s[j-k]) {
	  pal = false;
	  break;
	}
      }
      if(pal) {
	odd = false;
      }
    }
  }
  cout << (odd ? "Odd." : "Or not.") << endl;
}
