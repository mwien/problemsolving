#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

const int SZ = 305;
int T[SZ][SZ][8];
bool vis[SZ][SZ];

int main()
{
    int n;
    cin >> n;
    T[SZ/2][SZ/2][0] = 1;
    vis[SZ/2][SZ/2] = true;
    for(int i = 0; i < n; ++i) {
	int t;
	cin >> t;
	for(int j = 0; j < SZ; ++j) {
	    for(int k = 0; k < SZ; ++k) {
		for(int l = 0; l < 8; ++l) {
		    if(T[j][k][l] == i+1) {
			switch(l) {
			case 0:
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k+t][1] = i+2;
			    vis[j+t][k+t] = true;
			    for(int m = j; m >= j-t; --m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k+t][7] = i+2;
			    vis[j-t][k+t] = true;
			    break;
			case 1:
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o <= k; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j][k+t][0] = i+2;
			    vis[j][k+t] = true;
			    for(int m = j; m <= j; ++m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k][2] = i+2;
			    vis[j+t][k] = true;
			    break;
			case 2:
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k+t][1] = i+2;
			    vis[j+t][k+t] = true;
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k-t][3] = i+2;
			    vis[j+t][k-t] = true;
			    break;
			case 3:
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o <= k; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k][2] = i+2;
			    vis[j+t][k] = true;
			    for(int m = j; m <= j; ++m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j][k-t][4] = i+2;
			    vis[j][k-t] = true;
			    break;
			case 4:
			    for(int m = j; m <= j+t; ++m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j+t][k-t][3] = i+2;
			    vis[j+t][k-t] = true;
			    for(int m = j; m >= j-t; --m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k-t][5] = i+2;
			    vis[j-t][k-t] = true;
			    break;
			case 5:
			    for(int m = j; m <= j; ++m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j][k-t][4] = i+2;
			    vis[j][k-t] = true;
			    for(int m = j; m >= j-t; --m) {
				for(int o = k; o <= k; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k][6] = i+2;
			    vis[j-t][k] = true;
			    break;
			case 6:
			    for(int m = j; m >= j-t; --m) {
				for(int o = k; o >= k-t; --o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k-t][5] = i+2;
			    vis[j-t][k-t] = true;
			    for(int m = j; m >= j-t; --m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k+t][7] = i+2;
			    vis[j-t][k+t] = true;
			    break;
			case 7:
			    for(int m = j; m <= j; ++m) {
				for(int o = k; o <= k+t; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j][k+t][0] = i+2;
			    vis[j][k+t] = true;
			    for(int m = j; m >= j-t;--m) {
				for(int o = k; o <= k; ++o) {
				    vis[m][o] = true;
				}
			    }
			    T[j-t][k][6] = i+2;
			    vis[j-t][k] = true;
			    break;
			}
		    }
		}
	    }
	}
    }
    int cnt = 0;
    for(int i= 0; i < SZ; ++i) {
	for(int j = 0; j < SZ; ++j) {
	    if(vis[i][j]) ++cnt;
	}
    }
    cout << cnt << endl;
}
