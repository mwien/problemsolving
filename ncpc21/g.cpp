#include<iostream>
#include<random>

using namespace std;

int x[12];
int y[12];
int r[12];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> x[i] >> y[i] >> r[i];
    }
    default_random_engine generator;
    uniform_real_distribution<double> distribution(-10.0,20.0);
    int cnt = 0;
    int rep = 1000000;
    for(int i = 0; i < rep; ++i) {
	double rx = distribution(generator);
	double ry = distribution(generator);
	bool isin = false;
	for(int j = 0; j < n; ++j) {
	    if((rx - x[j]) * (rx - x[j]) + (ry - y[j]) * (ry - y[j])  <= r[j] * r[j]) isin = true;
	}
	if(isin) ++cnt;
    }
    printf("%.12f\n", (double) cnt / rep * 900);
}
