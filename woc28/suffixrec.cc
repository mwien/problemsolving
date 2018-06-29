#include<iostream>
#include<algorithm>

using namespace std;

int rec(string &st, string s, int i) {
    if(i == s.size()) return 0;
    int mn = s.size();
    if(s[i] != st[i]) {
	for(int j = i+1; j < s.size(); ++j) {
	    if(s[j] == st[i]) {
		string nw = s.substr(0, i);
		for(int k = 0; k < s.size() - i; ++k) {
		    nw += s[((k + j - i) % (s.size() - i)) + i];
		}
		mn = min(mn, rec(st, nw, i+1));
	    }
	}
	return mn + 1;
    } else {
	return rec(st, s, i+1);
    }
}

int main()
{
    int g;
    cin >> g;
    for(int i = 0; i < g; ++i) {
	string s;
	cin >> s;
	string st;
	st = s;
	sort(st.begin(), st.end());
	cout << rec(st, s, 0) << endl;
    }
}
