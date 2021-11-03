#include<iostream>

using namespace std;

long long A[3];
long long C[3];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
	long long a;
	cin >> a;
	A[i%3] += a;
    }
    for(int i = 1; i <= n; ++i) {
	long long b;
	cin >> b;
	for(int j = 0; j < 3; ++j) {
	    C[j] += A[(((j-i)%3)+3)%3] * b;
	}
    }
    cout << C[0] << " " << C[1] << " " << C[2] << endl;
    
}
