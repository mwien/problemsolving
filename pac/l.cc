#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    int K, P, X;
    cin >> K >> P >> X;
    double M = sqrt(K*P/X);
    double resl = K*P / floor(M) + floor(M) * X;
    double resh = K*P / ceil(M) + ceil(M) *X;
    cout << fixed << setprecision(3);
    cout << (resl > resh ? resh : resl) << endl;
}
