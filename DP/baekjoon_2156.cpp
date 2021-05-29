#include <iostream>
using namespace std;
long long val[10001] = {0,};
long long dp[10001] = { 0, };

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> val[i];
	
	dp[1] = val[1];
	dp[2] = val[1] + val[2];

	for (int idx = 3; idx <= N; idx++)
	{	
		dp[idx] = max(dp[idx - 1], dp[idx - 2] + val[idx]);
		dp[idx] = max(dp[idx - 3] + val[idx - 1] + val[idx], dp[idx]);
	}
	cout << dp[N];
	
}