#include<iostream>

using namespace std;

double s[505];
double t[505];

int mmod(int i, int n) {
  return (((i % n) + n) % n);
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> s[i];
    s[i] /= 100;
  }
  for(int i = 0; i < n; ++i) {
    double cur = 0;
    for(int j = 0; j < k; ++j) {
      cur += s[mmod(i-j, n)];
      t[i] += cur / (k-j) / (n - (k - j));
      
    }
  }
  for(int i = 0; i < n; ++i) {
    printf("%.12f\n", t[i]);
  }
}
