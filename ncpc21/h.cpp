#include<iostream>

pair<double, int> st[200005];
long long A[200005];
pair<int, int> tp[200005];
int rev[200005];
pair<long long, int> t[4*MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(A[tl], rev[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
	int x, y;
	cin >> x >> y;
	tp[i].first = x;
	tp[i].second = y;
	st[i].first = x / y;
	st[i].second = i;
    }
    sort(st, st+n);
    for(int i = 0; i < n; ++i) {
	A[i] = tp[st[i].second].first * tp[st[i].second].first + tp[st[i].second].second * tp[st[i].second].second;
	rev[st[i].second] = i;
    }
    build(a, 1, 0, n-1);

    int e;
    cin >> e;
    for(int i = 0; i < e; ++i) {
	string s;
	cin >> s;
	if(s == "c") {
	    int t, l, f;
	    cin >> t >> l >> f;
	    get_max(1,0,n-1,0, // TODO
	}
	if(s == "q") {
	    int x;
	    cin >> x;
	    update(1,0,n-1,rev[x],0);
	}
    }
}
