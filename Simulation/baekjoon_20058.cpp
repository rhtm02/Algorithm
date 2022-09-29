#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <set>
#include <cmath>

using namespace std;

int N, Q;
int world[2 * 2 * 2 * 2 * 2 * 2][2 * 2 * 2 * 2 * 2 * 2] = { {0,} };
int checker[2 * 2 * 2 * 2 * 2 * 2][2 * 2 * 2 * 2 * 2 * 2] = { {0,} };
int MAX;
vector<pair<int, int>> moves = { {0,1},{0,-1},{1,0},{-1,0} };

void visualize() {
	cout << "=====\n";
	for (int r = 0; r < pow(2, N); r++) {
		for (int c = 0; c < pow(2, N); c++) cout << world[r][c] << ' ';
		cout << '\n';
	}
	cout << "=====\n";
}

void visualize2() {
	cout << "=====\n";
	for (int r = 0; r < pow(2, N); r++) {
		for (int c = 0; c < pow(2, N); c++) cout << checker[r][c] << ' ';
		cout << '\n';
	}
	cout << "=====\n";
}

void rotate(int n) {

	int temp_world[2 * 2 * 2 * 2 * 2 * 2][2 * 2 * 2 * 2 * 2 * 2] = { {0,} };
	int term = pow(2, n);
	int cnt = 0;
	for (int r = 0; r < MAX; r += term) {
		for (int c = 0; c < MAX; c += term) {
			for (int dr = 0; dr < term; dr++) {
				for (int dc = 0; dc < term; dc++) {
					//cout << r + dr << '-' << c + dc << ':' << r + dc << '-' << term - 1 + c - dr << '\n';
					temp_world[r + dc][c + term - 1 - dr] = world[r + dr][c + dc];
				}
			}
		}
	}

	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) world[r][c] = temp_world[r][c];

	}

}

void remove() {

	int temp_world[2 * 2 * 2 * 2 * 2 * 2][2 * 2 * 2 * 2 * 2 * 2] = { {0,} };
	;	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			int cnt = 0;
			for (int m_idx = 0; m_idx < moves.size(); m_idx++) {
				int r_m = r + moves[m_idx].first;
				int c_m = c + moves[m_idx].second;
				if (r_m < 0 || r_m >= MAX || c_m < 0 || c_m >= MAX || world[r_m][c_m] == 0) continue;
				cnt++;
			}
			if (cnt <= 2 && world[r][c] > 0) temp_world[r][c] = world[r][c] - 1;
			else temp_world[r][c] = world[r][c];
		}
	}
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) world[r][c] = temp_world[r][c];
	}
}

vector<int> sizes;

void bfs(int r, int c) {
	queue<pair<int, int> > q;
	q.push({ r,c });

	int val = 0;
	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();
		if (checker[top.first][top.second] != 0) continue;
		checker[top.first][top.second] = val;
		val++;
		for (int m_idx = 0; m_idx < moves.size(); m_idx++) {
			int r_m = top.first + moves[m_idx].first;
			int c_m = top.second + moves[m_idx].second;
			if (r_m < 0 || r_m >= MAX || c_m < 0 || c_m >= MAX || world[r_m][c_m] == 0) continue;
			q.push({ r_m,c_m });
		}
	}
	sizes.push_back(val);
}

int main() {
	cin >> N >> Q;

	MAX = pow(2, N);

	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) cin >> world[r][c];
	}


	for (int t = 0; t < Q; t++) {
		int val = 0;
		cin >> val;
		rotate(val);
		remove();
	}


	int cnt = 0;
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			cnt += world[r][c];
		}
	}
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			if (checker[r][c] != 0 || world[r][c] == 0) continue;
			bfs(r, c);
		}
	}
	if (sizes.size() == 0) cout << cnt << '\n' << 0;
	else {
		sort(sizes.begin(), sizes.end());
		cout << cnt << '\n' << sizes[sizes.size() - 1] - 1;
	}
	
}