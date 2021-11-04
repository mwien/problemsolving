#include<iostream>
#include<unordered_set>

using namespace std;

int ft[10005];

int main()
{
    int N;
    cin >> N;
    unordered_set<int> tk;
    for(int i = 0; i < N; ++i) {
	int x;
	cin >> x;
	int st = ft[x];
	for(int j = 1; j <= N; ++j) {
	    if(tk.find(st + j*x) == tk.end()) {
		tk.insert(st + j*x);
		ft[x] = st + j*x;
		cout << st + j*x << endl;
		break;
	    }
	}
    }
}
