#include<iostream>

using namespace std;

long long inputs[100001] = {0,};
//int SumDP[100001] = {0,};
long long DP[100001];
int main()
{
	int N;
	scanf("%d",&N);

	for (int i = 1; i <= N; i++) scanf("%lld",&inputs[i]);

	DP[1] = inputs[1];
	long long maxVal = inputs[1];
	
	for (int i = 2; i <= N; i++)
	{
		maxVal = max(maxVal + inputs[i], inputs[i]);	
		DP[i] = max(DP[i - 1], maxVal);
	}
	printf("%lld",DP[N]);
}