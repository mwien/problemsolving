#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int h[(1 << 8)];
int r[(1 << 8)];

int main()
{
    while(true) {
	int n;
	cin >> n;
	if(n == 0) break;
	for(int i = 0; i < (1 << 8); i++) {
	    h[i] = 0;
	    r[i] = 0;
	}
	unordered_map<string, int> dupl;
	for(int i = 0; i < n; i++) {
	    string in;
	    if(i == 0) getline(cin, in);
	    getline(cin, in);
	    dupl.insert({in, i});
	    char sum = 0;
	    for(int j = 0; j < in.size(); j++) {
		sum ^= in[j];
	    }
	    if(dupl[in] != i) {
		++r[sum];
		--h[sum];
	    }
	    ++h[sum];
	}
	int coll = 0;
	for(int j = 0; j < (1 << 8); j++) {
	    if(h[j] > 0) coll += h[j]*(h[j]-1)/2 + r[j]*(h[j]-1);
	}
	cout << dupl.size() << " " << coll << endl;
    }
}
