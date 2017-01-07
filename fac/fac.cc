#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    string in;
    cin >> in;
    vector<int> lf (10);
    lf[0] = 1;
    for(int i = 1; i < 10; ++i)  {
	lf[i] = i * lf[i-1];
    }
    int res = -1;
    if(in.size() <= 6) {
	int ip = stoi(in);
	for(int i = 1; i < 10; ++i) {
	    if(ip == lf[i]) {
		res = i;
		break;
	    }
	}
    } else {
	double cnt = 0;
	int fac = 1;
	while(cnt < in.size()) {
	    cnt += log(fac) / log(10);
	    ++fac;
	}
	res = fac-2;
    }
    cout << res << endl;
}
