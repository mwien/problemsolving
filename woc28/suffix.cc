#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int lis(vector<int> &rot, int n)
{
    vector<int> m (n+1);
    int l = 0;
    for(int i = 0; i < n; ++i) {
	int lo = 1;
	int hi = l;
	while(lo <= hi) {
	    int mid = (int) (((lo + hi) / 2.0) + 0.6);
	    if(rot[m[mid]] <= rot[i])
		lo = mid+1;
	    else
		hi = mid-1;
	}
	int newL = lo;
	m[newL] = i;
	if(newL > l) l = newL;
    }
    return l;
}

int main()
{
    int g;
    cin >> g;
    for(int i = 0; i < g; ++i) {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> rot;
	for(int k = 0; k < n; ++k) {
	    rot.push_back(s[k] - 'a');
	}
	cout << n - lis(rot, n) << endl;
    }
}
