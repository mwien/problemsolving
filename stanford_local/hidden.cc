#include<iostream>
#include<vector>

using namespace std;

bool ck(string p, string c, string k) {
    string res = "";
    for(int i = 0; i < p.size(); ++i) {
	if(i < k.size()) {
	    res += ((p[i] + k[i] - 'A') %26) + 'A';
	} else {
	    res += (((p[i] -'A') + (res[i - k.size()] - 'A')) %26) + 'A';
	}
    }
    return res == c;
}

string sk(string p, string c) {
    string key = "";
    for(int i = 0; i < p.size(); ++i) {
	key += (c[i] - p[i] + 26) % 26;
	if(ck(p, c, key)) return key;
    }
    return key;
}

int main() {
    while(true) {
	int n;
	cin >> n;
	if(n == 0) break;
	vector<string> plain (n), cipher (n);
	string k = "", nk = "";
	for(int i = 0; i < n; ++i) {
	    cin >> plain[i] >> cipher[i];
	    nk = sk(plain[i], cipher[i]);
	    // for(int j = 0; j < nk.size(); ++j) {
	    //  	cout << (char) (nk[j] + 'A');
	    //  }
	    //  cout << endl;
	     if(k.size() > 0 && ck(plain[i], cipher[i], k) && k.size() <= nk.size()) {
		continue;
	    }
	    bool better = true;
	    for(int j = 0; j < i; ++j) {
		if(!ck(plain[j], cipher[j], nk)) {
		    better = false;
		    break;
		}
	    }
	    if(better) k = nk;
	}
	bool poss = true;
	for(int i = 0; i < n; ++i) {
	    if(!ck(plain[i], cipher[i], k)) {
		poss = false;
		break;
	    }
	}
	if(poss) {
	    for(int i = 0; i < k.size(); ++i) {
		k[i] += 'A';
	    }
	    cout << k << endl;
	} else {
	    cout << "Impossible" << endl;
	}
    }
}
