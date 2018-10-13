#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

bool myfunction (pair<int, int> i, pair<int, int> j) {return (i.first>j.first); }
pair<int, int> A[200005];
int res[200005];

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myfunction) *> pq(myfunction);
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	A[i] = {a, i};
    }
    sort(A, A+n);
    int idx = 0;
    for(int i = 0; i < n; ++i) {
	if(pq.empty()) {
	    pq.push({A[i].first+d, idx});
	    ++idx;
	    res[A[i].second] = idx;
	} else {
	    pair<int, int> u = pq.top();
	    if(u.first < A[i].first) {
		pq.pop();
		pq.push({A[i].first+d, u.second});
		res[A[i].second] = u.second + 1;
	    } else {
		pq.push({A[i].first+d, idx});
		++idx;
		res[A[i].second] = idx;
	    }
	}
    }
    cout << idx << endl;
    for(int i = 0; i < n; ++i) {
	cout << res[i] << " ";
    }
    cout << endl;
}
