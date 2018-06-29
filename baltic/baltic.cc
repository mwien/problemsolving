#include<iostream>
#include<queue>

using namespace std;

int g[505][505];
int vis[250005];

bool myfunction(pair<int, int> a, pair<int, int> b) {return (a.first > b.first);}


vector<int> neigh(int u, int h, int w) {
	int a = u % h;
	int b = u / h;
	vector<int> out;
	if(a + 1 < h) {
		if(b + 1 < w) {
			out.push_back((a+1)+(b+1)*h);
		}
		if(b - 1 >= 0) {
			out.push_back((a+1) + (b-1)*h);
		}
		out.push_back((a+1) + b*h);
	}
	if(a - 1 >= 0) {
		if(b + 1 < w) {
			out.push_back((a-1) + (b+1)*h);
		}
		if(b - 1 >= 0) {
			out.push_back((a-1) + (b-1)*h);
		}
		out.push_back((a-1) + b*h);
	}
	if(b-1 >= 0) {
		out.push_back(a + (b-1)*h);
	}
	if(b+1 < w) {
		out.push_back(a + (b+1)*h);
	}
	return out;
}

int main()
{
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> g[i][j];
		}
	}
	int di, dj;
	cin >> di >> dj;
	--di;
	--dj;
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myfunction) *> pq(myfunction);
	pq.push({g[di][dj], dj*h+di});
	int mx = g[di][dj];
	long long sum = mx;
	vis[di+dj*h] =true;
	while(!pq.empty()) {
		pair<int, int> nw = pq.top(); pq.pop();
		int dist = nw.first;
		int u = nw.second;
		mx = max(mx, dist);
		vector<int> nb = neigh(u, h, w);
		for(int j = 0; j < nb.size(); ++j) {
			int v = nb[j];
			if(!vis[v] && g[v%h][v/h] < 0) {
			    pq.push({max(mx, g[v%h][v/h]), v});
				sum += min(max(mx, g[v%h][v/h]), 0);
				vis[v] = true;
			}
		}
	}
	cout << -sum << endl;
}
