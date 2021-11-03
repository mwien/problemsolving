#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cout << 1;
	cout << setfill('0') << setw(2) << i;
	int a;
	cin >> a;
	for(int j = 1; j < a; ++j) {
	    cout << 0;
	}
	cout << " ";
    }
    cout << endl;
}
