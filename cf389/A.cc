#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int main()
{
    long long n, m , k;
    cin >> n >> m >> k;
    char s = ((k % 2) == 0 ? 'R' : 'L');
    --k;
    long long r = k / (2*m);
    long long d = (k % (2*m)) / 2;
    cout << r+1 << " " << d+1 << " " << s << endl;
}
