#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	string s;
	cin >> s;
	int n = s.size();
	int i = 0;
	vector<int> res;
	while(i < n) {
	    if(s[i] != 't' && s[i] != 'o') {
		++i;
		continue;
	    } else if(s[i] == 'o' && i+2 < n) {
		if(s[i+1] == 'n' && s[i+2] == 'e') {
		    res.push_back(i+1);
		    i += 3;
		} else {
		    ++i;
		}
	    } else if(s[i] == 't' && i+2 < n) {
		if(s[i+1] == 'w' && s[i+2] == 'o') {
		    if(i+4 < n && s[i+3] == 'n' && s[i+4] == 'e') {
			res.push_back(i+2);
			i += 5;
		    } else {
			res.push_back(i+1);
			i += 3;
		    }
		} else {
		    ++i;
		}
	    } else {
		++i;
	    }
	}
	cout << res.size() << endl;
	for(int j = 0; j < res.size(); ++j) {
	    cout << res[j]+1 << " ";
	}
	cout << endl;
    }
}
