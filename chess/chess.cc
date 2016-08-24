#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int n = 0; n < N; n++) {
	string sc, ec;
	int sr, er;
	cin >> sc >> sr >> ec >> er;
	int diffc = sc[0] - ec[0], diffr = sr - er;
	if((diffc + diffr) % 2 != 0) cout << "Impossible" << endl;
	else {
	    if(diffc == 0 && diffr == 0) cout << 0 << " " << sc[0] << " " << ec[0] << endl;
	    else if(diffc == 0) {
		cout << 2 << " ";
		if(sr >= 5) {
		    cout << sc[0]
		}
	    }
	}
    }
}
