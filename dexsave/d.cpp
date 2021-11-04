#include<iostream>
#include<map>

using namespace std;

int main()
{
    int d, m;
    cin >> d >> m;
    string s;
    cin >> s;

    map<int, double> prob;

    if(s == "straight") {
	for(int i = 1; i <= 20; ++i) {
	    prob[i] = 1/20.0;
	}
    }
    
    if(s == "advantage") {
	for(int i = 1; i <= 20; ++i) {
	    prob[i] = 2 * 1/20.0 * (i-1)/20.0 + 1/20.0 * 1/20.0;
	}
    }

    if(s == "disadvantage") {
	for(int i = 1; i <= 20; ++i) {
	    prob[i] = 2* 1/20.0 * (20-i)/20.0 + 1/20.0 * 1/20.0;
	}
    }

    double win = prob[20];
    prob[1] = 0;
    prob[20] = 0;

    int k;
    cin >> k;

    for(int i = 0; i < k; ++i) {
	string tk;
	cin >> tk;
	int val = 10;
	if(tk.size() == 3) {
	    val = tk[2] - '0';
	}

	if(tk[0] == '+') {
	    for(int j = 100; j >= -100; --j) {
		double tmp = 0;
		for(int z = j - val; z <= j-1; ++z) {
		    if(prob.find(z) != prob.end()) {
			tmp += prob[z] / val;
		    }
		}
		prob[j] = tmp;
	    }
	}
	if(tk[0] == '-') {
	    for(int j = -100; j <= 100; ++j) {
	        double tmp = 0;
		for(int z = j + val; z >= j+1; --z) {
		    if(prob.find(z) != prob.end()) {
			tmp += prob[z] / val;
		    }
		}
		prob[j] = tmp;
	    }
	}
    }
    for(int j = -100; j <= 100; ++j) {
	if(j + m >= d && prob.find(j) != prob.end()) {
	    win += prob[j];
	}
    }
    printf("%.12f\n", win);
}
