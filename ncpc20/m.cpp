#include<iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int ac = 0, bc = 0;
    for(int i = 0; i < a.size(); ++i) {
	if(a[i] == 'S') ++ac;
    }
    for(int i = 0; i < b.size(); ++i) {
	if(b[i] == 'S') ++bc;
    }
    for(int i = 0; i < ac*bc; ++i) {
	cout << "S(";
    }
    cout << 0;
    for(int i = 0; i < ac*bc; ++i) {
	cout << ")";
    }
    cout << endl;
}
