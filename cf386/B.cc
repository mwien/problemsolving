#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, o = "";
    cin >> s;
    for(int i = 0; i < n; ++i) {
	if((i + n) % 2 == 0) {
	    o = s[i] + o;
	} else {
	    o = o + s[i];
	}
    }
    cout << o << endl;
}
