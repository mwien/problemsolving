#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;

char grid[2005][2005];
int rows[2005][26];
int cols[2005][26];

void rem(int i, int j) {
	if(grid[i][j] == '.') return;
	rows[i][grid[i][j] - 'a'] -= 1;
	cols[j][grid[i][j] - 'a'] -= 1;	
	grid[i][j] = '.';
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> marked;
	set<int> ro;
	set<int> co;

	for(int i = 0; i < n; ++i) {
		ro.insert(i);
	}

	for(int i = 0; i < m; ++i) {
		co.insert(i);
	}

	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < m; ++j) {
			grid[i][j] = s[j];
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			++rows[i][grid[i][j] - 'a'];
			++cols[j][grid[i][j] - 'a'];
		}
	}
	while(true) {
		//for(int i = 0; i < n; ++i) {
	//		for(int j = 0; j < m; ++j) {
//				cout << grid[i][j] << " ";
//
//			}
//			cout << endl;
//		}	
		marked.clear();
		vector<int> erro;
		for(int i : ro) {
			int nz = 0;
			int anz = 0;
			for(int k = 0; k < 26; ++k) {
				if(rows[i][k] > 1) ++nz;	
				if(rows[i][k] > 0) ++anz;	
			}
			if(nz == 1 && anz == 1) {
				for(int j = 0; j < m; ++j) {
					if(grid[i][j] != '.') { 
					marked.push_back({i,j});
					}
				}
				erro.push_back(i);
			}
		}
		for(int i : erro) {
			ro.erase(i);
		}
		vector<int> erco;
		for(int i : co) {
			int nz = 0;
			int anz = 0;
			for(int k = 0; k < 26; ++k) {
				if(cols[i][k] > 1) ++nz;	
				if(cols[i][k] > 0) ++anz;	
			}
			if(nz == 1 && anz == 1) {
				for(int j = 0; j < n; ++j) {
					if(grid[j][i] != '.') { 
					marked.push_back({j,i});
					}
				}
				erco.push_back(i);
			}
		}
		for(int i : erco) {
			co.erase(i);
		}
		for(pair<int,int> p : marked) {
			int i = p.first;
			int j = p.second;
			//cout << i << " " << j << endl;
			rem(i,j);
		}
		if(marked.size() == 0) {
			break;
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			//cout << ngrid[i][j];
			if(grid[i][j] != '.') ++cnt;
		}
		//cout << endl;
	}
	cout << cnt << endl;
}


