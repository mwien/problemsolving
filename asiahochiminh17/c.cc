//TAGS: ad hoc, tree

#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a;
    cin >> a;
    int sum = a;
    for(int i = 0; i < N-1; ++i) {
	cin >> a;
	if(sum <= 0) {
	    cout << "NO" << endl;
	    return 0;
	}
	sum += a-2;
    }
    if(sum == 0) {
	cout << "YES" << endl;
    } else {
	cout << "NO" << endl;
    }
}
