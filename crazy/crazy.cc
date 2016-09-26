#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> cost;
    for(int i = 0; i < N-1; ++i) {
	long long new_cost;
	cin >> new_cost;
	cost.push_back(new_cost);
    }
    vector<long long> time;
    for(int i = 0; i < N; ++i) {
	long long new_time;
	cin >> new_time;
	if(i == 0) continue;
	time.push_back(new_time);
    }
    long long cur_time = 0;
    long long min = (1 << 30);
    long long sum = 0;
    for(int i = 0; i < N-1; ++i) {
	sum += cost[i];
	++cur_time;
	if(cost[i] < min) min = cost[i];
	long long residue = time[i] - cur_time;
	if(residue > 0) {
	    if(residue % 2 == 1) ++residue;
	    sum += min * residue;
	    cur_time += residue;
	}
    }
    cout << sum << endl;
}
