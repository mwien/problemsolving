#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int pd[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	long long a, b;
	cin >> a >> b;
	long long r = pow(a*b, 1/3.0);
	if(r * r * r != a * b) {
	    ++r;
	    if(r * r * r != a * b) {
		cout << "No" << endl;
		continue;
	    }
	}
	int cnt = 0;
	while (r%2 == 0) {
	    if(a % 2 == 0 && b % 2 == 0) {
		a /= 2;
		b /= 2;
		pd[cnt] = 2;
		++cnt;
	    }
	    r = r/2;
	}
	for (int i = 3; i <= sqrt(r); i = i+2) {
	    while (r%i == 0) {
		r = r/i;
		if(a % i == 0 && b % i == 0) {
		    a /= i;
		    b /= i;
		    pd[cnt] = i;
		    ++cnt;
		}
	    }
	}
	if(r > 2) {
	    if(a % r == 0 && b % r == 0) {
		a /= r;
		b /= r;
		pd[cnt] = r;
		++cnt;
	    }
	}
	int poss = true;
	for(int i = 0; i < cnt; ++i) {
	    if(a % pd[i] != 0 && b % pd[i] != 0) {
		poss = false;
		break;
	    }
	    if(a % pd[i] == 0) {
		a /= pd[i];
	    } else if(b % pd[i] == 0) {
		b /= pd[i];
	    }
	}
	if(a == 1 && b == 1 && poss) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
}
