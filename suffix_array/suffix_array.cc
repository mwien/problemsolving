#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> sa, pos, tmp, lcp;
string s;
int N, gap;

bool sufCmp(int i, int j) {
    if(pos[i] != pos[j])
	return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
    N = s.size();
    for(int i = 0; i < N; ++i) {
	sa.push_back(i);
	pos.push_back(s[i]);
    }
    tmp.resize(N);
    for(gap = 1;;gap *= 2) {
	sort(sa.begin(), sa.end(), sufCmp);
	for(int i = 0; i < N - 1; ++i) {
	    tmp[i+1] = tmp[i] + sufCmp(sa[i], sa[i+1]);
	}
	for(int i = 0; i < N; ++i) {
	    pos[sa[i]] = tmp[i];
	}
	if(tmp[N-1] == N-1) break;
    }
}

void buildLCP()
{
    lcp.resize(N);
    for(int i = 0, k = 0; i < N; ++i) {
	if(pos[i] != N - 1) {
	    for(int j = sa[pos[i] + 1]; s[i + k] == s[j + k];) {
		++k;
	    }
	    lcp[pos[i]] = k;
	    if (k) --k;
	}
    }
}

int main()
{
    string r, t;
    cin >> r >> t;
    s = r + "$" + t;
    buildSA();
    buildLCP();
    for(int i = 0; i < N; ++i) {
	cout << sa[i] << " " << lcp[i] << endl;
    }
    int mx = 0, mxi = -1;
    for(int i = 0; i+1 < s.size(); ++i) {
	bool a_in_s = sa[i] < r.size(), b_in_s = sa[i+1] < r.size();
	if(a_in_s != b_in_s) {
	    int l = lcp[i];
	    if(l > mx) {
		mx = l;
		mxi = sa[i];
	    }
	}
    }
    cout << mx << endl;
    cout << s.substr(mxi, mx) << endl;
}
