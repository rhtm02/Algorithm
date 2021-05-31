#include <iostream>

using namespace std;

int dp[1001] = {0,};
int values[1001] = {0,};

int main() {
	int N;
	int maxSum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &values[i]);
	
	dp[1] = values[1];
	for (int i = 1; i <= N; i++)
	{
		dp[i] = values[i];
		
		for (int j = 0; j < i; j++)
		{
			if(values[j] < values[i])dp[i] = max(dp[i], dp[j] + values[i]);
		}
		maxSum = max(maxSum, dp[i]);
	}
	cout << maxSum;

}