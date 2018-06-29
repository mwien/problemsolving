#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<int> a;
vector<int> b;
vector<pair<int, char>> res;

bool check(int i, int offset, int lastidx) {
    vector<int> tmp;
    for(int j = lastidx; j <= i; ++j) {
	tmp.push_back(a[j]);
    }
    while(tmp.size() > 1) {
	int max = -1;
	int maxind = -1;
	bool lr = true;
	for(int j = 0; j < tmp.size(); ++j) {
	    if(tmp[j] > max) {
		if(j > 0 && tmp[j-1] < tmp[j]) {
		    max = tmp[j];
		    maxind = j;
		    lr = true;
		} else if(j < tmp.size()-1 && tmp[j+1] < tmp[j]) {
		    max = tmp[j];
		    maxind = j;
		    lr = false;
		}
	    }
	}
	if(maxind == -1) return false;
	if(lr) {
	    tmp[maxind] += tmp[maxind-1];
	    tmp.erase(tmp.begin() + maxind-1);
	    res.push_back({offset+maxind+1, 'L'});
	} else if(!lr) {
	    tmp[maxind] += tmp[maxind+1];
	    tmp.erase(tmp.begin() + maxind+1);
	    res.push_back({offset+maxind+1, 'R'});
	}
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int cur;
	cin >> cur;
	a.push_back(cur);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i) {
	int cur;
	cin >> cur;
	b.push_back(cur);
    }
    int sum = 0;
    int idx = 0;
    bool poss = true;
    int lastidx = 0;
    for(int i = 0; i < n; ++i) {
	sum += a[i];
	if(sum == b[idx]) {
	    if(!check(i, idx, lastidx)) {
		cout << "NO" << endl;
		poss = false;
		break;
	    }
	    sum = 0;
	    ++idx;
	    lastidx = i+1;
	} else if(sum > b[idx]) {
	    cout << "NO" << endl;
	    poss = false;
	    break;
	}
    }
    if(poss) {
	cout << "YES" << endl;
	for(int i = 0; i < res.size(); ++i) {
	    cout << res[i].first << " " << res[i].second << endl;
	}
    }
}
