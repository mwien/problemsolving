#include<iostream>

using namespace std;

bool tr[26][26];
bool ed[26][26];

int main() {
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; ++i) {
	char a, b;
	cin >> a >> b;
	ed[a - 'a'][b - 'a'] = true;
    }
    for(int i = 0; i < 26; ++i) {
	tr[i][i] = true;
    }
    for(int c = 0; c < 26; ++c) {	
	for(int i = 0; i < 26; ++i) {
	    for(int j = 0; j < 26; ++j) {
		for(int k = 0; k < 26; ++k) {
		    if(tr[i][j] && ed[j][k]) tr[i][k] = true;
		}
	    }
	}
    }
    for(int i = 0; i < n; ++i) {
	string a, b;
	cin >> a >> b;
	bool poss = true;
	if(a.size() != b.size()) poss = false;
	else {
	    for(int i = 0; i < a.size(); ++i) {
		if(!tr[a[i]-'a'][b[i]-'a']) {
		    poss = false;
		    break;
		}
	    }
	}
	cout << (poss ? "yes" : "no") << endl;
    }
}
