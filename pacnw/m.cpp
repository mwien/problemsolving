#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	set<int> se;
	for (int i=1; i<=100; i++) 
		se.insert(i);

	int n;
	cin >> n;
	for (int l=0; l<n; l++) {
		string s;
		int op;
		cin >> s >> op;

		set<int> newset;
		if (s=="ADD")
			for (int i : se)
				newset.insert(i+op);
		if (s=="MULTIPLY")
			for (int i : se)
				newset.insert(i*op);
		if (s=="SUBTRACT")
			for (int i : se) {
				if (i>=op)
					newset.insert(i-op);
			}
		if (s=="DIVIDE")
			for (int i : se) {
				if (i%op == 0)
					newset.insert(i/op);
			}
		se = (newset);
	}
	cout << 100 - se.size() << endl;
}
