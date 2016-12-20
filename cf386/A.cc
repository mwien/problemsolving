#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int res = min(min(4 * a, 2 * b), c) / 4;
    cout << (res + res * 2 + res * 4) << endl;
}
