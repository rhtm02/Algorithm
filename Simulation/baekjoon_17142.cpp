#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;
int N, M;
int depth = 0;
int world[50][50] = { {0,} };
int checker[50][50] = { {0,} };
int ans = 50*50;
vector<pair<int, int> > moves = { {0,1},{0,-1} ,{1,0} ,{-1,0} };
vector<pair<int, int> > virus_coordinates;
vector<pair<int, int> > combinations;



void visualize() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) cout << checker[r][c] << ' ';
		cout << '\n';
	}
	cout << "====\n";
}


void bfs() {

	queue<pair<int, int> > q;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) checker[r][c] = 0;
	}


	for (int idx = 0; idx < combinations.size(); idx++) {
		q.push(combinations[idx]);
	}
	int time = 1;
	while (!q.empty()) {
		int epoch = q.size();
		queue<pair<int, int> > temp_q;
		while (epoch-- > 0) {
			pair<int, int> top = q.front();
			q.pop();

			if (checker[top.first][top.second] >= 1) continue;
			checker[top.first][top.second] = time;


			for (int m_idx = 0; m_idx < moves.size(); m_idx++) {
				int r_m = top.first + moves[m_idx].first;
				int c_m = top.second + moves[m_idx].second;
				if (r_m < 0 || r_m >= N || c_m < 0 || c_m >= N) continue;
				if (world[r_m][c_m] == 1) continue;
				q.push({ r_m,c_m });
			}
		}


		time++;
		//visualize();
	}
	int val = 0;
	int is_empty = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (world[r][c] == 0 && checker[r][c] == 0) is_empty = 1;
			if (world[r][c] == 2) continue;
			val = max(val, checker[r][c]);
		}
	}
	if(!is_empty) ans = min(ans, val);
}


void recursive(int r, int c, int pre_idx) {
	if (depth == M - 1) {
		combinations[depth].first = r;
		combinations[depth].second = c;

		//cout << combinations[depth].first << '-' << combinations[depth].second << '\n';
		bfs();

		//visualize();
		return;
	}
	combinations[depth].first = r;
	combinations[depth].second = c;

	for (int idx = pre_idx + 1; idx < virus_coordinates.size(); idx++) {
		depth++;
		recursive(virus_coordinates[idx].first, virus_coordinates[idx].second, idx);
		depth--;
	}

	return;
}

int ZERO_CNT = 0;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> world[i][j];
			if (world[i][j] == 2) virus_coordinates.push_back({ i,j });
			else if (world[i][j] == 0) ZERO_CNT++;
		}
	}

	combinations.resize(M);

	if (ZERO_CNT == 0) cout << 0;
	else {
		for (int idx = 0; idx <= virus_coordinates.size() - M; idx++) {
			recursive(virus_coordinates[idx].first, virus_coordinates[idx].second, idx);
		}
		if (ans == 2500) cout << -1;
		else cout << ans - 1;
	}
	
}