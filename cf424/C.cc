#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int T[10000005];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, n;
    cin >> k >> n;
    vector<int> a;
    for(int i = 0; i < k; ++i) {
	int x;
	cin >> x;
	a.push_back(x);
    }
    unordered_map<int, int> b;
    int s;
    cin >> s;
    b.insert({s,0});
    for(int i = 1; i < n; ++i) {
	int x;
	cin >> x;
	b.insert({x, 0});
    }
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < k; ++i) {
	sum += a[i];
	b[s] = cnt;
	int val = s;
	int sv = s - sum;
	for(int j = i+1; j < k; ++j) {
	    val += a[j];
	    if(b.find(val) != b.end()) {
		b[val] = cnt;
	    }
	}
	val = s;
	for(int j = i-1; j >= 0; --j) {
	    val -= a[j+1];
	    if(b.find(val) != b.end()) {
		b[val] = cnt;
	    }
	}
	bool poss = true;
	for(auto it = b.begin(); it != b.end(); ++it) {
	    if(it->second != cnt) {
		poss = false;
		break;
	    }
	}
	if(poss) {
	    T[sv + 5000000] = 1;
	}
	++cnt;
    }
    int res = 0;
    for(int i = 0; i < 10000004; ++i) {
	res += T[i];
    }
    cout << res << endl;
}
