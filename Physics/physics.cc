#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long long p[10005];

int main()
{
    int N;
    while(true) {
	cin >> N;
	if(N == 0) break;
	for(int i = 0; i < N; i++) {
	    double cur;
	    cin >> cur;
	    p[i] = round(cur * 1000);
	}
	double cur;
	cin >> cur;
	long long D;
	D = round(cur * 1000);
	sort(p, p + N);
	long long time = 0;
	long long pos = p[0];
	for(int i = 1; i < N; i++) {
	    if(p[i] > 
	}
    }
}
