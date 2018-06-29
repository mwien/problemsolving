#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;


int main() {
	int n;
	while (1) {
		cin >> n;
		if (n==0) return 0;

		vector<string> plain(n), cypher(n);
		for (int i=0; i<n; i++) {
			cin >> plain[i] >> cypher[i];
			//cout << plain[i] << cypher[i];
			assert(plain[i].size()==cypher[i].size());
			for (int j=0; j<plain[i].size(); j++) {
				cypher[i][j]-='A';
				plain[i][j]-='A';
			}
		}
		
		string key;
		{
			int i=max_element(plain.begin(), plain.end(), [](auto& a, auto& b) { return a.size()<b.size(); })-plain.begin();
			for (int j=0; j<plain[i].size(); j++) {
				key += (char)((cypher[i][j]-plain[i][j]+26)%26);
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<plain[i].size() && j<key.size(); j++)
				if ((plain[i][j]+key[j])%26!=cypher[i][j]) {
					key.erase(key.begin()+j, key.end());
				}
		}

		for (int i=0; i<n; i++) {
			for (int j=key.size(); j<plain[i].size(); j++)
				if ((plain[i][j]+cypher[i][j-key.size()])%26!=cypher[i][j]) 
					goto impossible;
		}

		for (int j=key.size()-1; j>0; j--) {
			for (int i=0; i<n; i++) {
				if (key[j]!=cypher[i][j])
					goto loop_end;
			}
			key.erase(key.end()-1);
		}
loop_end:

		if (key.empty()) {
impossible:
			cout << "Impossible";
		} else {
			for (char c: key)
				cout << (char)('A'+c);
		}
		cout << endl;

	}

}
