#include<iostream>
#include<string>
#include<vector>

using namespace std;

int cmp[26];

int main()
{
    for(int i = 0; i < 26; ++i) cmp[i] = i;
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    vector<string> opt;
    for(int i = 0; i < n; ++i) {
	if(cmp[a[i] - 'a'] != cmp[b[i] - 'a']) {
	    string nw = "";
	    nw += a[i];
	    nw += " ";
	    nw += b[i];
	    opt.push_back(nw);
	    int ch = cmp[b[i] - 'a'];
	    for(int j = 0; j < 26; ++j) {
		if(cmp[j] == ch) {
		    cmp[j] = cmp[a[i] - 'a'];
		}
	    }
	}
    }
    cout << opt.size() << endl;
    for(int i = 0; i < opt.size(); ++i) {
	cout << opt[i] << endl;
    }
}
