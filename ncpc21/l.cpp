#include<iostream>
#include<numeric>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int res = 1e9;
    for(int i = 0; i < k; ++i) {
	int y, c1, c2;
	cin >> y >> c1 >> c2;
	res = min(res, y + lcm(c1,c2));
    }
    cout << res << endl;
}
