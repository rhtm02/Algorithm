#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	map<char,set<int>> table;
	string s = "abcdefghijklmnopqrstuvwxyz";
	for (auto it : s) table[it];
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		table[str[i]].insert(i);
	}

	for (auto it : s)
	{
		if (table[it].size() == 0) cout << -1 << ' ';
		else cout << *table[it].begin() << ' ';
	}
}