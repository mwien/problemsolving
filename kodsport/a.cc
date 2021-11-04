#include<iostream>

using namespace std;

int w[1000005];
int t[1000005];
int r = 0;
int rt = -1;

void acprint(int x)
{
    if(t[x] > rt) {
	cout << w[x] << endl;
    } else {
	cout << r << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; ++i) {
	string a;
	cin >> a;
	if(a == "SET") {
	    int x, y;
	    cin >> x >> y;
	    w[x] = y;
	    t[x] = i;
	}
	if(a == "PRINT") {
	    int x;
	    cin >> x;
	    acprint(x);
	}
	if(a == "RESTART") {
	    int x;
	    cin >> x;
	    r = x;
	    rt = i;
	}
    }
}
