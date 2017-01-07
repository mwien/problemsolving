#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mxi = (1 << 25);

int main()
{
    int H;
    cin >> H;
    vector<int> h;
    int sumh = 0;
    for(int i = 0; i < H; ++i) {
	int a;
	cin >> a;
	h.push_back(a);
	sumh += a;
    }
    int B;
    cin >> B;
    vector<int> b;
    int sumb = 0;
    for(int i = 0; i < B; ++i) {
	int a;
	cin >> a;
	b.push_back(a);
	sumb += a;
    }
    vector<pair<bool, int>> Th (sumh+1, {false, mxi}) , Tb (sumb+1, {false, mxi});
    Th[0].first = true;
    Th[0].second = 0;
    Tb[0].first = true;
    Tb[0].second = 0;
    for(int i = 0; i < H; ++i) {
	for(int j = sumh; j >= 0; --j) {
	    if(Th[j].first && (j + h[i] <= sumh)) {
		Th[j+h[i]].first = true;
		if(Th[j].second + 1 < Th[j+h[i]].second) {
		    Th[j + h[i]].second = Th[j].second + 1;
		}
	    }
	}
    }
    for(int i = 0; i < B; ++i) {
	for(int j = sumb; j >= 0; --j) {
	    if(Tb[j].first && (j + b[i] <= sumb)) {
		Tb[j+b[i]].first = true;
		if(Tb[j].second + 1 < Tb[j+b[i]].second) {
		    Tb[j + b[i]].second = Tb[j].second + 1;
		}
	    }
	}
    }
    int res = mxi;
    for(int i = 1; i <= min(sumh, sumb); ++i) {
	if(Th[i].first && Tb[i].first) {
	    res = min(res, Th[i].second + Tb[i].second);
	}
    }
    if(res == mxi) {
	cout << "impossible" << endl;
    } else {
	cout << res << endl;
    }
}
