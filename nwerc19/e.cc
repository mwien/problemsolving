#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  vector<int> tt;
  double t1, t2, t3, t4;
  cin >> t1 >> t2 >> t3 >> t4;
  double t;
  cin >> t;
  int it1 = 100*t1 + 0.5, it2 = 100*t2 + 0.5, it3 = 100*t3 + 0.5, it4 = 100*t4 + 0.5;
  tt.push_back(it1);
  tt.push_back(it2);
  tt.push_back(it3);
  tt.push_back(it4);
  sort(tt.begin(), tt.end());
  int it = 100*t + 0.5;
  for(int i = 2100; i >= 0; --i) {
    vector<int> stt;
    for(int j = 0; j < 4; ++j) {
      stt.push_back(tt[j]);
    }
    stt.push_back(i);
    sort(stt.begin(), stt.end());
    int avg = 0;
    for(int j = 1; j <= 3; ++j) {
      avg += stt[j];
    }
    if(avg <= it*3) {
      if(i >= tt[3]) {
	cout << "infinite" << endl;
	return 0;
      } else {
	printf("%.2f\n", (double) i / 100);
	return 0;
      }
    }
  }
  cout << "impossible" << endl;
}
