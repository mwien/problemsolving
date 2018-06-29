#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int twos = n/2;
    int threes = 0;
    if((n%2) == 1) {
	--twos;
	++threes;
    }
    cout << (twos +threes) << endl;
    for(int i = 0; i < twos; ++i) {
	cout << 2 << " ";
    }
    for(int i = 0; i < threes; ++i) {
	cout << 3 << " ";
    }
    cout << endl;
}
