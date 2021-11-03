#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cubes, cyls;
    cubes.push_back(20000);
    cyls.push_back(20000);
    for(int i = 0; i < n; ++i) {
	string block;
	int a;
	cin >> block >> a;
	if(block == "cube") cubes.push_back(a);
	if(block == "cylinder") cyls.push_back(a);
    }
    sort(cubes.begin(), cubes.end());
    sort(cyls.begin(), cyls.end());
    reverse(cubes.begin(), cubes.end());
    reverse(cyls.begin(), cyls.end());

    string out = "";
    
    for(int i = 0; i < n; ++i) {
	int a = cubes.back();
	int b = cyls.back();
	if(b * 2 <= a) {
	    out += "cylinder " + to_string(b) + "\n";
	    cyls.pop_back();
	} else if(a * a <= 2 * b * b) {
	    out += "cube " + to_string(a) + "\n";
	    cubes.pop_back();
	} else {
	    cout << "impossible" << endl;
	    return 0;
	}
    }
    cout << out;
}
