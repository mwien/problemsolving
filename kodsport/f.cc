#include<iostream>

using namespace std;

char grid[55][55];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    cin >> grid[i][j];
	}
    }
    bool done = false;
    while(!done) {
	done = true;
	for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < m; ++j) {
		if(i < n-1 && grid[i][j] == 'V' && grid[i+1][j] == '.') {
		    grid[i+1][j] = 'V';
		    done = false;
		}
		if(i < n-1 && grid[i][j] == 'V' && grid[i+1][j] == '#' && j > 0 && grid[i][j-1] == '.') {
		    grid[i][j-1] = 'V';
		    done = false;
		}
		if(i < n-1 && grid[i][j] == 'V' && grid[i+1][j] == '#' && j < m-1 && grid[i][j+1] == '.') {
		    grid[i][j+1] = 'V';
		    done = false;
		}
	    }
	}
    }
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    cout << grid[i][j];
	}
	cout << endl;
    }
}
