#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

const int MB = 32;
double T[10005][MB];
pair<int,int> p[10005];

double npow(int i) {
	if(i < 0) return 0;
	else return pow(2.0, i);
}

double dist(int i, int j) {
	double dx = p[j].first - p[i].first;
	double dy = p[j].second - p[i].second;
	double ret = sqrt(dx*dx + dy*dy);
	return ret;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		p[i] = {x,y};
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < MB; ++j) {
			T[i][j] = (1LL << 62);
		}
	 }
	T[0][0] = 0;
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < MB; ++j) {
			for(int k = 0; k < MB; ++k) {
				if(i-k-1 < 0) continue;
				if(j-k < 0) continue;
				if(k >= 1) {
					T[i][j] = min(T[i][j], T[i-k-1][j-k] + dist(i, i-k-1) + npow(j-1) - npow(j-k-1));
				} else {
					T[i][j] = min(T[i][j], T[i-k-1][j-k] + dist(i, i-k-1));
				}
			}
		}
	}
	//for(int i = 0; i < n; ++i) {
//		for(int j = 0; j <= MB; ++j) {
//			cout << T[i][j] << " ";
//		}
//		cout << endl;
//	}	

	double res = (1LL << 62);
	for(int j = 0; j < MB; ++j) {
		res = min(res, T[n-1][j]);
	}
	printf("%.12f\n", res);
}



