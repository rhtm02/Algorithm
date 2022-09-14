#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int N;
vector<int> T(1001);
vector<int> P(1001);
vector<int> ans(1001);

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t; cin >> p;
		T[i + 1] = t;
		P[i + 1] = p;
	}

	for (int idx = 1; idx <= 5; idx++) {
		if (T[idx] == 1) ans[idx] = ans[idx - 1] + P[idx];
		else ans[idx] = ans[idx - 1];
		for (int j = 1; j < idx; j++) {
			if (T[idx - j] == (j + 1)) {
				ans[idx] = max(ans[idx], ans[idx - j - 1] + P[idx - j]);
			}
		}
	}
	
	
	
	for (int idx = 6; idx < N + 1; idx++) {

		if (T[idx] == 1) ans[idx] = ans[idx - 1] + P[idx];
		else ans[idx] = ans[idx - 1];

		for (int j = 1; j < 5; j++) {
			if (T[idx - j] == (j + 1))	ans[idx] = max(ans[idx], ans[idx - j - 1] + P[idx - j]);
		}

	}
	
	cout << ans[N];
}	