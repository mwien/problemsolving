#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int n, t , k;
    cin >> n >> t >> k;
    vector<int> d;
    for(int i = 0; i < t; ++i) {
	int a;
	cin >> a;
	d.push_back(a);
    }
    int mn = 0, mx = 0;
    for(int i = 0; i < t-1; ++i) {
	mx += d[i] - 1;
	mn += max(d[i] - d[i+1], 0);
    }
    mn += d[t-1];
    mx += d[t-1];
    if(k < mn || k > mx) {
	cout << -1 << endl;
    } else {
	vector<int> f (n);
	vector<int> last;
	for(int i = 0; i < d[0]; ++i) {
	    f[i+1] = 0;
	    last.push_back(i+1);
	}
	int ind = d[0]+1;
	int lw = 0;
	for(int i = 1; i < t; ++i) {
	    int ft = 0;
	    for(int j = 0; j < d[i]; ++j) {
		if(lw < (mx -k)) {
		    f[j+ind] = last[ft];
		    ++lw;
		} else {
		    if(ft < last.size()-1 && j != 0) {
			++ft;
		    }
		    f[j+ind] = last[ft];
		}
	    }
	    last.clear();
	    for(int j = 0; j < d[i]; ++j) {
		last.push_back(ind+j);
	    }
	    ind += d[i];
	}
	cout << n << endl;
	for(int i = 1; i < n; ++i) {
	    cout << (i+1) << " " << (f[i]+1) << endl;
	}
    }
}
