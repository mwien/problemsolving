#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int fac[11];
bool vis[4000000];
bool nvis[4000000];
bool bvis[4000000];
int dist[4000000];
int ndist[4000000];
vector<vector<int> > bsh;
vector<int> res;

int calcind(vector<int> p, int n) {
    int index = 0;
    int position = 2;
    int factor = 1;
    for (int i = n - 2; i >= 0; i--) {
	int successors = 0;
	for (int j = i + 1; j < n; j++) {
	    if (p[i] > p[j]) {
		successors++;
	    }
	}
	index += (successors * factor);
	factor *= position;
	position++;
    }
    return index;
}

void sbfs(vector<int> p, int n, int size) {
    queue<vector<int> > q;
    q.push(p);
    int ind = calcind(p,n);
    if(vis[ind]) {
	res.push_back(dist[ind]);
    }
    nvis[ind] = true;
    ndist[ind] = 0;
    while(!q.empty()) {
	vector<int> r = q.front();
	q.pop();
	int oldind = calcind(r, n);
	if(ndist[oldind] == 3) break;
	for(int i = 0; i < size; i++) {
	    vector<int> put(n);
	    for(int j = 0; j < n; j++) {
		put[bsh[i][j]] = r[j];
	    }
	    ind = calcind(put, n);
	    if(vis[ind]) {
		res.push_back(ndist[oldind] + dist[ind] + 1);
	    }
	    if(nvis[ind]) {
		continue;
	    }
	    q.push(put);
	    nvis[ind] = true;
	    ndist[ind] = ndist[oldind] + 1;
	}
    }
    res.push_back(6);
}

void bfs(vector<int> p, int n, int size) {
    queue<vector<int> > q;
    q.push(p);
    int ind = calcind(p, n);
    vis[ind] = true;
    dist[ind] = 0;
    while(!q.empty()) {
	vector<int> r = q.front();
	q.pop();
	int oldind = calcind(r, n);
	if(dist[oldind] == 2) break;
	for(int i = 0; i < size; i++) {
	    vector<int> put(n);
	    for(int j = 0; j < n; j++) {
		put[j] = r[bsh[i][j]];
	    }
	    ind = calcind(put, n);
	    if(vis[ind]) continue;
	    q.push(put);
	    vis[ind] = true;
	    dist[ind] = dist[oldind] + 1;
	}
    }
}



int main()
{
    int n;
    cin >> n;
    vector<int> order;
    vector<int> finish;
    for(int i = 0; i < n; ++i) {
	int k;
	cin >> k;
	order.push_back(k-1);
	finish.push_back(i);
    }
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) {
	fac[i] = fac[i-1] * i;
    }
    int cnt = 0;
    for(int i = 0; i < n+1; ++i) {
    	for(int j = i; j < n+1; ++j) {
    	    for(int k = j; k < n+1; ++k) {
    		vector<int> shuffle;
    		int as = i;
    		int bs = j - i;
    		int cs = k - j;
    		int ds = n - k;
    		for(int m = 0; m < cs; ++m) {
    		    shuffle.push_back(finish[as + bs + m]);
    		}
    		for(int m = 0; m < as; ++m) {
    		    shuffle.push_back(finish[m]);
    		}
    		for(int m = 0; m < ds; ++m) {
    		    shuffle.push_back(finish[as + bs + cs + m]);
    		}
    		for(int m = 0; m < bs; ++m) {
    		    shuffle.push_back(finish[as + m]);
    		}
    		int ind = calcind(shuffle, n);
    		if(bvis[ind]) continue;
    		bvis[ind] = true;
    		bsh.push_back(shuffle);
    		++cnt;
    	    }
    	}
    }
    bfs(order, n, cnt);
    sbfs(finish, n, cnt);
    int min = 10;
    int it = 0;
    while(true) {
    	if(res[it] == 6) {
    	    if(min > 6) min = 6;
    	    break;
    	}
    	if(min > res[it]) min = res[it];
    	++it;
    }
    cout << min << endl;
}

