#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p;
    int mn = 1000000;
    int ind = -1;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	p.push_back(a);
	if(a < mn) {
	    mn = a;
	    ind = i;
	}
    }
    int smn = 2*mn;
    int cnt = 1;
    for(int i = 0; i< n; ++i) {
	if(i == ind) continue;
	if(p[i] == mn) ++cnt;
	if(p[i] < smn) smn = p[i];
    }
    if(smn == mn) {
	cout << smn << " " << n << endl;
    } else {
	cout << smn << " " << cnt << endl;
    }
}
