#include<iostream>
#include<vector>

using namespace std;

int c[5];
int se[4][2];
bool usf[5000];

int main() {
    int n;
    cin >> n;
    if(n == 1) {
	cout << 0 << endl;
	return 0;
    }
    for(int i = 0; i < 625; ++i) {
	// c1-c4
	int cp = i;
	for(int k = 0; k < 4; ++k) {
	    c[k] = (cp % 5) - 2;
	    cp /= 5;
	}
	bool poss = true;
	for(int j = 0; j < 4; ++j) {
	    if(c[j] > 0) {
		se[j][0] = c[j];
	    } else if(c[j] < 0) {
		se[(((j-1)%4)+4)%4][1] = -c[j];
	    }
	}
	for(int j = 0; j < 4; ++j) {
	    if((n - 2 - se[j][0] - se[j][1]) % 3 != 0) poss = false;
	}
	if(poss) {
	    // if(c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0) {
	    // 	cout << "HI" << endl;
	    // }
	    for(int j = 0; j < 4; ++j) {
		int res = j * (n+1) + c[j];
		int mod = 4 * (n+1);
		usf[((res % mod)+mod)%mod] = true;
	    }
	    for(int j = 0; j < 4; ++j) {
		int corner = j * (n + 1);
		int start = corner + 2 + se[j][0];
		int end = (j+1) * (n + 1) - 2 - se[j][1];
		for(int k = start; k <= end; ++k) {
		    if((k - start) % 3 == 1) {
			usf[k] = true;
		    }
		}
	    }
	}
	for(int j = 0; j < 4; ++j) {
	    se[j][0] = 0;
	    se[j][1] = 0;
	}
    }
    vector<int> out;
    for(int i = 0; i < 4*(n+1); ++i) {
	if(!usf[i]) out.push_back(i+1);
    }
    cout << out.size() << endl;
    for(int i = 0; i < out.size(); ++i) {
	cout << out[i] << " ";
    }
    cout << endl;
}
