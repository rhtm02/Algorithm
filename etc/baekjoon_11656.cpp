#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> arr;

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		string temp(iter, s.end());
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	for (auto it : arr) cout << it << '\n';
	return 0;
}