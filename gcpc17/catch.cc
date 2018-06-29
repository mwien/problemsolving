#include<iostream>
#include<string>

using namespace std;

string id[10005];


int main()
{
    int n;
    cin >> n;
    long long ep = 0, cnt = 0;
    double mo = 0;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	if(id[a] == "") ++cnt;
	cin >> id[a];
	int k;
	double c;
	cin >> k >> c;
	ep += k;
	mo += c;
    }
    cout << cnt << " " << ep << " " << mo / n << endl;
    for(int i = 0; i < 10004; ++i) {
	if(id[i] != "") {
	    cout << i << " " << id[i] << endl;
	}
    }
}
