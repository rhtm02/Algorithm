#include <iostream>
#include <map>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, bool> table;
	for (int i = 1; i < 1001; i++) table[i] = true;
	table[1] = false;
	for (int i = 2; i < 1001; i++)
	{
		int temp = 2*i;
		while (temp <= 1000)
		{
			if (table[temp] == false) { temp += i; continue; }
			table[temp] = false;
			
		}
	}
	int cnt = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input; cin >> input;
		if (table[input]) cnt++;
	}
	cout << cnt;
}