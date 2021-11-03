#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
	int n;
	cin >> n;
	unordered_set<int> st;
	for(int i = 0; i < n; ++i) {
	    int a;
	    cin >> a;
	    st.insert(a);
	}
	cout << st.size() << endl;
    }
}
