#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 0) {
	cout << 0 << " " << 0 << endl;
    } else if(n % 2 == 1) {
	n = n/2;
	cout <<  n << " " << (n+1) << endl;
    } else if(n % 4 == 0) {
	n = n/4;
	cout << (n-1) << " " << (n+1) << endl;
    } else {
	cout << "impossible" << endl;
    }
}
