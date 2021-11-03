#include<iostream>

using namespace std;

int main()
{
    double c;
    cin >> c;
    printf("%.12f\n", min(0.25, (c / 2) * (c / 2)));
}
