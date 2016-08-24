#include<iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n) {
	int res = n;
	int cnt = 1;
	while(true) {
	    for(int i = 0; i < 10; i++) {
		int tmp = res + n * i;
		if(tmp % 10 == 1) {
		    res = tmp;
		    break;
		}
	    }
	    res = res/10;
	    if(res == 0) break;
	    ++cnt;
	}
	cout << cnt << endl;
    }
}
