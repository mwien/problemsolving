#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> diff;
    int sum = 0;
    int max = -1000;
    int maxind = -1;
    int min = 1000;
    int minind = -1;
    for(int i = 0; i < n; ++i) {
	int a, b;
	cin >> a >> b;
	diff.push_back(a-b);
	sum += a - b;
	if(a - b > max) {
	    max = a-b;
	    maxind = i+1;
	}
	if(a - b <  min) {
	    min = a-b;
	    minind = i+1;
	}
    }
    if(abs(sum) > abs(sum - 2*min) && abs(sum) > abs(sum - 2*max)) {
	cout << 0 << endl;
    } else if(abs(sum - 2*min) > abs(sum - 2*max)) {
	cout << minind << endl;
    } else {
	cout << maxind << endl;
    }
}
