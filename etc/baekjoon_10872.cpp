#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long> DP(13);
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] * i;
	}

	cout << DP[N];
}