#include<iostream>

using namespace std;

int x[105];

int main()
{
    int n,d;
    cin >> n >> d;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	++x[a];
    }
    int mx = 0;
    int sm = 0;
    for(int i = 1; i <= 100; ++i) {
	sm += x[i];
    }
    for(int i = 0; i <= 100-d; ++i) {
	int sum = 0;
	for(int j = i; (j-i) <= d; ++j) {
	    sum += x[j];
	}
	if(sum > mx) mx = sum;
    }
    cout << sm - mx << endl;
}
