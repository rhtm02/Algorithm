#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N, K;

vector<vector<int>> belt;
vector<int> robot_position;




void rotate() {
	vector<vector<int>> temp_belt;
	vector<int> temp_robot;
	
	temp_robot.resize(N);

	for (auto it : belt) {
		vector<int> temp;
		for (int it2 : it) temp.push_back(0);
		temp_belt.push_back(temp);
	}

	for (int idx = 0; idx < N; idx++) {
		if (idx == 0 || idx == N - 1) temp_robot[idx] = 0;
		else temp_robot[idx] = robot_position[idx - 1];
	}

	for (int row = 0; row < 2; row++) {
		if (row == 0) {
			for (int col = 0; col < N; col++) {
				if (col == 0) temp_belt[0][col] = belt[1][col];
				else {
					temp_belt[0][col] = belt[0][col - 1];
				}
			}
		}

		else {
			for (int col = 0; col < N; col++) {
				if (col == (N - 1)) temp_belt[1][col] = belt[0][col];
				else {
					temp_belt[1][col] = belt[1][col + 1];
				}
			}
		}
	}

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < N; c++) {
			belt[r][c] = temp_belt[r][c];
		}
	}

	for (int idx = 0; idx < N; idx++) {
		robot_position[idx] = temp_robot[idx];
	}

}

void move_robots() {

	for (int idx = N - 1; idx > 0; idx--) {
		if (belt[0][idx] >= 1 && robot_position[idx] == 0 && robot_position[idx - 1] == 1) {
			robot_position[idx] = 1;
			robot_position[idx - 1] = 0;
			belt[0][idx]--;

			if (idx == N - 1) robot_position[idx] = 0;
		}
	}
}


void upload() {
	if (belt[0][0] >= 1) {
		robot_position[0] = 1;
		belt[0][0]--;
	}
}


int main() {
	cin >> N >> K;

	vector<int> temp;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		temp.push_back(val);
	}
	belt.push_back(temp);
	temp.clear();
	temp.resize(N);
	for (int i = N - 1; i >= 0; i--) {
		cin >> temp[i];
	}
	belt.push_back(temp);
	robot_position.resize(N);
	
	int zero_cnt = 0;




	int ans = 0;
	

	while (zero_cnt < K) {

		zero_cnt = 0;
		ans++;
		rotate();

		move_robots();

		upload();


		zero_cnt = 0;
		for (auto it : belt) {
			for (auto it2 : it) {
				if (it2 == 0) zero_cnt++;
			}
		}
	}
	
	cout << ans;

}