#include<iostream>
#include<string>

using namespace std;

int main() {
    int n = 1;
    int sz = 1000000;
    cout << n << endl;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < sz; ++j) {
	    cout << 'v';
	}
	cout << " ";
	cout << sz;
	for(int j = 0; j < sz; ++j) {
	    cout  << " " << j + 1;
	}
	cout << endl;
    }
}
