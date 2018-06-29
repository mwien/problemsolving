#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int d[505];
int s[505];
pair<int,int> diff[505];
pair<int, bool[505]> T[10005];

int main()
{
    int n,c;
    cin >> n >> c;
    for(int i = 0; i < n; ++i) {
        cin >> d[i] >> s[i];
        diff[i] = {s[i] - d[i], i};
    }
    sort(begin(diff), begin(diff)+n);
    T[0].first = 0;
    for(int i = 1; i <= c; ++i) {
        T[i].first = -1000;
    }
    for(int i = 0; i < n; ++i) {
        int ind = diff[i].second;
        for(int j = c; j >= 0; --j) {
            if(T[j].first < 0) continue;
            if(j + max(d[ind], s[ind]) > c) continue;
            if(T[j].first + 1 > T[j+s[ind]].first) {
                T[j + s[ind]].first = T[j].first+1;
		T[j + s[ind]].second[ind] = true;
            }
        }
    }
    int mx = 0, mxind = -1;
    for(int i = 0; i <= c; ++i) {
        if(T[i].first > mx) {
            mx = T[i].first;
            mxind = i;
        }
    }
    if(mx == 0) {
        cout << 0 << endl;
    } else {
        vector<int> sol;
	int ind = n-1;
        while(true) {
            if(mxind == 0) break;
	    for(; ind >= 0; --ind) {
		if(T[mxind].second[diff[ind].second]) {
		    sol.push_back(diff[ind].second);
		    mxind -= s[diff[ind].second];
		    --ind;
		    break;
		}
	    }
        }
        cout << sol.size() << endl;
        for(int i = sol.size()-1; i >= 0; --i) {
            cout << sol[i]+1 << " ";
        }
        cout << endl;
    }
}
