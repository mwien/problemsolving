#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int t;
    while(cin >> t) {
	int n;
	cin >> n;
	double run[n];
	double cyc[n];
	for(int i = 0; i < n; i++) {
	    cin >> run[i];
	    cin >> cyc[i];
	}
	double maxdiff = -1;
	double cycdist = -1;
	double rundist = -1;
	for(int i = 0; i < t*1000+1; i++) {
	    double bestofrest = 10000000;
	    int ind = -1;
	    for(int j = 0; j < n-1; j++) {
		double time = (t-(i/1000.0))/cyc[j] + (i/1000.0)/run[j];
		if(time < bestofrest) {
		    bestofrest = time;
		    ind = j;
		}
	    }
	    double ctime = (t-i/1000.0)/cyc[n-1] + (i/1000.0)/run[n-1];
	    if(maxdiff < bestofrest - ctime) {
		maxdiff = bestofrest - ctime;
		cycdist = t-(i/1000.0);
		rundist = i/1000.0;
	    }
	}
	if(maxdiff < 0) {
	    cout << "The cheater cannot win." << endl;
	} else {
	    cout << "The cheater can win by " << round(maxdiff*3600) << " seconds with r = ";
	    printf("%.2f", rundist);
	    cout << "km and k = ";
	    printf("%.2f", cycdist);
	    cout << "km." << endl;
	}
    }

}
