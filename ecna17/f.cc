#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool vis[10005];
int pre[10005];

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g (n+1, vector<int> ());
    for(int i = 0; i < n; ++i) {
	int a, b;
	cin >> a >> b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    
    long long total = 0;
    ncnt = 0;
    for(int i = 1; i < sub.size(); ++i) {
	ncnt += sub[i-1];
	total += ncnt * sub[i];
    }
    sort(sub.begin(), sub.end());
    long long ntotal = sub[sub.size()-1]*sub[sub.size()-2];
    cout << total << " " << total - ntotal << endl;
}
