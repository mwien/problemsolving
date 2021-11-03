#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	s.insert(a);
    }
    for(int i = 0; i < n-1; ++i) {
	int a;
	cin >> a;
	s.erase(a);
    }
    for(int i : s) {
	cout << i << endl;
    }
}
