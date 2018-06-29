#include<iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
	long long n;
	cin >> n;
	if(n == 1 || n == 2 || n == 3 || n == 5 || n == 6 || n == 9 || n == 10 || n == 13 || n == 17) cout << "No" << endl;
	else cout << "Yes" << endl;
    }
}
