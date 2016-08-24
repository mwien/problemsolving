#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> workers;
    for(int i = 0; i < n; i++) {
	int a, b;
	cin >> a >> b;
	workers.push_back({a,b});
    }
    vector<vector<int>> gw;
    vector<vector<int>> bw;
    for(int i = 0; i < n; i++) {
	bool good = false;
	for(int j = 0; j < n; j++) {
	    if(i == j) continue;
	    if(workers[i][0] <= workers[j][0] && workers[i][1] >= workers[j][1]) {
		if(workers[i][0] < workers[j][0] || workers[i][1] > workers[j][1]) {
		    good = true;
		} else if(i > j) good = true;
	    }
	}
	if(good) gw.push_back(workers[i]);
	else bw.push_back(workers[i]);
    }
    
}
