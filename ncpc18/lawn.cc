#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int l, m;
    cin >> l >> m;
    string dump;
    getline(cin, dump);
    int mn = 100005;
    vector<string> mns;
    for(int i = 0; i < m; ++i) {
	string line;
	getline(cin, line);
	string n;
	long long p, c, t, r;
	int last = 0;
	for(int i = last; i < line.size(); ++i) {
	    if(line[i] == ',') {
		n = line.substr(last, (i - last));
		last = i+1;
		break;
	    }
	}
	for(int i = last; i < line.size(); ++i) {
	    if(line[i] == ',') {
		p = stoi(line.substr(last, (i - last)));
		last = i+1;
		break;
	    }
	}
	for(int i = last; i < line.size(); ++i) {
	    if(line[i] == ',') {
		c = stoi(line.substr(last, (i - last)));
		last = i+1;
		break;
	    }
	}
	for(int i = last; i < line.size(); ++i) {
	    if(line[i] == ',') {
		t = stoi(line.substr(last, (i - last)));
		last = i+1;
		break;
	    }
	}
	r = stoi(line.substr(last, line.size() - last));
	if(10080 * c * t >= l * (t + r)) {
	    if(p < mn) {
		mn = p;
		mns.clear();
		mns.push_back(n);
	    } else if(p == mn) {
		mns.push_back(n);
	    }
	}
    }
    if(mns.size() == 0) {
	cout << "no such mower" << endl;
    } else {
	for(int i = 0; i < mns.size(); ++i) {
	    cout << mns[i] << endl;
	}
    }
}
