#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long long gcd(long long a, long long b) {
    while (b > 0) {
        long long temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

int main()
{
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long tmp = gcd(x,y);
    x /= tmp;
    y /= tmp;
    cout << min(a / x, b / y) << endl;
}
