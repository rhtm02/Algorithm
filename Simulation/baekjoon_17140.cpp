#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;
int R, C, K;
int world[101][101] = { {0,} };
int R_MAX, C_MAX;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second && a.first < b.first) return true;
	else return false;
}


void visualize() {
	for (int r = 1; r < R_MAX + 1; r++) {
		for (int c = 1; c < C_MAX + 1; c++) cout << world[r][c];
		cout << '\n';
	}
	cout << "=====\n";
}

void r_sort() {
	int temp_world[101][101] = { {0,} };
	int C_TEMP = C_MAX;

	for (int r = 1; r < R_MAX + 1; r++) {
		map<int,int> numbers;
		for (int c = 1; c < C_MAX + 1; c++) {
			if (world[r][c] == 0) continue;
			numbers[world[r][c]]++;
		}
		vector<pair<int, int> > numbers_vec(numbers.begin(), numbers.end());
		sort(numbers_vec.begin(), numbers_vec.end(), compare);

		int temp = 0;
		for (int idx = 0; idx < numbers_vec.size(); idx++) {
			temp_world[r][2 * idx + 1] = numbers_vec[idx].first;
			temp_world[r][2 * idx + 2] = numbers_vec[idx].second;
			temp += 2;
		}
		C_TEMP = max(C_TEMP, temp);
	}
	C_MAX = max(C_TEMP, C_MAX);
	C_MAX = min(C_MAX, 100);
	for (int r = 1; r < R_MAX + 1; r++) {
		for (int c = 1; c < C_MAX + 1; c++) world[r][c] = temp_world[r][c];
	}


	//visualize();

}

void c_sort() {
	int temp_world[101][101] = { {0,} };
	int R_TEMP = R_MAX;

	for (int c = 1; c < C_MAX + 1; c++) {
		map<int, int> numbers;
		for (int r = 1; r < R_MAX + 1; r++) {
			if (world[r][c] == 0) continue;
			numbers[world[r][c]]++;
		}
		vector<pair<int, int> > numbers_vec(numbers.begin(), numbers.end());
		sort(numbers_vec.begin(), numbers_vec.end(), compare);

		int temp = 0;
		for (int idx = 0; idx < numbers_vec.size(); idx++) {
			temp_world[2 * idx + 1][c] = numbers_vec[idx].first;
			temp_world[2 * idx + 2][c] = numbers_vec[idx].second;
			temp += 2;
		}
		R_TEMP = max(R_TEMP, temp);
	}
	R_MAX = max(R_TEMP, R_MAX);
	R_MAX = min(100, R_MAX);

	for (int r = 1; r < R_MAX + 1; r++) {
		for (int c = 1; c < C_MAX + 1; c++) world[r][c] = temp_world[r][c];
	}


	//visualize();

}



int main() {
	cin >> R >> C >> K;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> world[i + 1][j + 1];
	}
	R_MAX = 3; C_MAX = 3;
	//visualize();
	int CNT = 100;
	int ans = 0;
	while (CNT-- > 0) {
		if (world[R][C] == K) break;
		if (C_MAX <= R_MAX) r_sort();
		else c_sort();
		ans++;
	}
	if (world[R][C] != K) cout << -1;
	else cout << ans;
}