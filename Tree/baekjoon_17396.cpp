#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int,pair<int, int>> PAIR;

int N, M;
vector<int> nodes;

vector<int> parents;

vector<PAIR> graph;

map<int,vector<pair<int,int>>> tree;

vector<int> nodes_path;


int ans = -1;

bool compare(PAIR a, PAIR b) {
	return a.second.second < b.second.second;
}


int find(int node) {
	if (parents[node] == node) return node;

	return find(parents[node]);
}


void union_set(int a, int b) {
	int node1 = find(a);
	int node2 = find(b);
	if (node1 > node2) parents[node2] = node1;
	else parents[node1] = node2;
}


void kruskal() {

	sort(graph.begin(), graph.end(),compare);

	for (auto it : graph) {
		if ((nodes[it.first] == 1) || (nodes[it.second.first] == 1)) continue;

		if (find(it.first) != find(it.second.first)) {
			union_set(it.first, it.second.first);
			tree[it.first].push_back({ it.second.first,it.second.second });
			tree[it.second.first].push_back({ it.first,it.second.second });
		}
	}

	for (auto it : tree) {
		cout << it.first << " : ";
		for (auto it2 : it.second) cout << it2.first << ' ' << it2.second;
		cout << '\n';
	}

}

struct cmp {
	bool operator()(pair<int,int> a,pair<int,int> b) {
		return a.second < b.second;
	}
};


void path_find() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;

	pq.push({ 0,0 });
	
	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		int node = top.first;
		int weight = top.second;

	}

	
}




int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		nodes.push_back(c);
		nodes_path.push_back(c);
		parents.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int f, t,w;
		cin >> f >> t >> w;
		graph.push_back({f, { t,w } });
		graph.push_back({t, { f,w } });
	}

	kruskal();



}