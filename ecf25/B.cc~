#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
    int e = 1;
    int n;
    cin >> n;
    string a;
    cin >> a;
    int res = 0;
    for(int i = n-1; i >= 0; --i) {
	if(a[i] == '0') e *= 10;
	else res += e;
    }
    cout << res << endl;
}
