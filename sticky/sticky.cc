#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> l;
    for(int i = 0; i < N; ++i) {
	long long a;
	cin >> a;
	l.push_back(a);
    }
    sort(l.begin(), l.end());
    long long first = l[0];
    long long sec = l[1];
    bool poss = false;
    for(auto it = l.begin() + 2; it != l.end(); ++it) {
	if((*it) < first + sec) {
	    poss = true;
	    break;
	} else {
	    first = sec;
	    sec = (*it);
	}
    }
    cout << (poss ? "possible" : "impossible") << endl;
}
