#include <iostream>

using namespace std;

long long A[100005];
long long B[100005];
long long length[3];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
	cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
	cin >> B[i];
    }

    for(int i = 0; i < n; ++i) {
	length[i%3] += A[i];
    }
    long long vals[3];
    vals[0] = 0;
    vals[1] = 0;
    vals[2] = 0;
    for (int i = 0; i < n; i++) {
	for(int j = 0; j < 3; ++j) {
	    vals[(j+i+2)%3] += length[j] * B[i]; 
	}
    }

    cout << vals[0] << " " << vals[1] << " " << vals[2] << endl;
}
