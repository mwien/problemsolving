// TAGS: DP
// Problem: https://open.kattis.com/problems/spiderman

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

pair<int, int> T[1005][45];

int main()
{
    int N;
    cin >> N;
    for(int I = 0; I < N; ++I) {
	T[0][0] = {0, -1};
	for(int j = 1; j < 1005; ++j) {
	    T[j][0] = {1005, -1};
	}
	for(int j = 0; j < 1005; ++j) {
	    for(int k = 1; k < 45; ++k) {
		T[j][k] = {1005, -1};
	    }
	}
	int M;
	cin >> M;
	for(int i = 1; i <= M; ++i) {
	    int a;
	    cin >> a;
	    for(int j = 0; j < 1005; ++j) {
		if(T[j][i-1].first == 1005) continue;
		if(j + a < 1005) {
		    int nn = max(T[j][i-1].first, j+a);
		    if(nn < T[j+a][i].first) {
			T[j+a][i].first = nn;
			T[j+a][i].second = -a;
		    }
		}
		if(j - a >= 0) {
		    if(T[j][i-1].first < T[j-a][i].first) {
			T[j-a][i].first = T[j][i-1].first;
			T[j-a][i].second = a;
		    }
		}
	    }
	}
	if(T[0][M].first == 1005) {
	    cout << "IMPOSSIBLE\n";
	} else {
	    int idx = 0;
	    string out = "";
	    for(int i = M; i > 0; --i) {
		if(T[idx][i].second < 0) {
		    out += "U";
		} else {
		    out += "D";
		}
		idx += T[idx][i].second;
	    }
	    reverse(out.begin(), out.end());
	    cout << out << endl;
	}
    }
}
