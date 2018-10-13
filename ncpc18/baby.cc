#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	string a;
	cin >> a;
	if(a == "mumble") continue;
	if(stoi(a) != i + 1) {
	    cout << "something is fishy" << endl;
	    return 0;
	}
    }
    cout << "makes sense" << endl;
}
