#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;
const int size = 10005;

int main()
{
    int g;
    cin >> g;
    multiset<int> a[size];
    for(int i = 0; i < g; i++) {
	int gx, gy;
	cin >> gx >> gy;
	a[gx].insert(gy);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
	int sx, sy, r;
	cin >> sx >> sy >> r;
	int start = max(0, sx - r), end = min(size-1, sx + r);
	for(int j = start; j <= end; j++) {
	    int root = sqrt(r * r - (sx - j)*(sx - j));
	    int ub = sy + root;
	    int lb = sy - root;
	    multiset<int>::iterator itup = a[j].upper_bound(ub);
	    multiset<int>::iterator itlow = a[j].lower_bound(lb);
	    a[j].erase(itlow, itup);
	}
    }
    int sum = 0;
    for(int i = 0; i < size; i++) {
	sum += a[i].size();
    }
    cout << sum << endl;
}
