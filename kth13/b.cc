#include<iostream>
#include<queue>

using namespace std;
int cust[50];
int main()
{
    int N, T;
    cin >> N >> T;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < N; ++i) {
	int c, t;
	cin >> c >> t;
	pq.push({c, t});
    }
    int cnt = T;
    int sum = 0;
    while(T >= 0 && !pq.empty()) {
	pair<int, int> u = pq.top(); pq.pop();
	int cu = u.first, tu = u.second;
	for(int i = tu; i >= 0; --i) {
	    if(cust[i] == 0) {
		cust[i] = cu;
		sum += cu;
		--cnt;
		break;
	    }
	}
    }
    cout << sum << endl;
}
