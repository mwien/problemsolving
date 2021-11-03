#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
	int n, k;
	cin >> n >> k;
	unordered_set<int> st;
	int mx = 0;
	int mex = 0;
	for(int i = 0; i < n; ++i) {
	    int x;
	    cin >> x;
	    st.insert(x);
	    mx = max(mx, x);
	}
	while(true) {
	    if(st.find(mex) != st.end()) {
		++mex;
	    } else {
		break;
	    }
	}
	if(mex > mx) {
	    cout << st.size() + k << endl;
	} else {
	    int nn = (mex + mx) / 2;
	    if((mex + mx) % 2) ++nn;
	    if(k > 0) {
		st.insert(nn);
	    }
	    cout << st.size() << endl;
	}
    }
}
