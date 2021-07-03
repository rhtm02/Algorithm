#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<pair<int, int>, int> table;
int N;
int num = 0;
vector<int> answers;

void bfs(pair<int, int> v)
{
	queue<pair<int, int>> q;
	q.push(v);
	int ans = 0;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		if (table[temp] == 1) continue;
		table[temp] = 1;
		ans++;
		if (temp.first == 0)
		{
			if (temp.second == 0)
			{
				q.push(make_pair(temp.first, temp.second + 1));
				q.push(make_pair(temp.first + 1, temp.second));
				continue;
			}
			else if (temp.second == N - 1)
			{
				q.push(make_pair(temp.first, temp.second - 1));
				q.push(make_pair(temp.first + 1, temp.second));
				continue;
			}
			q.push(make_pair(temp.first + 1, temp.second));
			q.push(make_pair(temp.first, temp.second + 1));
			q.push(make_pair(temp.first, temp.second - 1));
		}
		else if (temp.first == N - 1)
		{
			if (temp.second == 0)
			{
				q.push(make_pair(temp.first - 1, temp.second));
				q.push(make_pair(temp.first, temp.second + 1));
				continue;
			}
			else if (temp.second == N - 1)
			{
				q.push(make_pair(temp.first, temp.second - 1));
				q.push(make_pair(temp.first - 1, temp.second));
				continue;
			}
			q.push(make_pair(temp.first, temp.second + 1));
			q.push(make_pair(temp.first, temp.second - 1));
			q.push(make_pair(temp.first - 1, temp.second));
		}
		else
		{
			if (temp.second == 0)
			{
				q.push(make_pair(temp.first, temp.second + 1));
				q.push(make_pair(temp.first - 1, temp.second));
				q.push(make_pair(temp.first + 1, temp.second));
				continue;
			}
			else if (temp.second == N - 1)
			{
				q.push(make_pair(temp.first, temp.second - 1));
				q.push(make_pair(temp.first + 1, temp.second));
				q.push(make_pair(temp.first - 1, temp.second));
				continue;
			}
			q.push(make_pair(temp.first - 1, temp.second));
			q.push(make_pair(temp.first, temp.second - 1));
			q.push(make_pair(temp.first, temp.second + 1));
			q.push(make_pair(temp.first + 1, temp.second));
		}
	}
	answers.push_back(ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	string str;
	pair<int, int> temp;
	for (int i = 0; i < N; i++)
	{
		temp.first = i;
		cin >> str;
		for (int j =  0;j < str.size();j++)
		{
			temp.second = j;
			if (str[j] == '0') table[temp] = 1;
			else if (str[j] == '1') table[temp] = 0;
		}
	}
	for (auto it : table)
	{
		if (it.second == 1) continue;
		bfs(it.first);
		num++;
	}
	cout << num << '\n';
	sort(answers.begin(), answers.end());
	for (auto it : answers) cout << it << '\n';
}