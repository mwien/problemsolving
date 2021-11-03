#include<iostream>

using namespace std;

int p[10005];
int r[10005];
int o[10005];
int t[10005];

int fd(int x) {
    int root = x;
    while (p[root] >= 0) { // find root
        root = p[root];
    }
    while (p[x] >= 0) { // path compression
        int tmp = p[x];
        p[x] = root;
        x = tmp;
    }
    return root;
}

// return true, if sets merged and false, if already from same set
bool un(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py)
        return false; // same set -> reject edge
    if (r[px] < r[py]) { // swap so that always h[px]>=h[py]
        int tmp = px;
        px = py;
        py = tmp;
    }
    p[py] = px; // hang flatter tree as child of higher tree
    r[px] = max(r[px], r[py] + 1); // update (worst-case) height
    // if needed use count here
    // count--;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
	p[i] = -1;
    }
    for(int i = 0; i < n; ++i) {
	cin >> o[i];
    }
    for(int i = 0; i < m; ++i) {
	int a, b;
	cin >> a >> b;
	un(a, b);
    }
    for(int i = 0; i < n; ++i) {
	t[fd(i)] += o[i];
    }
    bool poss = true;
    for(int i = 0; i < n; ++i) {
	if(t[i] != 0) poss = false;
    }
    cout << (poss ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
