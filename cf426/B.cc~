#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int getpos(char a)
{
    if(a == 118) return 0;
    if(a == 60) return 1;
    if(a == 94) return 2;
    if(a == 62) return 3;
}

int main()
{
    char a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int s = getpos(a);
    int t = getpos(b);
    if((s + n) % 4 != t && (t + n) % 4 == s) {
	cout << "ccw" << endl;
    } else if((s + n) % 4 == t && (t + n) % 4 != s) {
	cout << "cw" << endl;
    } else {
	cout << "undefined" << endl;
    }
}
