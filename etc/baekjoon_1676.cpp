#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> DP(N + 1);
	for (int i = 1; i <= N; i++)
	{
		if ((i % 5) == 0)
		{
			int temp = i;
			int cnt = 0;
			while (1)
			{
				if ((temp % 5) != 0) break;
				temp /= 5;
				cnt++;
			}
			DP[i] = DP[i - 1] + cnt;
		}
		else
		{
			DP[i] = DP[i - 1];
		}
	}
	cout << DP[N];
}