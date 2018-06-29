#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
    int k,p;
    cin >> k >> p;
    vector<string> z;
    for(int i = 0; i < 10; ++i) {
	string ig = "";
	z.push_back(ig + (char) ('0' + i) + (char) ('0' + i));
    }
    int old = 0;
    for(int i = 0; i < 5; ++i) {
	int cur = z.size();
	for(int j = old; j < cur; ++j) {
	    for(int l = 0; l < 10; ++l) {
		string nig = (char) ('0' + l) + z[j] + (char) ('0' + l);
		z.push_back(nig);
	    }
	}
	
	old = cur;
    }
    vector<string> nz;
    for(int i = 0; i < z.size(); ++i) {
	if(z[i][0] != '0') nz.push_back(z[i]);
    }
    vector<long long> zn;
    for(int i = 0; i < nz.size(); ++i) {
	zn.push_back(stoll(nz[i]));
    }
    sort(zn.begin(), zn.end());
    long long sum = 0;
    for(int i = 0; i < k; ++i) {
	sum = (sum + zn[i]) % p;
    }
    cout << sum << endl;
}
