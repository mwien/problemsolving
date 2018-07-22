#include<iostream>

using namespace std;

long long T[257][256];
long long vals[256][2];
long long f[256][256];

long long msqe(long long i, long long j, long long p) {
  long long sum = 0;
  for(int id = i; id <= j; id++) {
    sum += vals[id][1] * (p - vals[id][0]) * (p - vals[id][0]);
  }
  return sum;
}

int main() {
  int d, k;
  cin >> d >> k;
  for(int i = 0; i < d; ++i) {
    cin >> vals[i][0] >> vals[i][1];
  }
  for(long long i = 0; i < d; ++i) {
    for(long long j = i; j < d; ++j) {
      long long d = 0, c = 0;
      for(int l = i; l <= j; ++l) {
	d += vals[l][0] * vals[l][1];
	c += vals[l][1];
      }
      d *= -2;
      long long x = -d / (2*c);
      long long xn = x + 1;
      f[i][j] = min(msqe(i, j, x), msqe(i, j, xn));
    }
  }
  for(int i = 1; i <= d; ++i) {
    T[i][0] = f[0][i-1]; 
  }
  for(int i = 0; i <= d; ++i) {
    for(int j = 1; j < k; ++j) {
      T[i][j] = (1LL << 60);
      for(int l = 0; l < i; ++l) {
	T[i][j] = min(T[i][j], T[l][j-1] + f[l][i-1]);
      }
    }
  }
  for(int i = 1; i <=d; ++i) {
      cout << vals[i][0] << ": ";
      for(int j = 0; j < k; ++j) {
	  cout << T[i][j] << " ";
      }
      cout << endl;
  }
  cout << T[d][k-1] << endl;
}
