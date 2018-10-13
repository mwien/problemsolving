#include<iostream>
#include<string>

using namespace std;

int g[105][105];

int main()
{
    int N;
    cin >> N;
    string a;
    cin >> a;
    for(int i = 0; i < N; ++i) {
	for(int j = 0; j < N; ++j) {
	    g[i][j] = a[i*N+j];
	}
    }
}
