#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

long long fac(long long a) {
    if(a == 1) return 1;
    return fac(a-1) * a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int res = min(a, b);
    cout << fac(res) << endl;
}
