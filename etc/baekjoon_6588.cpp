#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table(1000001);
	
	table[1] = true;
	for (int i = 2; i <= (int)sqrt(1000000); i++)
	{
		int temp = i*i;
		if (table[i] == true) continue;

		while (temp <= 1000000)
		{
			table[temp] = true;
			temp += i;
		}
	}
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		bool check = false;
		for (int i = 1; i <= 500000; i++)
		{
			int idx = 2 * i + 1;
			if ((table[idx] == false) && (table[N - idx] == false))
			{
				cout << N << " = " << idx << " + " << N - idx << '\n';
				check = true;
				break;
			}
		}
		if(!check) cout << "Goldbach's conjecture is wrong.\n";
	}
}