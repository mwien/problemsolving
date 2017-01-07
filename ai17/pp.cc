#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int p;
    cin >> p;
    int phi = p - 1;
    vector<int> fac;
    for(int i = 2; i <= sqrt(phi)+1; ++i) {
	if(phi % i == 0) {
	    fac.push_back(i);
	}
    }
    for(int i = 2; i < p; ++i) {
	bool poss = true;
	for(int j = 0; j < fac.size(); ++j) {
	    if(f
	}
    }
}
