#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool compare(pair<int, int> f, pair<int, int> s, vector<int> &order, vector<bool> &rev) {
    if(f.first != s.first) return order[f.first] < order[s.first];
    else {
    if(!rev[f.first]) return f.second < s.second;
    else return f.second > s.second;
    }
}

int moves(vector<pair<int, int>> &cards, vector<int> &order, vector<bool> &rev) {
    vector<int> p (cards.size());
    vector<int> m (cards.size() + 1);
    int l = 0;
    for(int i = 0; i < cards.size(); ++i) {
	int lo = 1;
	int hi = l;
	while(lo <= hi) {
	    int mid = (int) (lo + hi) / 2.0 + 0.6;
	    if(compare(cards[m[mid]], cards[i], order, rev)) {
		lo = mid + 1;
	    } else {
		hi = mid - 1;
	    }
	}
	m[lo] = i;
	l = max(lo, l);
    }
    return cards.size() - l;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> cards;
    for(int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    int rank;
    int suit;
    if(a[0] <= '9') rank = a[0] - '2';
    if(a[0] == 'T') rank = 8;
    if(a[0] == 'J') rank = 9;
    if(a[0] == 'Q') rank = 10;
    if(a[0] == 'K') rank = 11;
    if(a[0] == 'A') rank = 12;
    if(a[1] == 's') suit = 0;
    if(a[1] == 'h') suit = 1;
    if(a[1] == 'd') suit = 2;
    if(a[1] == 'c') suit = 3;
    cards.push_back({suit, rank});
    }
    vector<int> order = {0, 1, 2, 3};
    int minimum = n;
    do {
	for(int brev = 0; brev < (1 << 4); ++brev) {
	    vector<bool> rev;
	    for(int mask = 8; mask > 0; mask /= 2) {
		if((brev & mask) != 0) rev.push_back(true);
		else rev.push_back(false);
	    }
	    minimum = min(minimum, moves(cards, order, rev));
	}
    } while(next_permutation(order.begin(), order.end()));
    cout << minimum << endl;
}

