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


	// 0���� n-1����
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		tmp = 0; // ���� ū tmp���� ã������ 0���� �ʱ�ȭ
		for (int j = 0; j < i; j++)
		{
			// ���簪(A[i])���� ���� ��������(A[j])�߿���
			// ���� ū DP[j]���� ���ϰ� �� ���� tmp�� ����
			if (A[i] > A[j] && DP1[j] > tmp) tmp = DP1[j];
		}
		DP1[i] = tmp + 1; // ���� ���� ���� +1 ����
		ans[i] += DP1[i];
	}


	// n-1���� 0����
	for (int i = n - 1; i >= 0; i--)
	{
		tmp = 0; // ���� ū tmp���� ã������ 0���� �ʱ�ȭ
		for (int j = n - 1; j > i; j--)
		{
			// ���簪(A[i])���� ���� ��������(A[j])�߿���
			// ���� ū DP[j]���� ���ϰ� �� ���� tmp�� ����
			if (A[i] > A[j] && DP2[j] > tmp) tmp = DP2[j];
		}
		DP2[i] = tmp + 1; // ���� ���� ���� +1 ����
		ans[i] += DP2[i];
	}

	sort(ans, ans + n, greater<>()); // �������� ����

	cout << ans[0] - 1; // �ִ밪 ���

}