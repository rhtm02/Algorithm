#include<iostream>
#include<algorithm>
using namespace std;

#define SIZE 1001

int n, tmp;
int A[SIZE];
int DP1[SIZE];
int DP2[SIZE];
int ans[SIZE];

int main()
{
	cin >> n;


	// 0에서 n-1까지
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		tmp = 0; // 가장 큰 tmp값을 찾기위해 0으로 초기화
		for (int j = 0; j < i; j++)
		{
			// 현재값(A[i])보다 작은 이전값들(A[j])중에서
			// 가장 큰 DP[j]값을 구하고 그 값을 tmp에 저장
			if (A[i] > A[j] && DP1[j] > tmp) tmp = DP1[j];
		}
		DP1[i] = tmp + 1; // 현재 수열 길이 +1 증가
		ans[i] += DP1[i];
	}


	// n-1에서 0까지
	for (int i = n - 1; i >= 0; i--)
	{
		tmp = 0; // 가장 큰 tmp값을 찾기위해 0으로 초기화
		for (int j = n - 1; j > i; j--)
		{
			// 현재값(A[i])보다 작은 이전값들(A[j])중에서
			// 가장 큰 DP[j]값을 구하고 그 값을 tmp에 저장
			if (A[i] > A[j] && DP2[j] > tmp) tmp = DP2[j];
		}
		DP2[i] = tmp + 1; // 현재 수열 길이 +1 증가
		ans[i] += DP2[i];
	}

	sort(ans, ans + n, greater<>()); // 내림차순 정렬

	cout << ans[0] - 1; // 최대값 출력

}