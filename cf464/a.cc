#include<iostream>

using namespace std;

int f[5005];
bool vis[5005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> f[i];
	--f[i];
    }
    for(int i= 0;  i < n; ++i) {
	if(vis[i]) continue;
	vis[i] = true;
	int cnt = 1;
	int tmp = f[i];
	vis[tmp] = true;
	while(cnt < 3 && tmp != i) {
	    ++cnt;
	    tmp = f[tmp];
	    vis[tmp] = true;
	}
	if(tmp == i && cnt == 3) {
	    cout << "YES\n";
	    return 0;
	}
    }
    cout << "NO\n";
}
