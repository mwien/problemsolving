#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long carts[500005];
pair<double, int> T[500005];
long long l, a, b, t, r;

double timeto(long long i, long long j) {
    long long cd = i + t*a;
    double tme = (min(cd, j) - i) / (double) a;
    long long dn = cd + r*b;l;
    if(cd < j) {
	tme += (min(dn, j) - cd) / (double) b;
    }
    if(dn < j) {
	tme += (j - dn) / (double) a;
    }
    return tme;
}

int main()
{
    cin >> l >> a >> b >> t >> r;
    int n;
    cin >> n;
    if(n == 0) {cout << 0 << endl; return 0;}
    for(int i = 0; i < n; ++i) {
	cin >> carts[i];
    }
    carts[n] = l;
    T[n].first = 0;
    T[n].second = -1;
    for(int i = n-1; i >= 0; --i) {
	long long cd = carts[i] + t*a + r*b;
	int lo = 0;
	int hi = n;
	int mid = (lo + hi) / 2;
	while(true) {
	    mid = (lo + hi) / 2;
	    if(mid >= n) break;
	    if(mid <= 0) break;
	    if(carts[mid] == cd) break;
	    if(carts[mid] < cd && carts[mid+1] >= cd) {
		break;
	    }
	    if(carts[mid] < cd) {
		lo = mid + 1;
	    }
	    if(carts[mid] > cd) {
		hi = mid - 1;
	    }
	}
	T[i].first = T[i+1].first + timeto(carts[i], carts[i+1]);
	T[i].second = i+1;
	if(mid > 0 && mid -1 > i) {
	    double tmp =  timeto(carts[i], carts[mid-1])+T[mid-1].first;
	    if(tmp < T[i].first) {
		T[i].first = tmp;
		T[i].second = mid-1;
	    }
	}
	if(mid > i) {
	    double tmp =  timeto(carts[i], carts[mid]) + T[mid].first;
	    if(tmp < T[i].first) {
		T[i].first = tmp;
		T[i].second = mid;
	    }
	}
	if(mid < n && mid + 1 > i) {
	    double tmp = timeto(carts[i], carts[mid+1]) + T[mid+1].first;
	    if(tmp < T[i].first) {
		T[i].first = tmp;
		T[i].second = mid+1;
	    }
	}
    }
    double mn = 1e39;
    int mni = -1;
    for(int i = 0; i < n; ++i) {
	double dst = a*carts[i] + T[i].first;
	if(dst < mn) {
	    mn = dst;
	    mni = i;
	}
    }
    vector<int> res;
    int ind = mni;
    while(ind != -1) {
	res.push_back(ind);
	ind = T[ind].second;
    }
    cout << res.size()-1 << endl;
    for(int i = 0; i < res.size()-1; ++i) {
	cout << res[i] << " ";
    }
    cout << endl;
}
