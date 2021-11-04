#include<iostream>

using namespace std;

int main()
{
    int H, N, M;
    cin >> H >> N >> M;
    int nd = H * (H-1);
    int wt2 = 0;
    if(N >= 1 && M + (N - 1) / 2 >= nd) {
	cout << "0 0" << endl;
	return 0;
    }
    if(N % 2 == 0) {
	wt2 = 1;
    }
    nd -= (N - 1 + wt2) / 2;
    cout << wt2 << " " << max(0, nd - M) << endl;
}
