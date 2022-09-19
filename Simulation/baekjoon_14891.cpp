#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int K;
int gears[4][3][3];


vector<int> checker = { 0,0,0,0 };

void spin(int gear_idx, int spin_pos) {
	if (checker[gear_idx] == 1) return;
	if (gear_idx < 0 || gear_idx > 4) return;

	checker[gear_idx] = 1;

	int gear[3][3] = { {0,} };

	int left_checker = 0;
	int right_checker = 0;

	if (gear_idx == 0) {
		if (gears[gear_idx][1][2] != gears[gear_idx + 1][1][0]) right_checker = 1;
	}
	else if (gear_idx == 3) {
		if (gears[gear_idx][1][0] != gears[gear_idx - 1][1][2]) left_checker = 1;
	}
	else {
		if (gears[gear_idx][1][2] != gears[gear_idx + 1][1][0]) right_checker = 1;
		if (gears[gear_idx][1][0] != gears[gear_idx - 1][1][2]) left_checker = 1;
	}

	if (spin_pos == -1) {

		gear[0][0] = gears[gear_idx][0][1];
		gear[0][1] = gears[gear_idx][0][2];
		gear[0][2] = gears[gear_idx][1][2];

		gear[1][0] = gears[gear_idx][0][0];
		gear[1][2] = gears[gear_idx][2][2];

		gear[2][0] = gears[gear_idx][1][0];
		gear[2][1] = gears[gear_idx][2][0];
		gear[2][2] = gears[gear_idx][2][1];
	}
	else {
		
		gear[0][0] = gears[gear_idx][1][0];
		gear[0][1] = gears[gear_idx][0][0];
		gear[0][2] = gears[gear_idx][0][1];

		gear[1][0] = gears[gear_idx][2][0];
		gear[1][2] = gears[gear_idx][0][2];

		gear[2][0] = gears[gear_idx][2][1];
		gear[2][1] = gears[gear_idx][2][2];
		gear[2][2] = gears[gear_idx][1][2];

	}

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			gears[gear_idx][r][c] = gear[r][c];
		}
	}

	if (left_checker) spin(gear_idx - 1, -spin_pos);
	if(right_checker) spin(gear_idx + 1, -spin_pos);
}


int main() {
	
	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		
		gears[i][0][1] = temp[0] - '0';
		gears[i][0][2] = temp[1] - '0';
		gears[i][1][2] = temp[2] - '0';
		gears[i][2][2] = temp[3] - '0';
		gears[i][2][1] = temp[4] - '0';
		gears[i][2][0] = temp[5] - '0';
		gears[i][1][0] = temp[6] - '0';
		gears[i][0][0] = temp[7] - '0';
	}


	cin >> K;

	int gear_idx, spin_pos;
	for (int i = 0; i < K; i++) {
		checker = { 0,0,0,0 };
		cin >> gear_idx >> spin_pos;
		spin(gear_idx-1, spin_pos);
	}
	int ans = 0;
	
	if (gears[0][0][1] == 1) ans += 1;
	if (gears[1][0][1] == 1) ans += 2;
	if (gears[2][0][1] == 1) ans += 4;
	if (gears[3][0][1] == 1) ans += 8;

	cout << ans;
	
}