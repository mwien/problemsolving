#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

string mv(string &s, int id, int ur, int rc) {
  string out = s;
  if(rc) {
    id *= 4;
    if(ur) {
      for(int i = 0; i < 4; ++i) {
	out[id + (i+1) % 4] = s[id + i];
      }
    } else {
      for(int i = 0; i < 4; ++i) {
	out[id + i] = s[id + (i+1) % 4];
      }
    }
  } else {
    if(ur) {
      for(int i = 0; i < 4; ++i) {
	out[id + ((i+1) % 4) * 4] = s[id + 4*i];
      }
    } else {
      for(int i = 0; i < 4; ++i) {
	out[id + 4*i] = s[id + ((i+1) % 4) * 4];
      }
    }
  }
  return out;
}

int main() {
  string in, s = "";
  for(int i = 0; i < 4; ++i) {
    cin >> in;
    s += in;
  }
  unordered_map<string, char> dist;
  queue<string> q;
  q.push(s);
  dist.insert({s, 0});
  while(!q.empty()) {
    string u = q.front(); q.pop();
    if(dist[u] == 6) break;
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 2; ++j) {
	for(int k = 0; k < 2; ++k) {
	  string v = mv(u, i, j, k);
	  if(dist.find(v) == dist.end()) {
	    dist.insert({v, dist[u]+1});
	    q.push(v);
	  }
	}
      }
    }
  }
  int md = 13;
  s = "RRRRGGGGBBBBYYYY";
  while(!q.empty()) q.pop();
  unordered_map<string, char> rdist;
  q.push(s);
  rdist.insert({s, 0});
  while(!q.empty()) {
    string u = q.front(); q.pop();
    if(rdist[u] == 7) break;
    if(dist.find(u) != dist.end()) {
      md = min(md, rdist[u] + dist[u]);
      if(rdist[u] == 6) continue;
    }
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 2; ++j) {
	for(int k = 0; k < 2; ++k) {
	  string v = mv(u, i, j, k);
	  if(rdist.find(v) == rdist.end()) {
	    rdist.insert({v, rdist[u]+1});
	    q.push(v);
	  }
	}
      }
    }
  }
  cout << md << endl;
}
