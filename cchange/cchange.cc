#include<iostream>

using namespace std;

long long T[251];

int main()
{
    int N, M;
    cin >> N >> M;
    T[0] = 1;
    for(int i = 0; i < M; ++i) {
	int C;
	cin >> C;
	for(int j = 0; j <= N; ++j) {
	    if(j + C > N) continue;
	    T[j + C] += T[j];
	}
    }
    cout << T[N] << endl;
}
