#include<iostream>

using namespace std;

int lc[1005];
int p[1005];
int lf[1005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
	cin >> p[i];
    }
    for(int i = 0; i < n; ++i) {
	lf[i] = 1;
    }
    for(int i = 1; i < n; ++i) {
	lf[p[i]-1] = 0;
    }
    for(int i = 1; i < n; ++i) {
	lc[p[i]-1] += lf[i];
    }
    bool sp = true;
    for(int i = 0; i < n; ++i) {
	if(lf[i] == 1 || lc[i] >= 3) continue;
	sp = false;
    }
    cout << (sp ? "Yes" : "No") << endl;
}
