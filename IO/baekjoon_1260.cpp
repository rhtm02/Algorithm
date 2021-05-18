#include <iostream>
#include <set>
#include <utility>
#include <queue>
#include <map>
using namespace std;
map<int, bool> check1;
map<int, bool> check2;
void bfs(map<int, set<int>> &graph, int root)
{
	queue<int> q;
	q.push(root);
	int temp;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (check1[temp]) continue;
		check1[temp] = true;
		cout << temp << ' ';
		for (auto it = graph[temp].begin();it != graph[temp].end();it++)
		{
			q.push(*it);
		}
	}
	
}

void dfs(map<int, set<int>>& graph, int root)
{
	if (check2[root]) return;
	check2[root] = true;
	cout << root << ' ';
	for (auto it = graph[root].begin(); it != graph[root].end(); it++)
	{
		dfs(graph,*it);
	}
}

int  main()
{
	int nodeNum = 0, edgeNum = 0, startNum = 0, node1Val = 0, node2Val = 0;
	cin >> nodeNum;	cin >> edgeNum;	cin >> startNum;
	
	map<int, set<int>> graph;
	for (int i = 0; i < edgeNum;i++)
	{	
		cin >> node1Val;
		cin >> node2Val;
		check1[node1Val] = false;
		check1[node2Val] = false;
		check2[node1Val] = false;
		check2[node2Val] = false;
		graph[node1Val].insert(node2Val);
		graph[node2Val].insert(node1Val);
	}

	dfs(graph, startNum);
	cout << endl;
	bfs(graph, startNum);
	

	return 0;
}