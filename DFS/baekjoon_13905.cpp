#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int N,M,S,E;
map<int, vector<pair<int,int>>> graphs;
map<int, bool> nodes;

int ans2 = 0;


void dfs(int node,int weight ,vector<int> weights) {
	weights.push_back(weight);
	if (node == E) {
		int val = *min_element(weights.begin() + 1, weights.end());
		ans2 = max(val, ans2);
		return;
	}
	nodes[node] = true;

	for (auto it : graphs[node]) {
		if (nodes[it.first] == true) continue;
		nodes[it.first] = true;
		dfs(it.first, it.second, weights);
		nodes[it.first] = false;
	}


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> M; cin >> S; cin >> E;

	
	for (int i = 0; i < M; i++) {
		int h1, h2,w;
		cin >> h1; cin >> h2; cin >> w;
		graphs[h1].push_back(make_pair(h2,w));
		graphs[h2].push_back(make_pair(h1,w));
		nodes[h1] = false;
	}
	/*
	for (int idx = 1; idx <= N;idx++) {
		cout << "node : " << idx << ' ';
		for (auto it2 : graphs[idx]) cout << it2.first << ' ' << it2.second << ' ';
		cout << '\n';
	}
	*/
	vector<int> temp;
	dfs(S, 0, temp);
	/*
	for (auto it : ans) {
		for (auto it2 : it) cout << it2 << ' ';
		cout << '\n';
	}
	*/
	cout << ans2;

}