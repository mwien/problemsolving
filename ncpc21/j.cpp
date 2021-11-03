#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double sxk, syk, sxo, syo, exk, eyk, exo, eyo;
    cin >> sxk >> syk >> sxo >> syo >> exk >> eyk >> exo >> eyo;

    double res = max((sxk - sxo) *(sxk - sxo) + (syk - syo) * (syk - syo), (exk - exo) * (exk - exo) + (eyk - eyo) * (eyk - eyo));
    printf("%.12f\n", sqrt(res));
}
