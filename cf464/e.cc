#include<iostream>

using namespace std;

int T[500005];

int main()
{
    int q;
    cin >> q;
    int cnt = 0;
    long long sum = 0;
    int ind = 0;
    for(int i = 0; i < q; ++i) {
	int t;
	cin >> t;
	if(t == 1) {
	    cin >> T[cnt];
	    ++cnt;
	} else {
	    for(; ind < cnt-1; ++ind) {
		if((double) (sum + T[ind] + T[cnt-1]) / (ind + 2) > (double) (sum + T[cnt-1]) / (ind +1)) {
		    break;
		} else {
		    sum += T[ind];
		}
	    }
			   printf("%.11f\n", T[cnt-1] - (double) (sum + T[cnt-1]) / (ind + 1));
	}
    }
}
