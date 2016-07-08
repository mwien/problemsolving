#include<iostream>

using namespace std;

int A[2*100005];
int pos[100005];

int sum(int i)
{
    int sum = 0;
    while(i > 0) {
	sum += A[i];
	i -= i & -i;
    }
    return sum;
}

void add(int i, int k, int size)
{
    while(i < size) {
	A[i] += k;
	i += i & -i;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++) {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m + n + 1; i++) {
	    A[i] = 0;
	}
	for(int i = m +1; i < m + n + 1; i++) {
	    add(i, 1, m + n + 1);
	}
	for(int i = 0; i < n; i++) {
	    pos[i + 1] = i + m + 1;
	}
	for(int i = 0; i < m; i++) {
	    int a;
	    cin >> a;
	    if(i > 0) cout << " ";
	    cout << (sum(pos[a]) - 1);
	    add(pos[a], -1, m + n + 1);
	    add(m-i, 1, m + n + 1);
	    pos[a] = m-i;
	}
	cout << endl;
    }
}
