#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<unordered_map>

using namespace std;

bool isan(char a) {
    if((a >= '0' && a <= '9') || (a >= 'a' && a<= 'z') || (a >= 'A' && a <= 'Z')) return true;
    return false;
}

bool rec(vector<string> &message, vector<vector<int>> &pp, vector<string> &users, int d, int last, vector<string> &names) {
    if(d == message.size()) {
	return true;
    }
    for(int i = 0; i < pp[d].size(); ++i) {
	if(pp[d][i] != last) {
	    int tmp = pp[d][i];
	    users[d] = names[tmp];
	    if(rec(message, pp, users, d+1, tmp, names)) {
		return true;
	    }
	}
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	int n;
	cin >> n;
	unordered_map<string, int> nm;
	vector<string> names;
	for(int i = 0; i < n; ++i) {
	    string a;
	    cin >> a;
	    nm.insert({a, i});
	    names.push_back(a);
	}
	int m;
	cin >> m;
	vector<string> message;
	string empty;
	getline(cin, empty);
	for(int i = 0; i < m; ++i) {
	    string a;
	    getline(cin, a);
	    message.push_back(a);
	}
	vector<vector<int>> pp (m);
	for(int i = 0; i < m; ++i) {
	    if(message[i][0] == '?') {
		vector<bool> imp (n);
		for(int j = 2; j < message[i].size(); ++j) {
		    if(!isan(message[i][j]) || j == 2) {
			int s = j+1;
			++j;
			if(j == 3 && isan(message[i][j-1])) {
			    s = j-1;
			    --j;
			}
			int cnt = 1;
			while(j < message[i].size() &&isan(message[i][j])) {
			    ++j;
			    ++cnt;
			}
			string ch = message[i].substr(s, cnt);
			if(ch.size() > 0 && !isan(ch[ch.size()-1])) {
			    ch = ch.substr(0, ch.size()-1);
			}
			if(!isan(message[i][j])) --j;
			if(nm.find(ch) != nm.end()) {
			    imp[nm[ch]] = true;
			}
		    }
		}
		for(int j = 0; j < n; ++j) {
		    if(!imp[j]) pp[i].push_back(j);
		}
	    } else {
		string ch = "";
		for(int j = 0; j < message[i].size(); ++j) {
		    if(message[i][j] == ':') break;
		    ch += message[i][j];
		}
		if(nm.find(ch) != nm.end()) {
		    pp[i].push_back(nm[ch]);
		}
	    }
	}
	vector<string> users (m);
	if(!rec(message, pp, users, 0, -1, names)) {
	    cout << "Impossible" << endl;
	} else {
	    for(int i = 0; i < m; ++i) {
		if(message[i][0] == '?') {
		    string out = users[i] + message[i].substr(1, message[i].size()-1);
		    cout << out << endl;
		} else {
		    cout << message[i] << endl;
		}
	    }
	}
    }
}
