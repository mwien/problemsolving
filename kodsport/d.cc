#include<iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    while(x >= 10) {
	int z = x;
	int y = 1;
	while(z > 0) {
	    if(z % 10 > 0)
	    y *= z % 10;
	    z /= 10;
	}
	x = y;
    }
    cout << x << endl;
}
