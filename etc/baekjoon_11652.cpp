#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<long long, int> a, pair<long long, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int N;
	cin >> N;
	map<long long, int> table;
	
	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		table[temp]++;
	}
	vector<pair<long long, int>> vectorTable(table.begin(),table.end());
	sort(vectorTable.begin(), vectorTable.end(), compare);
	cout << vectorTable[0].first;
}