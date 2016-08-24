#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    int cnt = 0;
    while(cin >> n) {
	cout << "Case " << ++cnt << ": "  << ceil(log10(3) + n * log10(3/2.0)) << endl;
    }
}
