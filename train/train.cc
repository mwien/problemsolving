// https://open.kattis.com/problems/trainsorting
#include<iostream>

using namespace std;

int a[2005];
int Ti[2005];
int Td[2005];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i) {
    Ti[i] = 1;
    Td[i] = 1;
  }
  for(int i = n-1; i >= 0; --i) {
    for(int j = n-1; j > i; --j) {
      if(a[j] < a[i]) {
	Ti[i] = max(Ti[i], Ti[j] + 1);
      }
      if(a[j] > a[i]) {
	Td[i] = max(Td[i], Td[j] + 1);
      }
    }
  }
  int res = 0;
  for(int i = 0; i < n; ++i) {
    res = max(res, Td[i] + Ti[i] - 1);
  }
  cout << res << endl;
}
