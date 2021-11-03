#include<iostream>
#include<algorithm>

using namespace std;

pair<int, char> d[3];
char res[1005][1005];

void output(int R, int C) {
    for(int i = 0; i < R; ++i) {
	for(int j = 0; j < C; ++j) {
	    cout << res[i][j];
	}
	cout << endl;
    }
}

bool neighbors_val(int x, int y, int R, int C) {
    for(int i = -1; i < 2; ++i) {
	for(int j = -1; j < 2; ++j) {
	    if((i + j) % 2 == 1 && x + i < R && x + i >= 0 && y + j < C && y + j >= 0 && res[x+i][y+j] == d[1].second) {
		return false;
	    }
	}
    }
    return true;
}

int main()
{
    int R, C;
    cin >> R >> C;
    int a, b, c;
    cin >> a >> b >> c;
    d[0] = {a, 'A'};
    d[1] = {b, 'B'};
    d[2] = {c, 'C'};
    sort(d, d+3);
    if(d[2].first > R*C/2) {
	cout << "impossible" << endl;
	return 0;
    }
    for(int i = 0; i < R; ++i) {
	for(int j = 0; j < C; j += 2) {
	    if(d[2].first != 0) {
		res[i][j + (i%2)] = d[2].second;
		--d[2].first;
	    } else {
		res[i][j + (i%2)] = d[1].second;
		--d[1].first;
	    }
	}
    }
    for(int i = 0; i < R; ++i) {
	for(int j = 1; j < C; j += 2) {
	    int y = j - (i%2);
	    if(d[1].first != 0 && neighbors_val(i, y, R, C)) {
		res[i][y] = d[1].second;
		--d[1].first;
	    } else {
		res[i][y] = d[0].second;
	    }
	}
    }
    for(int i = 0; i < R; ++i) {
	for(int j = 0; j < C; ++j) {
	    cout << res[i][j];
	}
	cout << endl;
    }
}
