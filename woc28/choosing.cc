#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<iomanip>

using namespace std;

unordered_map<string, double> T; 
string a;
int n, k;

double rec(string b, int d)
{
    if(T.find(b) != T.end()) return T[b];
    if(d == k) return 0;
    double ev = 0;
    int l = n - d;
    for(int i = 0; i < l / 2; ++i) {
	string f = "", s = "";
	int fv = 0, sv = 0;
	if(b[i] == 'W') ++fv;
	if(b[l-i-1] == 'W') ++sv; 
	for(int j = 0; j < l; ++j) {
	    if(j != i) f += b[j];
	    if(j != l-i-1) s += b[j];
	}
	ev += 2 * max(rec(f, d+1) + fv, rec(s, d+1) + sv);
    }
    if(l % 2 == 1) {
	string f = "";
	int fv = 0;
	if(b[l/2] == 'W') ++fv;
	for(int j = 0; j < l; ++j) {
	    if(j != l/2) f += b[j];
	}
	ev += rec(f, d+1) + fv;
    }
    T[b] = ev / l;
    return T[b];
}

int main()
{
    cin >> n >> k;
    cin >> a;
    cout << fixed << setprecision(10) << rec(a, 0) << endl;
}
