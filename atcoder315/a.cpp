#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
			cout << s[i];
		}
	}
	cout << endl;
}
