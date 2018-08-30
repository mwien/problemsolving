#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ind = 0;
    int sum = 0;
    int last = -2;
    while(ind < n && k > 0) {
	if((s[ind] - 'a') >= (last + 2)) {
	    sum += s[ind] - 'a';
	    ++sum;
	    last = s[ind] - 'a';
	    --k;
	}
	++ind;
    }
    if(k == 0) {
	cout << sum << endl;
    } else {
	cout << -1 << endl;
    }
}
