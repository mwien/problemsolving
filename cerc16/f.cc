#include<iostream>
#include<vector>

using namespace std;

int c[100005];
int g[100005];
vector<int> cl[100005];
vector<int> gl[100005];
bool vis[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
	cin >> c[i];
    }
    for(int i = 1; i <= n; ++i) {
	if(vis[i]) continue;
	int ind = i;
	while(ind != 0) {
	    vis[ind] = true;
	    cl[i].push_back(ind);
	    ind = c[ind];
	}
    }
    for(int i = 1; i <= n; ++i) {
	vis[i] = false;
    }
    for(int i = 1; i <= n; ++i) {
	cin >> g[i];
    }
    for(int i = 1; i <= n; ++i) {
	if(vis[i]) continue;
	int ind = i;
	while(ind != 0) {
	    vis[ind] = true;
	    gl[i].push_back(ind);
	    ind = g[ind];
	}
    }
    for(int i = 1; i <= n; ++i) {
	vis[i] = false;
    }
    for(int i = 1; i <= n; ++i) {
	int j = -1;
	for(j = 0; j < min(cl[i].size(), gl[i].size()); ++j) {
	    if(cl[i][j] != gl[i][j]) {
		break;
	    }
	}
	for(int k = 0; k < j-1; ++k) {
	    vis[cl[i][k]] = true;
	}
    }
    int s = 0;
    for(int i = 1; i <= n; ++i) {
	if(vis[i]) continue;
	if(c[i] != 0) ++s;
	if(g[i] != 0) ++s;
    }
    cout << s << endl;
}
