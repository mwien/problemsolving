#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int dt = 0;
    int op = 0;
    int last;
    cin >> last;
    for(int i = 0; i < n-1; ++i) {
	int a;
	cin >> a;
	++op;
	dt += op * (a - last);
	if(dt > 19) {
	    ++cnt;
	    //cout << i <<  " " << dt << endl;
	    dt = 0;
	    op = 0;
	}
	last = a;
    }
    cout << cnt + 1 << endl;
}
