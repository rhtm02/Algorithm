#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int N;
vector<int> test_taker;
int B, C;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		test_taker.push_back(temp);
	}
	cin >> B; cin >> C;
	long long ans = N;

	for (auto it : test_taker) {
		if (it <= B) continue;
		int q = (it - B) / C;
		ans += q;
		if (((it - B) % C) != 0) ans++;
	}
	
	cout << ans;
}