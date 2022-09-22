#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N, M, x, y, K;

int world[20][20];
map<int, pair<int, int>> moves = { {1,{0,1}},{2,{0,-1}},{3,{-1,0}},{4,{1,0}} };

vector<int> commands;

pair<int, int> pos;


int cube[4][4] = { {0,} };

bool rotate_cube(int command) {

	int pos_r_m = pos.first + moves[command].first;
	int pos_c_m = pos.second + moves[command].second;


	if (pos_r_m < 0 || pos_r_m >= N || pos_c_m < 0 || pos_c_m >= M) return false;

	pos.first = pos_r_m;
	pos.second = pos_c_m;
	

	if (command == 1 || command == 2) {
		int row_cube[4] = { 0, };
		for (int c = 0; c < 4; c++) {
			int c_m = (c + moves[command].second + 4) % 4;
			row_cube[c] = cube[1][c_m];
		}
		for (int c = 0; c < 4; c++) cube[1][c] = row_cube[c];
		cube[3][1] = cube[1][3];
	}
	else {
		int col_cube[4] = { 0, };
		for (int r = 0; r < 4; r++) {
			int r_m = (r + moves[command].first + 4) % 4;
			col_cube[r] = cube[r_m][1];
		}
		for (int r = 0; r < 4; r++) cube[r][1] = col_cube[r];
		cube[1][3] = cube[3][1];
	}

	
	if (world[pos_r_m][pos_c_m] == 0) {
		world[pos_r_m][pos_c_m] = cube[1][1];
	}
	else {
		cube[1][1] = world[pos_r_m][pos_c_m];
		world[pos_r_m][pos_c_m] = 0;
	}
	

	return true;
}


void cube_visulaize() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) cout << cube[r][c] << ' ';
		cout << '\n';
	}
	cout << "=============================\n";
}

int main() {
	cin >> N >> M >> x >> y >> K;

	pos = { x,y };

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) cin >> world[r][c];
	}

	for (int i = 0; i < K;i++) {
		int val;
		cin >> val;
		commands.push_back(val);
	}

	for (auto command : commands) {
		bool check = rotate_cube(command);

		if (check) cout << cube[1][3] << '\n';
		else continue;
	}
}