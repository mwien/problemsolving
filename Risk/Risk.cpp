#include<iostream>
#include<iomanip>
using namespace std;

void floydWarshall(int graph[][20], int ans[][20]) {
   for(int i = 0; i < 20; i++) {
      for(int j = 0; j < 20; j++) {
         ans[i][j] = graph[i][j];
      }
   }
   for (int k = 0; k < 20; k++) {
      for (int i = 0; i < 20; i++) {
         for (int j = 0; j < 20; j++) {
            if (ans[i][k] + ans[k][j] < ans[i][j]
            && ans[i][k] < 100 && ans[k][j] < 100) {
               ans[i][j] = ans[i][k] + ans[k][j];
            }
         }
      }
   }
}


int main()
{
    int N;
    int cnt = 1;
    while(cin >> N) {
	int G[20][20];
	for(int i = 0; i < 20; i++) {
	    for(int j = 0; j < 20; j++) {
		G[i][j] = 100;
	    }
	}
	int next;
	for(int n = 0; n < N; n++) {
	    cin >> next;
	    G[0][next-1] = 1;
	    G[next-1][0] = 1;
	}
	for(int i = 1; i < 19; i++) {
	    cin >> N;
	    for(int n = 0; n < N; n++) {
		cin >> next;
		G[i][next-1] = 1;
		G[next-1][i] = 1;
	    }
	}
	cin >> N;
	int dist[20][20];
	floydWarshall(G, dist);
	cout << "Test Set #" << cnt << endl;
	cnt++;
	for(int n = 0; n < N; n++) {
	    int a,b;
	    cin >> a >> b;
	    int d = dist[a-1][b-1];
	    cout << right << setw(2) << a << " to " << right << setw(2) << b << ": " << d << endl;
	}
	cout << endl;
    }
}
