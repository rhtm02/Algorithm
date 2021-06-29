#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<int> vertex;
map<int,vector<int>> edge;


void dfs(int v)
{
	if (vertex[v] == 1) return;
	vertex[v] = 1;
	for (auto it : edge[v])
	{
		dfs(it);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; int T;
	cin >> N; cin >> T;
	vertex.assign(N + 1, 0);
	for (int i = 0; i < T; i++)
	{
		int v1; int v2;
		cin >> v1; cin >> v2;
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	int ans = 0;

	for (auto it : edge)
	{
		if (vertex[it.first] == 1) continue;
		dfs(it.first);
		ans++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (vertex[i] == 0) ans++;
	}
	cout << ans;
}