#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<string> con;
    for(int i = 0; i < n; ++i) {
	string assum;
	while(true) {
	    cin >> assum;
	    if(assum == "->") {
		break;
	    }
	    if(con.find(assum) == con.end()) {
		cout << i+1 << endl;
		return 0;
	    }
	}
	string fol;
	cin >> fol;
	con.insert(fol);
    }
    cout << "correct" << endl;
}
