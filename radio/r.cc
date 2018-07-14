// TAGS: DP
// Problem: https://open.kattis.com/problems/commercials

#include<iostream>

using namespace std;

int T[100005];

int main()
{
    int N, P;
    cin >> N >> P;
    for(int i = 1; i <= N; ++i) {
	int a;
	cin >> a;
	a -= P;
	T[i] = max(0, T[i-1] + a);
    }
    int mx = 0;
    for(int i = 1; i <= N; ++i) {
	mx = max(mx, T[i]);
    }
    cout << mx << endl;
}
