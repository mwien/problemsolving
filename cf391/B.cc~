#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    vector<int> lc (26);
    vector<int> uc (26);
    for(int i = 0; i < a.size(); ++i) {
	if(a[i] >= 'A' && a[i] <= 'Z') {
	    ++uc[a[i] - 'A'];
	}
	if(a[i] >= 'a' && a[i] <= 'z') {
	    ++lc[a[i] - 'a'];
	}
    }
    int mn = a.size();
    mn = min(lc['u' - 'a'] / 2, mn);
    mn = min(lc['l' - 'a'], mn);
    mn = min(lc['b' - 'a'], mn);
    mn = min(lc['a' - 'a'] / 2, mn);
    mn = min(lc['s' - 'a'], mn);
    mn = min(lc['r' - 'a'], mn);
    mn = min(uc['B' - 'A'], mn);
    cout << mn << endl;
}
