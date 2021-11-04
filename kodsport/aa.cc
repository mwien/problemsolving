#include<iostream>

using namespace std;

int freqs[28];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i) {
	++freqs[s[i]-'a'];
    }
    int split = -1;
    for(int i = 0; i < 26; ++i) {
	if(freqs[i] == n) {
	    cout << -1 << endl;
	    return 0;
	}
	if(freqs[i] > n/2) {
	    split = i;
	    break;
	}
    }
    string out = "";
    int rest = 0;
    if(split != -1) {
	int beg = freqs[split] / 2;
	freqs[split] -= beg;
	rest = freqs[split];m
	freqs[split] = 0;
	for(int i = 0; i < beg; ++i) {
	    out += (char) (split + 'a');
	}
    }
    for(int i = 0; i < 26; ++i) {
	for(int j = 0; j < freqs[i]; ++j) {
	    out += (char) (i + 'a');
	}
    }
    if(split != -1) {
	for(int i = 0; i < rest; ++i) {
	    out += (char) (split + 'a');
	}
    }
    cout << out << endl;
}
