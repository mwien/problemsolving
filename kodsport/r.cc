#include<iostream>

using namespace std;

bool isright(string f, string s) {
    if(f == "South" && s == "East") return true;
    if(f == "East" && s == "North") return true;
    if(f == "North" && s == "West") return true;
    if(f == "West" && s == "South") return true;
    return false;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    if(!isright(a, c)) {
	if(!isright(c, a)) {
	    if(isright(b, a)) {
		cout << "Yes" << endl;
		return 0;
	    }
	}
    } else {
	if(!isright(a, b)) {
	    cout << "Yes" << endl;
	    return 0;
	}
    }
    cout << "No" << endl;
}
