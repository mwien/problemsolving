#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<long long, long long, long long, int>> stones;
    for(int i = 0; i < n; ++i) {
	long long a, b, c;
	cin >> a >> b >> c;
	stones.push_back(make_tuple(a, b, c, i));
	stones.push_back(make_tuple(a, c, b, i));
	stones.push_back(make_tuple(b, a, c, i));
	stones.push_back(make_tuple(b, c, a, i));
	stones.push_back(make_tuple(c, a, b, i));
	stones.push_back(make_tuple(c, b, a, i));
    }
    sort(stones.begin(), stones.end());
    long long f = get<0>(stones[0]), s = get<1>(stones[0]);
    long long max = min({get<0>(stones[0]), get<1>(stones[0]), get<2>(stones[0])});
    int start = 0;
    pair<int, int> res = {0,-1};
    for(int i = 1; i < stones.size(); ++i) {
	if(get<0>(stones[i]) != f || get<1>(stones[i]) != s) {
	    long long fmax = min({get<0>(stones[i-1]), get<1>(stones[i-1]), get<2>(stones[i-1])});
	    long long smax = 0;
	    int sind = -1;
	    int idx = get<3>(stones[i-1]);
	    for(int j = i-2; j >= start; --j) {
		if(idx != get<3>(stones[j])) {
		    if(min({get<0>(stones[i-1]), get<1>(stones[i-1]), get<2>(stones[i-1]) + get<2>(stones[j])}) > fmax) {
			smax = get<2>(stones[j]);
			sind = get<3>(stones[j]);	
		    }
		    break;
		}
	    }
	    if(fmax + smax > max) {
		max = fmax + smax;
		res.first = idx;
		res.second = sind;
	    }
	    start = i;
	    f = get<0>(stones[i]);
	    s = get<1>(stones[i]);
	    if(min({get<0>(stones[i]), get<1>(stones[i]), get<2>(stones[i])}) > max) {
		max = min({get<0>(stones[i]), get<1>(stones[i]), get<2>(stones[i])});
		res.first = get<3>(stones[i]);
		res.second = -1;
	    }
	}
    }
    int i = stones.size();
    long long fmax = min({get<0>(stones[i-1]), get<1>(stones[i-1]), get<2>(stones[i-1])});
    long long smax = 0;
    int sind = -1;
    int idx = get<3>(stones[i-1]);
    for(int j = i-2; j >= start; --j) {
	if(idx != get<3>(stones[j])) {
	    if(min({get<0>(stones[i-1]), get<1>(stones[i-1]), get<2>(stones[i-1]) + get<2>(stones[j])}) > fmax) {
		smax = get<2>(stones[j]);
		sind = get<3>(stones[j]);	
	    }
	    break;
	}
    }
    if(fmax + smax > max) {
	max = fmax + smax;
	res.first = idx;
	res.second = sind;
    }
    if(res.second != -1) {
	cout << 2 << endl;
	cout << res.first+1 << " " << res.second+1 << endl;
    } else {
	cout << 1 << endl;
	cout << res.first+1 << endl;
    }
}
