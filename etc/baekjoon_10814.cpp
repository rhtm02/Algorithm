#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
	if (a.second.first == b.second.first) return a.first < b.first;

	return a.second.first < b.second.first;
}


int main()
{
	int N;
	scanf("%d", &N);
	vector<pair<int,pair<int, string>>> values;

	for (int i = 0; i < N; i++)
	{
		pair<int,pair<int, string>> temp;
		temp.first = i;
		cin >> temp.second.first; cin >> temp.second.second;
		values.push_back(temp);
	}

	sort(values.begin(), values.end(), compare);
	for (auto it : values) cout << it.second.first << ' ' << it.second.second << '\n';

}