#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 0;
    while((1 << k) < n) ++k;
    cout << k+1 << endl;
}
