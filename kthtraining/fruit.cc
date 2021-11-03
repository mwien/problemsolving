#include<iostream>

using namespace std;

int w[45];
long long sum = 0;
int N;

void rec(int i, int s)
{
    if(i == N) return;
    rec(i + 1, s);
    s += w[i];
    if(s < 200) {
	rec(i + 1, s);
	sum -= s;
    }
}


int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) {
	cin >> w[i];
	sum += (1LL << (N-1)) * w[i];
    }
    rec(0,0);
    cout << sum << endl;
}
