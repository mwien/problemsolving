#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int T[55];

int main() {
    string a;
    cin >> a;
    int n = a.size();
    for(int i = 0; i < n; ++i) {
	T[i] = a[i] - 'a';
	for(int j = 0; j < i; ++j) {
	    if(a[j] - a[i] >= 0) continue;
	    T[i] = min(T[i], T[j] + a[i] - a[j] - 1);
	}
    }
    int res = 100;
    for(int i = 0; i < n; ++i) {
	res = min(res, T[i] + 'z' - a[i]);
    }
    cout << res << endl;
}
