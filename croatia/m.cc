#include<iostream>

using namespace std;

bool T[505][5005];
int P[505][5005];
bool C[5005];
int A[5005];

int main()
{
  int L, N;
  cin >> L >> N;
  T[0][0] = true;
  for(int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    A[i] = a;
    for(int j = 0; j <= L; ++j) {
      T[i][j] = T[i-1][j];
      P[i][j] = j;
    }
    for(int j = a; j <= L; ++j) {
      if(T[i-1][j-a]) {
	T[i][j] = T[i-1][j-a];
	P[i][j] = j-a;
      }
    }
  }
  int mx = -1;
  for(int i = 0; i <= L; ++i) {
    if(T[N][i]) mx = i;
  }
  int j = mx;
  
  for(int i = N; i >= 0; --i) {
    if(P[i][j] != j) {
      C[i] = true;
      j = P[i][j];
    }
  }
  int lt = 0, lf = 0;
  for(int i = 1; i <= N; ++i) {
    //cout << "hi " << C[i] << " " << A[i] << endl;
    if(C[i]) {
      cout << lt << " ";
      lt += A[i];
    } else {
      cout << lf << " ";
      lf += A[i];
    }
  }
  cout << endl;
}
