#include<iostream>

using namespace std;

int main() {
    long long n, b;
    cin >> n >> b;
    while(n > 1) {
	n /= 2;
	--b;
    }
    if(b >= 0) {
	cout << "yes" << endl;
    } else {
	cout << "no" << endl;
    }
}
