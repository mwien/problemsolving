#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long k;
    cin >> k;
    string s;
    cin >> s;
    long long sum = 0;
    for(int i = 0; i < s.size(); ++i) {
	sum += s[i] - '0';
    }
    if(sum >= k) cout << 0 << endl;
    else {
	sort(s.begin(), s.end());
	for(int i = 0; i < s.size(); ++i) {
	    sum += '9' - s[i];
	    if(sum >= k) {
		cout << i + 1 << endl;
		break;
	    }
	}
    }
}
