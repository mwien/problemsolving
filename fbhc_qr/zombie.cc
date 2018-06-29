#include<iostream>
#include<string>
#include<regex>
#include<iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int tc = 0; tc < T; ++tc) {
	int H, S;
	cin >> H;
	cin >> S;
	double max = 0;
	for(int i = 0; i < S; ++i) {
	    string spell;
	    cin >> spell;
	    int X = -1, Y = -1, Z = -1;
	    string pattern ("[0-9]+[d][0-9]+");
	    regex r(pattern);
	    if(regex_match(spell, r)) {
		for(int i = 0; i < spell.size(); ++i) {
		    if(spell[i] == 'd') {
			X = stoi(spell.substr(0, i));
			Y = stoi(spell.substr(i+1));
			Z = 0;
			break;
		    }
		}
	    } else {
		int fs = -1, ss = -1;
		for(int i = 0; i < spell.size(); ++i) {
		    if(spell[i] == 'd') fs = i;
		    if(spell[i] == '+' || spell[i] == '-') ss = i;
		}
		X = stoi(spell.substr(0, fs));
		Y = stoi(spell.substr(fs+1, ss - fs - 1));
		Z = stoi(spell.substr(ss));
	    }
	    vector<vector<double>> prob(X+1, vector<double> (X*Y + 1));
	    prob[0][0] = 1;
	    for(int i = 1; i <= X; ++i) {
		for(int j = 1; j <= Y; ++j) {
		    for(int k = 0; k <= X*Y; ++k) {
			if(k + j > X*Y) continue;
			prob[i][k+j] += prob[i-1][k] / Y;
		    }
		}
	    }
	    double sum = 0;
	    for(int j = 0; j <= X*Y; ++j) {
		if(j + Z >= H) {
		    sum += prob[X][j];
		}
	    }
	    if(sum > max) max = sum;
	}
	cout << "Case #" << tc+1 << ": "<< fixed << setprecision(6) << max << endl;
    }
}
