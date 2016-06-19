#include<iostream>
#include<iterator>
#include<array>

using namespace std;

int g[25];
bool a[1000005] = {false};

int gcd(int a, int b) {
    while(b > 0) {
	int tmp = b;
	b = a % b;
	a = tmp;
    }
    return a;
}

int gcda(int *beg, int *end) {
    int res = *beg;
    ++beg;
    while(beg != end) {
	res = gcd(res, *beg++);
    }
    return res;
}

int main()
{
    int n;
    long long K;
    cin >> n >> K;
    int max = 0;
    for(int i = 0; i < n; i++) {
	cin >> g[i];
	if(g[i] > max) max = g[i];
    }
    if(max * max >= K) {
	a[0] = true;
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j <= K; j++) {
		if(!a[j] || j + g[i] > K) continue;
		a[j + g[i]] = true;
	    }
	}
	cout << (a[K] ? "possible" : "impossible") << endl;
    } else {
	cout << (K % gcda(begin(g), begin(g) + n) == 0 ? "possible" : "impossible") << endl;
    }
}
