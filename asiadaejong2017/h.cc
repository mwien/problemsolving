#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>

using namespace std;

void iterativefft(const vector<long long> &pol, vector<complex<double>> &fft, int n, bool inv)
{
    //copy pol into fft
    if(!inv) {
        for(int i = 0; i < n; ++i) {
            complex<double> cp (pol[i], 0);
            fft[i] = cp;
        }
    }
    //swap positions accordingly
    for(int i = 0, j = 0; i < n; ++i) {
        if(i < j) swap(fft[i], fft[j]);
        int m = n >> 1;
        while(1 <= m && m <= j) j -= m, m >>= 1;
        j += m;
    }
    for(int m = 1; m <= n; m <<= 1) { //<= or <
        double theta = (inv ? -1 : 1) * 2 * M_PI / m;
        complex<double> wm(cos(theta), sin(theta));
        for(int k = 0; k < n; k += m) {
            complex<double> w = 1;
            for(int j = 0; j < m/2; ++j) {
                complex<double> t = w * fft[k + j + m/2];
                complex<double> u = fft[k + j];
                fft[k + j] = u + t;
                fft[k + j + m/2] = u - t;
                w = w*wm;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; ++i) {
            fft[i] /= complex<double> (n);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    vector<pair<char, char>> mt {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
    int n = 1;
    while(n < N) n <<= 1;
    n *= 2;
    vector<long long> sum (n);
    for(int i = 0; i < 3; ++i) {
	vector<long long> ap (n), bp (n);
	for(int j = 0; j < n; ++j) {
	    if(j < N && mt[i].second == a[j]) ap[j] = 1;
	}
	for(int j = 0; j < n; ++j) {
	    if(j < M && mt[i].first == b[j]) bp[j] = 1;
	}
	vector<complex<double>> ffta (n), fftb (n);
	iterativefft(ap, ffta, n, false);
	iterativefft(bp, fftb, n, false);
	for(int i = 0; i < n; ++i) {
	    ffta[i] *= fftb[i];
	}
	iterativefft(ap, ffta, n, true);
	for(int i = 0; i < n; ++i) {
	    sum[i] += round(ffta[i].real());
	}
    }
    long long mx = 0;
    for(int i = M-1; i < n; ++i) {
	mx = max(mx, sum[i]);
    }
    cout << mx << endl;
}
