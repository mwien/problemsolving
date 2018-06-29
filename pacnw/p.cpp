#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v;

	for (char a='a'; a<='z'; a++)
		v.push_back(count(s.begin(), s.end(), a));

	sort(v.begin(), v.end(), [] (auto a, auto b) { return a>b; } );

	if (v.size()<2)
		cout << "0\n";
	else
		cout << s.size() - v[0]- v[1]<< endl;
}
