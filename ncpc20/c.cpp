#include<iostream>
#include<algorithm>

using namespace std;

int stck[55];

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int mx = 0;
    for(int i = 0; i < n; ++i) {
	cin >> stck[i];
	sum += stck[i];
	mx = max(mx, stck[i]);
    }
    if(sum % 2 != 0 || 2*mx > sum) {
	cout << "no" << endl;
	return 0;
    }
    cout << "yes" << endl;
    while(true) {
	int hi = 0, shi = 0, hii = -1, shii = -1;
	for(int i = 0; i < n; ++i) {
	    if(stck[i] > hi) {
		int tmp = hi;
		int tmpi = hii;
		hi = stck[i];
		hii = i;
		shi = tmp;
		shii = tmpi;
	    } else if(stck[i] > shi) {
		shi = stck[i];
		shii = i;
	    }
	}
	if(hi == 0) {
	    break;
	}
	stck[hii]--;
	stck[shii]--;
	cout << hii + 1 << " " << shii + 1 << endl;
    }
}
