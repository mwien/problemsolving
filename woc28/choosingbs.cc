#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<iomanip>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

unordered_map<pair<unsigned int, char>, double, pairhash> T; 
string a;
int n, k;

double rec(unsigned int bs, char d)
{
    pair<int, char> b {bs, d};
    unsigned int v = b.first;
    v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
    v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
    v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
    v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
    v = ( v >> 16             ) | ( v               << 16);
    v = (v >> (32 - (n - d)));
    if(T.find(b) != T.end()) return T[b];
    if(T.find({v, b.second}) != T.end()) return T[{v, b.second}];
    if(b.second == k-1) {
	double sum = 0;
	int l = n - b.second;
	for(int i = 0; i < l/2; ++i) {
	    if((b.first & (1 << i)) || (b.first & (1 << (l - i- 1)))) sum += 2;
	}
	if(l % 2 == 1 && (b.first & (1 << l/2))) ++sum;
	double res = sum / l;
	T[b] = res;
	return res;
    }
    double ev = 0;
    int l = n - b.second;
    for(int i = 0; i < l / 2; ++i) {
	int fv = 0, sv = 0;
	if(b.first & (1 << i)) ++fv;
	if(b.first & (1 << (l - i - 1))) ++sv; 
	//create bs
	ev += 2 * max(rec((b.first & ((1 << i) -1)) + ((b.first & (((1 << n) - 1) - ((1 << (i+1))-1))) >> 1), b.second+1) + fv, rec((b.first & ((1 << (l-i-1)) -1)) + ((b.first & (((1 << n) - 1) - ((1 << (l-i))-1))) >> 1), b.second+1) + sv);
    }
    if(l % 2 == 1) {
	int fv = 0;
	if(b.first & (1 << l/2)) ++fv;
	// create bs
	ev += rec((b.first & ((1 << (l/2)) -1)) + ((b.first & (((1 << n) - 1) - ((1 << (l/2+1))-1))) >> 1), b.second+1) + fv;
    }
    double res = ev / l;
    T[b] = res;
    return res;
}

int main()
{
    T.reserve(10000000);
    cin >> n >> k;
    cin >> a;
    int st = 0;
    for(int i = 0; i < n; ++i) {
	if(a[i] == 'W') st += (1 << i);
    }
    cout << fixed << setprecision(10) << rec(st, 0) << endl;
}
