#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

int D[105];

int main()
{
	int M;
	cin >> M;
	int sum = 0;
	for(int i = 0; i < M; ++i) {
		cin >> D[i];
		sum += D[i];
	}
	int nsum = 0;
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < D[i]; ++j) {
			++nsum;
			if(sum - nsum + 1 == nsum) {
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}
}
