#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
    cin.tie(0);
    int N;
    cin >> N;
    vector<string> s;
    for(int i = 0; i < N; ++i) {
	string a;
	cin >> a;
	reverse(a.begin(), a.end());
	s.push_back(a);
    }
    sort(s.begin(), s.end());
    int longest = 0;
    for(int i = 0; i < N-1; ++i) {
	int j = 0;
	while(j < s[i].size()) {
	    if(s[i][j] != s[i+1][j]) break;
	    ++j;
	}
	if(j != s[i].size()) {
	    longest = max(j, longest);
	}
    }
    cout << longest << endl;
}
