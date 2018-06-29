#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<string, pair<int,int>> recipe;
vector<vector<pair<int, int>>> g;
unordered_map<string, int> ids;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int B, N;
    cin >> B >> N;

    int id = 0;
    unordered_map<string, vector<recipe>> recipes;
    for (int i = 0; i < N; i++) {
	string name, base, ingr;
	int cost, prestige;

	cin >> name >> base >> ingr >> cost >> prestige;

	if (recipes.find(name) == recipes.end()) {
	    recipes.insert({name, vector<recipe>()});
	}
	recipes[name].push_back({base, {cost, prestige}});

	if (ids.find(name) == ids.end()) {
	    ids.insert({name, id});
	    cout << name << " id " << id << endl;
	    id ++;
	}
    }
    for (int i = 0; i < id; i++) {
	g.push_back(vector<pair<int, int>>());
    }

    for (auto it = recipes.begin(); it != recipes.end(); ++it) {
	int idNew = ids.find(it -> first) -> second;
	cout << it -> first << endl;
	for (int i = 0; i < (it->second).size(); i++) {
	    recipe r = (it -> second)[i];
	    auto idEntry = ids.find(r.first);
	    if (idEntry == ids.end()) {
		g.push_back(vector<pair<int, int>>());
		ids.insert({r.first, id});
		id++;

		idEntry = ids.find(r.first);
	    }
	    g[idEntry->second].push_back({idNew, r.second.second});
	    cout << idNew << " con " << idEntry->second << " " << r.second.second <<endl;
	}	
    }

}
