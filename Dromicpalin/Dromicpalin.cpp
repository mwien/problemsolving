#include <iostream>
#include <string>
using namespace std;

int main()
{
int T;
cin >> T;
for(int t = 0; t < T; t++) {
    string s;
    cin >> s;
    int n = s.size();
    bool table[n+1][26];
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < 26; j++) {
	    table[i][j] = false;
	}
    }
    for(int i = n-1; i >= 0; i--) {
	for(int j = 0; j < 26; j++) {
	    if(s[i] - 'a' == j) {
		table[i][j] = !table[i+1][j];
	    } else {
		table[i][j] = table[i+1][j];
	    }
	}
    }
    int total = 0;
    for(int i = 0; i < n; i++) {
	for(int j = i; j < n; j++) {
	    int cnt = 0;
	    for(int k = 0; k < 26; k++) {
		bool parity = table[i][k] ^ table[j+1][k];
		if(parity) cnt++;
	    }
	    if(cnt <= 1) total++;
	}
    }
    cout << "Case " << t+1 << ": " << total << endl;
  }
}
