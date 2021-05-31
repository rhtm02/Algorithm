#include <iostream>

using namespace std;

int dp[1001];
int values[1001] = {0,};

int main() {
	int N;
	int maxLen = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &values[i]);
	for (int i = 0; i < 1001; i++) dp[i] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (values[i] < values[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		maxLen = max(maxLen, dp[i]);
	}
	cout << maxLen;
}