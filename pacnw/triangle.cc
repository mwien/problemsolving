#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> tr1, tr2;
    for(int i = 0; i < 3; ++i) {
	int a;
	cin >> a;
	tr1.push_back(a);
    }
    for(int i = 0; i < 3; ++i) {
	int a;
	cin >> a;
	tr2.push_back(a);
    }
    sort(tr1.begin(), tr1.end());
    sort(tr2.begin(), tr2.end());
    if(tr1[0] == tr2[0] && tr1[1] == tr2[1] && tr1[2] == tr2[2]) {
	if(tr1[0]*tr1[0] + tr1[1] * tr1[1] == tr1[2] * tr1[2]) {
	    cout << "YES" << endl;
	} else {
	    cout << "NO" << endl;
	}
    } else {
	cout << "NO" << endl;
    }
}
