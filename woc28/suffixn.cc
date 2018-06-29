#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int g;
    cin >> g;
    for(int i = 0; i < g; ++i) {
	string s;
	cin >> s;
	int cnt = 0;
	for(int j = 1; j < s.size(); ++j) {
	    if(s[j] < s[j-1]) ++cnt;
	}
	cout << cnt << endl;
    }
}
