#include<iostream>
#include<list>

using namespace std;

int main()
{
    int n;
    cin >> n;
    list<int> scks;
    for(int i = 0; i < 2*n; ++i) {
	int a;
	cin >> a;
	scks.push_back(a);
    }
    auto it = scks.begin();
    auto nit = scks.begin();
    ++nit;
    while(!scks.empty()) {
	if(nit == scks.end() || it == scks.end()) {
	    break;
	}
	if(*it == *nit) {
	    nit = scks.erase(nit);
	    it = scks.erase(it);
	    if(it == scks.begin()) {
		++nit;
	    } else {
		--it;
	    }
	} else {
	    ++it;
	    ++nit;
	}
    }
    if(scks.empty()) {
	cout << 2*n <<endl;
    } else {
	cout << "impossible" << endl;
    }
}
