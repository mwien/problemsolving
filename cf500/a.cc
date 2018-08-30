#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    for(int i = 0; i < n; ++i) {
	int x;
	cin >> x;
	a += x;
    }
    for(int i = 0; i < n; ++i) {
	int x;
	cin >> x;
	b += x;
    }
    if(b <= a) cout << "Yes" << endl;
    else cout << "No" << endl;
}
