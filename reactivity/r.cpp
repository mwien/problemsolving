#include<iostream>
#include<vector>

using namespace std;

int inc[1005];

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> g (N, vector<int>());

    for(int i = 0; i < K; ++i) {
	int a, b;
	cin >> a >> b;
	g[a].push_back(b);
	++inc[b];
    }

    vector<int> out;
    
    for(int rep = 0; rep < N; ++rep) {
	int s = -1;
	int cnt = 0;
	for(int i = 0; i < N; ++i) {
	    if(inc[i] == 0) {
		s = i;
		++cnt;
	    }
	}
	if(cnt != 1) {
	    cout << "back to the lab" << endl;
	    return 0;
	}
	out.push_back(s);
	--inc[s];
	for(int j : g[s]) {
	    --inc[j];
	}
    }
    for(int i = 0; i < N; ++i) {
	cout << out[i] << " ";
    }
    cout << endl;
}
