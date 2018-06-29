#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int s, x1, x2;
    cin >> s >> x1 >> x2;
    int t1, t2;
    cin >> t1 >> t2;
    int p, d;
    cin >> p >> d;
    int first, sec, t2i;
    first = abs(x2 - x1) * t2;
    if(d == -1 && x1 <= p) {
	t2i = abs(p - x1) * t1;
    } else if(d == -1 && x1 > p) {
	d = 1;
	t2i = (abs(p - x1) + 2*p) * t1;
    } else if(d == 1 && x1 >= p) {
	t2i = abs(p-x1) * t1;
    } else if(d == 1 && x1 < p) {
	d = -1;
	t2i = (abs(p-x1) + 2*(s-p)) * t1;
    }
    if(d == -1 && x2 <= x1) {
	sec = abs(x2-x1) * t1 + t2i;
    } else if(d == -1 && x2 > x1) {
	sec = (abs(x2-x1) + 2*x1) * t1 + t2i;
    } else if(d == 1 && x2 >= x1) {
	sec = abs(x2-x1) * t1 + t2i;
    } else if(d == 1 && x2 < x1) {
	sec = (abs(x2-x1) + 2 * (s-x1)) * t1 + t2i;
    }
    cout << min(first, sec) << endl;
}
