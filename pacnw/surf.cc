#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long T[1000005];
long long f[1000005];
long long w[1000005];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int a, b, c;
	cin >> a >> b >> c;
	f[a] = b;
	w[a] = c;
    }
    for(int i = 1000000; i >= 0; --i) {
	T[i] = T[i+1];
	if(f[i] == 0) continue;
	T[i] = ((i + w[i] > 1000000) ? max(T[i], f[i]) : max(T[i], T[i + w[i]] + f[i]));
    }
    cout << T[0] << endl;
}
