#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	int n;
	cin >> n;
	int nm = 0;
	int ln = -1;
	int nn = n;
	while(nn != 0) {
	    ++nm;
	    ln = nn % 10;
	    nn /= 10;
	}
	int res = (nm - 1) * 9 + max(0, ln-1);
	int cmp = 0;
	int mt = 1;
	for(int i = 0; i < nm; ++i) {
	    cmp += ln*mt;
	    mt *= 10;
	}
	if(n >= cmp) ++res;
	cout << res << endl;
    }
}
