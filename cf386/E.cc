#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> evg;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	evg.push_back(a);
    }
    unordered_map<int, int> alleven, allodd, evgeven, evgodd;
    for(int i = 0; i < n; ++i) {
	if(evg[i] % 2 == 0) {
	    alleven.insert({evg[i], i});
	    evgeven.insert({evg[i], i});
	} else {
	    allodd.insert({evg[i], i});
	    evgodd.insert({evg[i], i});
	}
    }
    for(int i = 1; i <= m; ++i) {
	if(i % 2 == 0) {
	    alleven.insert({i, -1});
	} else {
	    allodd.insert({i, -1});
	}
    }
    if(alleven.size() < n/2 || allodd.size() <  n/2) {
	cout << -1 << endl;
    } else {
	cout << n - min(n/2, (int) evgeven.size()) - min(n/2, (int) evgodd.size()) << endl;
	vector<int> ch (n, -1);
	vector<int> rest;
	int cnt = 0;
	for(auto it = evgeven.begin(); it != evgeven.end(); ++it) {
	    if(cnt >= n/2) break;
	    ch[it -> second] = it -> first;
	    ++cnt;
	}
	for(auto it = alleven.begin(); it != alleven.end(); ++it) {
	    if(cnt >= n/2) break;
	    if(evgeven.find(it -> first) == evgeven.end()) {
		rest.push_back(it -> first);
		++cnt;
	    }
	}
	cnt = 0;
	for(auto it = evgodd.begin(); it != evgodd.end(); ++it) {
	    if(cnt >= n/2) break;
	    ch[it -> second] = it -> first;
	    ++cnt;
	}
	for(auto it = allodd.begin(); it != allodd.end(); ++it) {
	    if(cnt >= n/2) break;
	    if(evgodd.find(it -> first) == evgodd.end()) {
		rest.push_back(it -> first);
		++cnt;
	    }
	}
	int ind = 0;
	for(int i = 0; i < n; ++i) {
	    if(ch[i] != -1) cout << ch[i] << " ";
	    else {
		cout << rest[ind] << " ";
		++ind;
	    }
	}
	cout << endl;
    }
}
