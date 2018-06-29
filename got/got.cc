#include<iostream>
#include<string>

using namespace std;

bool occ[26];

int main()
{
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); ++i) {
	occ[a[i] - 'a'] ^= true;
    }
    int cnt = 0;
    for(int i = 0; i < 26; ++i) {
	if(occ[i]) ++cnt;
    }
    cout << (cnt > 1 ? "NO" : "YES") << endl; 
}
