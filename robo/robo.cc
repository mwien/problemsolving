#include<iostream>
#include<utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int l1, a1, l2, a2, lt, at;
	cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
	pair<int, int> res = {-1, -1};
	bool poss = false;
	int lim = lt / l1;
	if(lt % l1 != 0) ++lim;
	for(int j = 1; j < lim; ++j) {
	    if(at - j*a1 < 0) continue;
	    if((lt - j*l1) % l2 == 0 && (at - j*a1) % a2 == 0 && (lt - j*l1) / l2 == (at - j*a1) / a2) {
		if(res.first == -1) {
		    poss = true;
		    res.first = j;
		    res.second = (lt - j*l1) / l2;
		} else {
		    poss = false;
		}
	    }
	}
	if(poss) {
	    cout << res.first << " " << res.second << endl;
	} else {
	    cout << "?" << endl;
	}
    }
}
