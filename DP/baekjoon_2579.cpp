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
	vector<int> stair(N + 1);
	for (int i = 1; i <= N; i++) cin >> stair[i];
	DP[1] = stair[1];
	DP[2] = stair[2] + stair[1];
	DP[3] = stair[3] + max(stair[1], stair[2]);
	for (int idx = 4; idx <= N; idx++)
	{
		DP[idx] = stair[idx] + max(DP[idx - 3] + stair[idx - 1], DP[idx - 2]);
	}
	cout << DP[N];
}