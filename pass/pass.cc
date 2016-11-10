#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> vals;
    for(int i = 0; i < N; ++i) {
	string in;
	double val;
	cin >> in >> val;
	long long cur = round(val * 10000);
	vals.push_back(cur);
    }
    sort(vals.begin(), vals.end());
    long long res = 0;
    for(int i = 0; i < N; ++i) {
	res += (i+1) * vals[N-i-1];
    }
    cout << setiosflags(ios::fixed) << setprecision(4) << (double) res / 10000.0 << endl;
}
