#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for(int i = 0; i < n/2; ++i) {
	sum += s[i] - 'A';
    }
    for(int i = 0; i < n/2; ++i) {
	s[i] = (char) (((s[i] + sum) % 26) + 'A');
    }
    sum = 0;
    for(int i = n/2; i < n; ++i) {
	sum += s[i] - 'A';
    }
    for(int i = n/2; i < n; ++i) {
	s[i] = (char) (((s[i] + sum) % 26) + 'A');
    }
    for(int i = 0; i < n/2; ++i) {
	s[i] = (char) (((s[i] + s[i+n/2]) % 26) + 'A');
    }
    cout << s.substr(0, n/2) << endl;
}
