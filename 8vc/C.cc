#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int find(int x, vector<int> &r, vector<int> &p) {
    int root = x;
    while(p[root] >= 0) root = p[root];
    while(p[x] >= 0) {
	int tmp = p[x];
	p[x] = root;
	x = tmp;
    }
    return root;
}

bool unionf(int x, int y, vector<int> &r, vector<int> &p, int &cnt) {
    int px = find(x, r, p);
    int py = find(y, r, p);
    if(px == py) return false;
    if(r[px] < r[py]) {
	int tmp = px;
	px = py;
	py = tmp;
    }
    p[py] = px;
    r[px] = max(r[px], r[py]+1);
    --cnt;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int cnt = n;
    vector<int> r (n);
    vector<int> p (n, -1);
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	unionf(i, a-1, r, p, cnt);
    }
    cout << cnt << endl;
}
