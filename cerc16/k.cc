#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> pos;
    if(s[0] == s[1] && s[1] == s[2]) {
	pos.push_back(0);
    }
    for(int i = 3; i < s.size(); i += 3) {
	if(s[i-1] == '0' && s[i] == '0' && s[i+1] == '0' && s[i+2] == '0') {
	    s[i] = '1';
	    s[i+1] = '1';
	    pos.push_back(i);
	} else if(s[i-1] == '0' && s[i] == '0' && s[i+1] == '0' && s[i+2] == '1') {
	    s[i+1] = '1';
	    s[i+2] = '0';
	    pos.push_back(i+1);
	} else if(s[i-1] == '0' && s[i] == '0' && s[i+1] == '1' && s[i+2] == '1') {
	    s[i] = '1';
	    s[i+1] = '0';
	    pos.push_back(i);
	} else if(s[i-1] == '0' && s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') {
	    s[i+1] = '0';
	    s[i+2] = '0';
	    pos.push_back(i+1);
	} else if(s[i-1] == '1' && s[i] == '0' && s[i+1] == '0' && s[i+2] == '0') {
	    s[i+1] = '1';
	    s[i+2] = '1';
	    pos.push_back(i+1);
	} else if(s[i-1] == '1' && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0') {
	    s[i] = '0';
	    s[i+1] = '1';
	    pos.push_back(i);
	} else if(s[i-1] == '1' && s[i] == '1' && s[i+1] == '1' && s[i+2] == '0') {
	    s[i+1] = '0';
	    s[i+2] = '1';
	    pos.push_back(i+1);
	} else if(s[i-1] == '1' && s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') {
	    s[i] = '0';
	    s[i+1] = '0';
	    pos.push_back(i);
	}
	
    }
    cout << pos.size() <<endl;
    for(int i = 0; i < pos.size(); ++i) {
	cout << pos[i] + 1 << " ";
    }
    if(pos.size() > 0)
    cout << endl;
}
