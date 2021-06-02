#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}


int main()
{
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> values;

	for (int i = 0; i < N; i++)
	{
		pair<int, int> temp;
		scanf("%d %d", &temp.first, &temp.second);
		values.push_back(temp);
	}

	sort(values.begin(), values.end(), compare);
	
	for (auto it : values) printf("%d %d \n", it.first, it.second);

}