#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int b,w,h;
	cin >> w >> h >> b;
	vector<vector<int>> in, out;
	in.resize(h);
	for (int i=0; i<h; i++) {
		in[i].resize(w);
		for (int j=0; j<w; j++)
			cin >> in[i][j];
	}

	out = in;

	for (int k=0; k<b; k++) {
		for (int t=0; t<h; t++)
			for (int s=0; s<w; s++) {
				int sum = 0;
				for (int j=-1; j<=1; j++)
					for (int i=-1; i<=1; i++)
						sum += in[(i+h+t)%h][(j+w+s)%w];
				out[t][s] = sum;
			}
		swap(in, out);
	}

	set<int> se;
	for (int t=0; t<h; t++)
		for (int s=0; s<w; s++)
			se.insert(in[t][s]);

	cout << se.size() << endl;
}
