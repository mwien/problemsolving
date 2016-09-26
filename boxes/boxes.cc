#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

void rec_dfs(vector<vector<int>> &forest, vector<pair<int, int>> &times, const int &n, int &time, int node) 
{
    ++time;
    times[node].first = time;
    for(auto it = forest[node].begin(); it != forest[node].end(); ++it) {
	rec_dfs(forest, times, n, time, *it);
    }
    ++time;
    times[node].second = time;
}

void dfs(vector<vector<int>> &forest, vector<pair<int, int>> &times,  const int &n, vector<int> &start)
{
    int time = 0;
    for(auto it = start.begin(); it != start.end(); ++it) {
	rec_dfs(forest, times,  n, time, *it);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> forest;
    for(int i = 0; i < N; ++i) {
	forest.push_back(vector<int>());
    }
    vector<int> start;
    for(int i = 0; i < N; ++i) {
	int in;
	cin >> in;
	if(in != 0) {
	    forest[in-1].push_back(i);
	} else {
	    start.push_back(i);
	}
    }
    vector<pair<int, int>> times;
    for(int i = 0; i < N; ++i) {
	pair<int, int> new_pair (0,0);
	times.push_back(new_pair);
    }
    dfs(forest, times, N, start);

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i) {
	int M;
	cin >> M;
	vector<pair<int, int>> req;
	for(int j = 0; j < M; ++j) {
	    int new_box;
	    cin >> new_box;
	    req.push_back(times[new_box-1]);
	}
	sort(req.begin(), req.end());
	int sum = 0;
	int start_range = -10;
	int end_range = -10;
	for(auto it = req.begin(); it != req.end(); ++it) {
	    if((*it).first > end_range) {
		sum += ((*it).second - (*it).first) / 2 + 1;
		start_range = (*it).first;
		end_range = (*it).second;
	    }
	}
	cout << sum << endl;
    }
}
