#include<iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
	long long int x;
	cin >> x;
	int cnt = 0;
	long long sum = 0;
	while(x != 0) {
	    int id = 1 - (x % 2);
	    sum += id * (1LL << cnt);
	    ++cnt;
	    x /= 2;
	}
	cout << sum << endl;
    }
}
