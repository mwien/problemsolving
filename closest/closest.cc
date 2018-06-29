#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
	int b;
	cin >> b;
	a.push_back(b);
    }
    sort(a.begin(), a.end());
    int md = 1e8 + 1;
    for(int i = 0; i < n-1; ++i) {
	md = min(md, a[i+1] - a[i]);
    }
    for(int i = 0; i < n-1; ++i) {
	bool pr = false;
	if(a[i+1] - a[i] == md) {
	    cout << a[i] << " " << a[i+1] << " ";
	}
    }
    cout << endl;
}
