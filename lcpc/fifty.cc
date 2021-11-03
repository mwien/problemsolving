#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
	string s;
	cin >> s;
	for(int j = 0; j < s.size(); ++j) {
	    if(s[j] < 'a') {
		s[j] = 'a' + (s[j] - 'A');
	    }
	}
	int m = s.size();
	for(int j = 0; j < m-3; ++j) {
	    if(s[j] == 'p' && s[j+1] == 'i' && s[j+2] == 'n' && s[j+3] == 'k') {
		++cnt;
		break;
	    }
	    if(s[j] == 'r' && s[j+1] == 'o' && s[j+2] == 's' && s[j+3] == 'e') {
		++cnt;
		break;
	    }
	}
    }
    if(cnt == 0) {
	cout << "I must watch Star Wars with my daughter" << endl;
    } else {
	cout << cnt << endl;
    }
}
