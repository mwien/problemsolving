// TAGS: AD HOC
// Problem: http://codeforces.com/gym/101667/attachments (Problem D)

#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long tmp = 0;
    while(true) {
	tmp = 0;
	if(n == 4) {
	    cout << "UNHAPPY\n";
	    return 0;
	}
	if(n == 1) {
	    cout << "HAPPY\n";
	    return 0;
	}
	while(n != 0) {
	    tmp += (n%10) * (n%10);
	    n /= 10;
	}
	n = tmp;
    }
}
