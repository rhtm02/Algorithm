#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N; long long M;
	cin >> N; cin >> M;
	long long K = N - M;
	long long val = 5;
	vector<long long> values_5;
	while (val <= 2000000000)
	{
		if (val > 2000000000) break;
		values_5.push_back(val);
		val *= 5;
	}
	val = 2;
	vector<long long> values_2;
	while (val <= 2000000000)
	{
		if (val > 2000000000) break;
		values_2.push_back(val);
		val *= 2;
	}
	int cntN_5 = 0;
	int cntM_5 = 0;
	int cntK_5 = 0;
	for (auto it : values_5)
	{
		cntN_5 += (N / it);
		cntM_5 += (M / it);
		cntK_5 += (K / it);
	}
	int cntN_2 = 0;
	int cntM_2 = 0;
	int cntK_2 = 0;

	for (auto it : values_2)
	{
		cntN_2 += (N / it);
		cntM_2 += (M / it);
		cntK_2 += (K / it);
	}
	int cnt_5 = cntN_5 - cntM_5 - cntK_5;
	int cnt_2 = cntN_2 - cntM_2 - cntK_2;
	cout << min(cnt_5,cnt_2);
}