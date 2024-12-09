#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string in;
    cin >> in;
    int pos = -1;
    int maxjump = 0;
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};
    for(int i = 0; i < in.size(); ++i) {
	if(find(vowels.begin(), vowels.end(), in[i]) != vowels.end()) {
	    int dist = i - pos;
	    pos = i;
	    if(dist > maxjump) maxjump = dist;
	}
    }
    if(in.size() - pos > maxjump) maxjump = in.size() - pos;
    cout << maxjump << endl;
}
