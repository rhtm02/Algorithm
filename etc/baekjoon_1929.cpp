#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int N1; int N2;
	cin >> N1; cin >> N2;
	vector<int> table(1000001);
	
	table[1] = true;
	for (int i = 2; i <= (int)sqrt(N2); i++)
	{
		int temp = i*i;
		if (table[i] == true) continue;

		while (temp <= N2)
		{
			table[temp] = true;
			temp += i;
		}
	}
	for (int i = N1; i <= N2; i++)
	{
		if (!table[i]) cout << i << '\n';
	}
}