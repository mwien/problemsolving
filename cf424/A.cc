#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ph = 0;
    bool poss = true;
    int last;
    cin >> last;
    for(int i = 0; i < n-1; ++i) {
	int a;
	cin >> a;
	if(a == last && (ph == 0|| ph == 1)) {
	    ph = 1;
	} else if(a == last && ph == 2) {
	    poss = false;
	} else if(a > last && ph != 0) {
	    poss = false;
	} else if(a < last) {
	    ph = 2;
	}
	last = a;
    }
    cout << (poss ? "YES" : "NO") << endl;
}
