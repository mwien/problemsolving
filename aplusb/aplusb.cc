#include<iostream>
#include<vector>

using namespace std;

vector<int> karatsuba(vector<int>::iterator lower, vector<int>::iterator upper) {
    if(upper - lower == 1) {
	vector<int> one = {(*lower) * (*lower)};
	return one;
    } else {
	vector<int> a = karatsuba(lower, lower + (upper - lower) / 2);
	vector<int> b = karatsuba(lower + (upper - lower) / 2, upper);
	int size = (upper-lower) / 2;
	vector<int> last(size);
	int idx = 0;
	for(auto it = lower; it != upper; ++it, ++idx) {
	    last[idx % size] += *it;
	}
	vector<int> c = karatsuba(last.begin(), last.end());
	vector<int> z(upper -lower);
	idx = 0;
	for(auto it = a.begin(); it != a.end(); ++it, ++idx) {
	    z[idx] -= *it;
	}
	idx = 0;
	for(auto it = b.begin(); it != b.end(); ++it, ++idx) {
	    z[idx] -= *it;
	}
	idx = 0;
	for(auto it = c.begin(); it != c.end(); ++it, ++idx) {
	    z[idx] += *it;
	}
	vector<int> res(2 * (upper-lower));
	idx = upper - lower;
	for(auto it = a.begin(); it != a.end(); ++it, ++idx) {
	    res[idx] += *it;
	}
	idx = 0;
	for(auto it = b.begin(); it != b.end(); ++it, ++idx) {
	    res[idx] += *it;
	}
	idx = (upper - lower) / 2;
	for(auto it = z.begin(); it != z.end(); ++it, ++idx) {
	    res[idx] += *it;
	}
	return res;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(131072);
    //Karatsuba works, but is too slow; rest is not done
    for(int i = 0; i < N; ++i) {
    	int ind;
    	cin >> ind;
    	++A[131072 - (ind+65536)];
    }
    vector<int> res = karatsuba(A.begin(), A.end());
    for(int i = 131072; i < 131100; ++i) {
    	cout << res[i] << " ";
    }
    cout << endl;
    long long sum = 0;
    for(int i = 0; i < N; ++i) {
	res[i] -= A[i]*A[i];
	res[i] *= 2;
	res[i] += A[i]*(A[i]-1);
	sum += res[i];
    }
    cout << sum << endl;
    // vector<int> A = {3, 4, 2, 1};
    // vector<int> res = karatsuba(A.begin(), A.end());
    // for(auto it = res.begin(); it != res.end(); ++it) {
    // 	cout << *it << " ";
    // }
    // cout << endl;
}
