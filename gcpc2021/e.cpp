#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

pair<int, pair<int, int>> edges[100005];
pair<int, int> qs[100005];
int dist[100005];
long long res[100005];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
	int a, d, c;
	cin >> a >> d >> c;
	edges[i] = {c, {a, d}};
    }

    sort(edges+1, edges+m+1);

    int q;
    cin >> q;

    for(int i = 1; i <= q; ++i) {
	int a;
	cin >> a;
	qs[i] = {a, i};
    }

    sort(qs+1, qs+q+1);
    int pos = m;
    int missing = n-1;
    long long tdist = -1;
    
    for(int i = q; i > 0; --i) {
	while(pos > 0) {
	    if(edges[pos].first < qs[i].first) break;
	    pair<int, pair<int, int>> e = edges[pos];
	    --pos;
	    if(dist[e.second.first] == 0) {
		dist[e.second.first] = e.second.second;
		--missing;
	    } else if(dist[e.second.first] > e.second.second) {
		tdist -= dist[e.second.first] - e.second.second;
		dist[e.second.first] = e.second.second;
	    }
	}
	if(missing == 0 && tdist < 0) {
	    tdist = 0;
	    for(int i = 1; i < n; ++i) {
		tdist += dist[i];
	    }
	}
	res[qs[i].second] = tdist;
    }
    for(int i = 1; i <= q; ++i) {
	if(res[i] < 0) {
	    cout << "impossible" << endl;
	} else {
	    cout << res[i] << endl;
	}
    }
}
