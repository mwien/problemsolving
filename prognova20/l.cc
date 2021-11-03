#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<bool>> vis (a+1, vector<bool> ());
    for(int i = 0; i < a+1; ++i) {
	for(int j = 0; j < b+1; ++j) {
	    vis[i].push_back(false);
	}
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    vis[0][0] = true;
    int last = 0;
    for(int i = 0; i < n; ++i) {
	int t;
	cin >> t;
	while(!q.empty()) {
	    pair<int, pair<int, int>> tp = q.front();
	    if(tp.first == i) {
		q.pop();
		last = i;
		int c = tp.second.first;
		int d = tp.second.second;
		if(c + t <= a && !vis[c+t][d]) {
		    q.push({i+1, {c + t, d}});
		    vis[c+t][d] = true;
		}
		if(d + t <= b && !vis[c][d+t]) {
		    q.push({i+1, {c, d + t}});
		    vis[c][d+t] = true;
		}
	    } else {
		break;
	    }
	    
	}
    }
    if(!q.empty()) {
	cout << n << endl;
    } else {
	cout << last << endl;
    }
}
