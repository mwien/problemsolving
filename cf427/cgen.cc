#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    int n = 10000;
    int q = 100000;
    int c = 10;
    cout << n << " " << q << " " << c << endl;
    for(int  i = 0; i < n; ++i) {
	cout << i / 100 + 1 << " " << i % 100 + 1 << " " << i % 11 << endl;
    }
    for(int i = 0; i < q; ++i) {
	cout << i << " " << 1 << " " << 1 << " " << 100 << " " << 100 << endl;
    }
}
