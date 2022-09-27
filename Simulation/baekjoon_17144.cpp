#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;

int world[51][51] = { {0,} };
int N, M, T;
vector<pair<int, int> > moves = { {0,1},{0,-1},{1,0},{-1,0} };


void visualize() {
	cout << "====\n";
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) cout << world[r][c] << ' ';
		cout << '\n';
	}
	cout << "====\n";
}

void diffuse() {
	vector<pair<int, int> > coords;
	int diffusion[51][51] = { {0,} };

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (world[r][c] > 0) coords.push_back({ r,c });
		}
	}

	for (int idx = 0; idx < coords.size(); idx++) {

		int cnt = 0;
		int val = world[coords[idx].first][coords[idx].second] / 5;
		for (int m_idx = 0; m_idx < 4; m_idx++) {
			int r_m = coords[idx].first + moves[m_idx].first;
			int c_m = coords[idx].second + moves[m_idx].second;

			if (r_m < 0 || r_m >= N || c_m < 0 || c_m >= M) continue;
			if (world[r_m][c_m] == -1) continue;
			cnt++;
			diffusion[r_m][c_m] += val;
		}
		world[coords[idx].first][coords[idx].second] -= cnt * val;
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) world[r][c] += diffusion[r][c];
	}

	//visualize();
}

void move_ccw(int r, int c) {
	int temp[50][50] = { {0,} };
	for (int r_m = 0; r_m <= r; r_m++) {
		for (int c_m = 0; c_m < M; c_m++) temp[r_m][c_m] = world[r_m][c_m];
	}
	int cur_r = r;
	int cur_c = c + 1;
	int pre_r = r;
	int pre_c = c;
	while (world[cur_r][cur_c] != -1) {
		temp[cur_r][cur_c] = world[pre_r][pre_c];

		pre_r = cur_r;
		pre_c = cur_c;

		if (cur_c < M - 1 && cur_r == r) cur_c++;
		else if (cur_c == M - 1 && cur_r > 0) cur_r--;
		else if (cur_c > 0 && cur_r == 0) cur_c--;
		else if(cur_c == 0 && cur_r < r) cur_r++;
		
	}

	for (int r_m = 0; r_m <= r; r_m++) {
		for (int c_m = 0; c_m < M; c_m++) {
			if (temp[r_m][c_m] == -1) world[r][c_m] = 0;
			else world[r_m][c_m] = temp[r_m][c_m];
		}
	}
	world[r][c] = -1;

	//visualize();
}

void move_cw(int r, int c) {
	int temp[50][50] = { {0,} };

	for (int r_m = r; r_m < N; r_m++) {
		for (int c_m = 0; c_m < M; c_m++) temp[r_m][c_m] = world[r_m][c_m];
	}

	int cur_r = r;
	int cur_c = c + 1;
	int pre_r = r;
	int pre_c = c;
	while (world[cur_r][cur_c] != -1) {
		temp[cur_r][cur_c] = world[pre_r][pre_c];

		pre_r = cur_r;
		pre_c = cur_c;

		if (cur_c < M - 1 && cur_r == r) cur_c++;
		else if (cur_c == M - 1 && cur_r < N - 1) cur_r++;
		else if (cur_c > 0 && cur_r == N - 1) cur_c--;
		else if (cur_c == 0 && cur_r > r) cur_r--;

	}

	for (int r_m = r; r_m < N; r_m++) {
		for (int c_m = 0; c_m < M; c_m++) {
			if (temp[r_m][c_m] == -1) world[r][c_m] = 0;
			else world[r_m][c_m] = temp[r_m][c_m];
		}
	}
	world[r][c] = -1;

	//visualize();
}



void clear_room() {

	vector<pair<int, int> > machine_coords;
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (world[r][c] == -1) machine_coords.push_back({ r,c });
		}
	}
	move_ccw(machine_coords[0].first, machine_coords[0].second);
	move_cw(machine_coords[1].first, machine_coords[1].second);


}

int main() {

	cin >> N >> M >> T;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) cin >> world[r][c];
	}


	while(T-- > 0){
		diffuse();
		clear_room();
	}
	
	int ans = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (world[r][c] == -1) continue;
			ans += world[r][c];
		}
	}
	cout << ans;
	
}