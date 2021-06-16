#include <iostream>
#include <map>
#include <deque>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inputs;
	cin >> inputs;
	map<string, int> table;
	deque<string> str = { "000","001","010","011" ,"100","101" ,"110","111" };
	for (int i = 0; i < str.size(); i++) table[str[i]] = i;
	table["11"] = 3;
	table["1"] = 1;
	table["10"] = 2;
	
	deque<int> ans;

	deque<char> temp;

	for (int idx = inputs.size() - 1;idx >= 0;idx--)
	{
		temp.push_front(inputs[idx]);
		if ((((inputs.size() - idx) % 3) == 0) || (idx == 0))
		{
			string key(temp.begin(), temp.end());
			ans.push_front(table[key]);
			temp.clear();
		}
	}
	for(auto it:ans) cout << it;
}