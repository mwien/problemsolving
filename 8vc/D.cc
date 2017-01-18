#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int ft[10000005];
int n;

int read(int index) {
   int sum = 0;
   while (index > 0) {
      sum += ft[index];
      index -= (index & -index);
   }
   return sum;
}

void update(int index, int addValue) {
   while (index <= n) {
      ft[index] += addValue;
      index += (index & -index);
   }
}

int main()
{
    int k;
    cin >> n >> k;
    int pos = 1;
    long long sum = 1;
    for(int i = 0; i < n; ++i) {
	int npos = pos + k;
	if(npos > n) npos -= n;
	//cout << read(npos) << " " << npos << " "  << read(pos) << " " << pos << endl;
	int bg = max(npos, pos), sm = min(npos, pos);
	if(bg - sm <= n/2) {
	    sum += 1 + read(bg-1) - read(sm);
	} else {
	    sum += 1 + read(sm-1) + read(n) - read(bg);
	}
	cout << sum << " ";
	update(npos, 1);
	update(pos, 1);
	pos = npos;
    }
    cout << endl;
}
