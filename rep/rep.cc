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
    sa.resize(N);
    pos.resize(N);
    for(int i = 0; i < N; ++i) {
	sa[i] = i;
	pos[i] = s[i];
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
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
	cin >> s;
	buildSA();
	buildLCP();
	int sum = lcp[0];
	for(int i = 1; i < N - 1; ++i) {
	    if(lcp[i] > lcp[i-1]) sum += lcp[i] - lcp[i-1];
	}
	cout << sum << endl;
    }
}
