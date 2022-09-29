#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
#include <limits.h>
using namespace std;

int world[10][10];
int ans = INT_MAX;
map<int, int> masks = { {1,5},{2,5} ,{3,5} ,{4,5} ,{5,5} };


bool is_masking(int r, int c, int n) {
	int cnt = 0;
	for (int dr = 0; dr < n; dr++) {
		for (int dc = 0; dc < n; dc++) {
			int r_m = r + dr;
			int c_m = c + dc;
			if (r_m < 0 || r_m >= 10 || c_m < 0 || c_m >= 10) continue;
			if (world[r_m][c_m] == 1) cnt++;
		}
	}

	if (cnt == n * n) return true;
	else return false;
}

void masking(int r, int c, int n, int val) {
	for (int dr = 0; dr < n; dr++) {
		for (int dc = 0; dc < n; dc++) {
			int r_m = r + dr;
			int c_m = c + dc;
			world[r_m][c_m] = val;
		}
	}
}


void recursive(int r, int c, int cnt) {

	int val = r * 10 + c;

	while (world[val / 10][val % 10] != 1) {
		if (val >= 99) {
			ans = min(ans, cnt);
			return;
		}
		val++;
	}

	int cur_r = val / 10; int cur_c = val % 10;
	
	if (ans <= cnt) return;

	for (int n = 5; n > 0; n--) {
		if (is_masking(cur_r, cur_c, n) && masks[n] > 0) {
			masking(cur_r, cur_c, n, 0);
			masks[n]--;
			recursive(cur_r, cur_c, cnt + 1);
			masking(cur_r, cur_c, n, 1);
			masks[n]++;
		}
	}
}



int main() {
	
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) cin >> world[r][c];
	}

	recursive(0, 0, 0);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}