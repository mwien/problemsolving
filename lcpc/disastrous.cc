#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    queue<int> q;

    int mx = 0;
    
    for(int i = 0; i < n; ++i) {
	int t;
	cin >> t;
	while(!q.empty()) {
	    int u = q.front();
	    if(t - u >= 1000) {
		q.pop();
	    } else {
		break;
	    }
	}
	q.push(t);
	if(q.size() > mx) {
	    mx = q.size();
	}
    }
    if(mx % k == 0) {
	cout << mx / k << endl;
    } else {
	cout << mx / k + 1 << endl;
    }
}
