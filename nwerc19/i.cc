#include<iostream>

using namespace std;

int a[1000005];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int idx = 0;
  while(idx < n-1 && a[idx] <= a[idx+1]) {
    ++idx;
  }
  while(idx < n-1 && a[idx] >= a[idx+1]) {
    ++idx;
  }
  int right = idx;
  while(idx > 0 && a[idx] <= a[idx-1]) {
    --idx;
  }
  int left = idx;
  for(int i = left; i <= (left + right) / 2; ++i) {
    int tmp = a[i];
    a[i] = a[right - (i - left)];
    a[right - (i - left)] = tmp;
  }
  for(int i = 0; i < n - 1; ++i) {
    if(a[i] > a[i+1]) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << left + 1 << " " << right + 1 << endl;
}
