#include<iostream>

using namespace std;

int main()
{
    int y;
    cin >> y;
    bool poss = false;
    for(int i = 1; i <= 12; ++i) {
	if(((y - 2018) * 12 - 4 + i) % 26 == 0) poss = true;
    }
    cout << (poss ? "yes" : "no") << endl;
}
