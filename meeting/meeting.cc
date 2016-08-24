#include<iostream>
#include<string>

using namespace std;
int me[30][30];
int prof[30][30];

void floyd_warshall(int a[][30]) {
    for(int k = 0; k < 26; k++) 
	for(int i = 0; i < 26; i++) 
	    for(int j = 0; j < 26; j++) 
		if(a[i][j] > a[i][k] + a[k][j]) 
		    a[i][j] = a[i][k] + a[k][j];
}

int main()
{
    while(true) {
	int N;
	cin >> N;
	if(N == 0) break;
	for(int i = 0; i < 30; i++) {
	    for(int j = 0; j < 30; j++) {
		if(i == j) {
		    me[i][j] = 0;
		} else {
		    me[i][j] = (1 << 29);
		}
	    }
	}
	for(int i = 0; i < 30; i++) {
	    for(int j = 0; j < 30; j++) {
		if(i == j) {
		    prof[i][j] = 0;
		} else {
		    prof[i][j] = (1 << 29);
		}
	    }
	}
	for(int i = 0; i < N; i++) {
	    string age, dir, S, T;
	    int e;
	    cin >> age >> dir >> S >> T >> e;
	    char s = S[0], t = T[0];
	    if(s == t) continue;
	    if(age[0] == 'Y') {
		me[s-'A'][t-'A'] = e;
		if(dir[0] == 'B')
		    me[t-'A'][s-'A'] = e;
	    } else {
		prof[s-'A'][t-'A'] = e;
		if(dir[0] == 'B')
		    prof[t-'A'][s-'A'] = e;
	    }
	}
	string me_start, prof_start;
	cin >> me_start >> prof_start;
	floyd_warshall(me);
	floyd_warshall(prof);

	int min = (1 << 30);
	for(int i = 0; i < 26; i++) {
	    int dist = me[me_start[0] - 'A'][i] + prof[prof_start[0] - 'A'][i];
	    if(min > dist) min = dist;
	}
	if(min == (1 << 29))
	    cout << "You will never meet." << endl;
	else {
	    cout << min;
	    for(int i = 0; i < 26; i++) {
		if(min == me[me_start[0] - 'A'][i] + prof[prof_start[0] - 'A'][i])
		    cout << " " << ((char) ('A' + i));
	    }
	    cout << endl;
	}
    }
}
