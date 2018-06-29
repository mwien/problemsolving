#include<iostream>

using namespace std;

int a[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> a[i];
    }
    int s,f;
    cin >> s >> f;
    --s;
    --f;
    int d = f-s;
    long long mx = 0;
    int sind = -1;
    int tb = 100006;
    long long sum = 0;
    for(int i = 0; i < d; ++i) {
	sum += a[i];
    }
    if(sum > mx) {
	mx = sum;
	sind = 0;
    }
    for(int i = 1; i < n; ++i) {
	sum -= a[i-1];
	sum += a[(i+d-1)%n];
	int ctb = ((((s - i) % n) +n) %n);
	if(sum > mx || (sum == mx && ctb < tb)) {
	    mx = sum;
	    sind = i;
	    tb = ctb;
	}
    }
    cout << tb + 1 << endl;
}
