#include<iostream>
#include<string>

using namespace std;

int main()
{
  string line;
  cin >> line;
  long long inv = 0;
  int zeros = 0;
  int questions = 0;
  for(int i = line.size(); i >= 0; --i) {
    if(line[i] == '0') {
      ++zeros;
    }
    if(line[i] == '1') {
      if(questions > 0) {
	inv = (inv + (1 << (questions-1)) * questions) % 1000000007;
      }
      inv = (inv + (1 << questions) * zeros) % 1000000007;
    }
    if(line[i] == '?') {
      inv = (inv * 2) % 1000000007;
      if(questions > 0) {
	inv = (inv + (1 << (questions-1)) * questions) % 1000000007;
      }
      inv = (inv + (1 << questions) * zeros) % 1000000007;
      ++questions;
    }
  }
  cout << inv << endl;
}
