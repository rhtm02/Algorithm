#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	if (get<1>(a) == get<1>(b))
	{
		if (get<2>(a) == get<2>(b))
		{
			if (get<3>(a) == get<3>(b)) return get<0>(a) < get<0>(b);
			return get<3>(a) > get<3>(b);
		}
		return get<2>(a) < get<2>(b);
	}
	return get<1>(a) > get<1>(b);
}


int main()
{
	int N;
	cin >> N;
	vector<tuple<string,int,int,int>> values;
	

	for (int i = 0; i < N; i++)
	{
		tuple<string, int, int, int> temp;
		
		cin >> get<0>(temp); cin >> get<1>(temp); cin >> get<2>(temp); cin >> get<3>(temp);
		values.push_back(temp);
	}

	sort(values.begin(), values.end(), compare);
	for (auto it : values) cout << get<0>(it) << '\n';
}