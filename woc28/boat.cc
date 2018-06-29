#include<iostream>

using namespace std;

int main()
{
    int n, c, m;
    cin >> n >> c >> m;
    int cap = c * m;
    bool poss = true;
    for(int i = 0; i < n; ++i) {
	int p;
	cin >> p;
	if(p > cap) {
	    poss = false;
	    break;
	}
    }
    cout << (poss ? "Yes" : "No") << endl;
}
