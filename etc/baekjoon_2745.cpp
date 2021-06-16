#include <iostream>
#include <map>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inputs; int B;
	cin >> inputs; cin >> B;
	map<char, int> table;
	string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < str.size(); i++) table[str[i]] = i;
	long long ans = 0;
	int len = inputs.size();
	for (auto it : inputs)
	{
		ans += ((table[it])*pow(B, len - 1));
		len--;
	}
	cout << ans;
}