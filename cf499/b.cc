#include<iostream>
#include<algorithm>

using namespace std;

int a[105];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
	int b;
	cin >> b;
	++a[b];
    }
    sort(a+1, a+100);
}
