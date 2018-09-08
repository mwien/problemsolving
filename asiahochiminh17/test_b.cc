#include<iostream>

using namespace std;

bool eq(int j, int i) {
    int ocnt = 0;
    while(j != 0) {
	if(j % 2) ++ocnt;
	j /= 2;
    }
    if(ocnt == (i - ocnt)) return true;
    return false;
}

bool con(int j) {
    int last = 0;
    while(j != 0) {
	int nn = j % 2;
	if(nn == 1 && last == 1) return false;
	j /= 2;
	last = nn;
    }
    return true;
}

int main()
{
    for(int i = 2; i <= 24; i += 2) {
	int fcnt = 0, cnt = 0, scnt = 0;
	for(int j = 0; j < (1 << i); ++j) {
	    if(eq(j, i) || con(j)) {
		++cnt;
	    }
	    if(eq(j, i)) {
		++fcnt;
	    }
	    if(con(j)) {
		++scnt;
	    }
	}
	cout << i << " " << cnt % 3 << " " << fcnt % 3 << " " << scnt % 3 << endl;
    }
}
