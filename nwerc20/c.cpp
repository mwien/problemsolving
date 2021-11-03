#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s = "";
    for(int i = 0; i < 26; ++i) {
	for(int j = 0; j < 4; ++j) {
	    cout << (char) ('a' + i);
	}
	cout << endl << flush;
	string x;
	cin >> x;
	if(x[0] == 'c') return 0;
	int a, b;
	a = stoi(x);
	cin >> b;
	while(a > 0) {
	    --a;
	    s += ('a' + i);
	}
    }
    while(true) {
	cout << s << endl << flush;
	string x;
	cin >> x;
	if(x[0] == 'c') return 0;
	cin >> x;
	next_permutation(s.begin(), s.end());
    }
}
