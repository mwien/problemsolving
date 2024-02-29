#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const string snuke = "snuke";
char grid[505][505];
bool vis[505][505][6];
int H, W;

void dfs(int x, int y, int z)
{
	vis[x][y][z] = true;
	for(int px = -1; px <= 1; ++px) {
		for(int py = -1; py <= 1; ++py) {
			if((px + py) % 2 == 0) continue;
			if(y + py < 0 || y + py >= W) continue;
			if(x + px < 0 || x + px >= H) continue;
			if(grid[x+px][y+py] != snuke[(z+1)%5]) continue;
			if(!vis[x+px][y+py][(z+1)%5]) {
				dfs(x+px, y+py, (z+1)%5);
			}
		}
	}
}


int main()
{
	cin >> H >> W;
	for(int i = 0; i < H; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < W; ++j) {
			grid[i][j] = s[j];
		}
	}
	if(grid[0][0] != 's') {
		cout << "No" << endl;
		return 0;
	}
	dfs(0,0,0);
	for(int i = 0; i < 5; ++i) {
		if(vis[H-1][W-1][i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
