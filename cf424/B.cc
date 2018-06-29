#include<iostream>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < c.size(); ++i) {
	bool found = false;
	for(int j = 0; j < a.size(); ++j) {
	    if(a[j] == tolower(c[i])) {
		if(c[i] >= 'a') {
		    cout << (char) b[j];
		} else {
		    cout << (char) toupper(b[j]);
		}
		found = true;
	    }
	}
	if(!found) cout << c[i];
    }
    cout << endl;
}
