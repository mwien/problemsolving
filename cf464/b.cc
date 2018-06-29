#include<iostream>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long min = 1e18+10;
    long long num = -1;
    long long ind = -1;
    for(int i = 0; i < k; ++i) {
	int a;
	cin >> a;
	if(min > n % a) {
	    min = n % a;
	    num = n / a;
	    ind = i;
	}
    }
    cout << ind + 1 << " " << num << endl;
}
