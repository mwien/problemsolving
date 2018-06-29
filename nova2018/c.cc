#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int maxa, minb;
    cin >> maxa >> minb;
    for(int i = 1; i < N; ++i) {
	int a,b;
	cin >> a >> b;
	if(a > maxa) maxa = a;
	if(b < minb) minb = b;
    }
    if(maxa <= minb) cout << "gunilla has a point\n";
    else cout << "edward is right\n";
}
