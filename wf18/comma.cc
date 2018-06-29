#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

vector<string> text;
vector<bool> cm, pnt;
unordered_map<string, pair<bool, bool>> st;

int main()
{
    string in;
    while(cin >> in) {
	cm.push_back(in[in.size()-1] == ',');
	pnt.push_back(in[in.size()-1] == '.');
	if(in[in.size()-1] == ',' || in[in.size()-1] == '.')
	    in = in.substr(0, in.size()-1);
	text.push_back(in);
    }
    for(int i = 0; i < text.size(); ++i) {
	bool prev = false, nxt = false;
	if(i > 0 && cm[i-1]) prev = true;
	if(cm[i]) nxt = true;
	if(st.find(text[i]) == st.end()) {
	    st.insert({text[i], {prev, nxt}});
	} else {
	    pair<bool, bool> old = st[text[i]];
	    st[text[i]] = {old.first || prev, old.second || nxt};
	}
    }
    for(int i = 0; i < text.size(); ++i) {
	cout << text[i];
	if(pnt[i]) cout << ". ";
	else if(cm[i]) cout << ", ";
	else cout << " ";
    }
    cout << endl;
}
