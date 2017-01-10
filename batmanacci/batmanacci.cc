#include<iostream>
#include<vector>

using namespace std;

long long mx = 1e18;

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> F (N+1, -1);
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i < N+1; ++i) {
	F[i] = F[i-1] + F[i-2];
	if(F[i] > mx) {
	    F[i] = -1;
	    break;
	}
    }
    // for(auto it = F.cbegin(); it != F.cend(); ++it) {
    // 	cout << *it << " ";
    // }
    // cout << endl;
    char res;
    int j = N;
    while(true) {
	if(j == 1) {
	    res = 'N';
	    break;
	}
	if(j == 2) {
	    res = 'A';
	    break;
	}
	if(F[j-2] == -1) {
	    j -= 2;
	} else if(F[j-2] >= K) {
	    j -= 2;
	} else {
	    K -= F[j-2];
	    j -= 1;
	}
    }
    cout << res << endl;
}
