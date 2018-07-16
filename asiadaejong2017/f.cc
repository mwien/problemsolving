// TAGS: AD HOC, RECURSION
// Problem: http://codeforces.com/gym/101667/attachments (Problem F)

#include<iostream>

using namespace std;

pair<int, int> solve(int n, int m) {
    if(n < 2) return {0, 0};
    int p = m / (n*n/4);
    int x = 0, y = 0;
    pair<int, int> pp = solve(n/2, m % (n*n/4));
    if(p == 0) {
	x += pp.second;
	y += pp.first;
    }
    if(p == 1 || p == 2) {
	if(p == 2)
	    x += n/2;
	y += n/2;
	x += pp.first;
	y += pp.second;
    }
    if(p == 3) {
	x += n/2;
	x += n/2 - pp.second - 1;
	y += n/2 - pp.first - 1;
    }
    //cout << m << " " << n << endl;
    //cout << x << " " << y << endl;
    return {x,y};
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> res;
    res = solve(n, m-1);
    cout << res.first+1 << " " << res.second+1 << endl;
}
