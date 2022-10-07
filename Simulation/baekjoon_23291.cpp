#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <set>
#include <cmath>

using namespace std;

int N, K;
int world[100][100];
vector<int> fish_ball(100);
int W,H;

vector<pair<int, int> > moves = { {0,1},{1,0}};

void visualize() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) cout << world[r][c] << ' ';
		cout << '\n';
	}
	cout << "FISH BALL\n";
	for (int c = 0; c < N; c++) cout << fish_ball[c] << ' ';
	cout << '\n';

	cout << "====\n";
}

int rotate_ccw90(int center_r, int center_c) {

	int temp_world[100][100] = { {0,} };
	int height = H;
	int shift_c = center_c + H;
	for (int r = 0; r < height; r++) {
		for (int c = 0; c < center_c; c++) {
			if (world[r][c] == 0) continue;
			int dr = r;
			int dc = center_c - c;
			world[center_r + dc][center_c + dr] = world[r][c];
			world[r][c] = 0;
			H = max(H, center_r + dc + 1);
		}
	}
	
	return shift_c;
}

void add_fish() {
	vector<int> temp(fish_ball.begin(), fish_ball.begin() + N);
	sort(temp.begin(), temp.end());

	for (int idx = 0; idx < N; idx++) {
		if (fish_ball[idx] == temp[0]) fish_ball[idx]++;
	}

	
}

void ratate() {
	int shift_idx = 1;
	while (1) {
		shift_idx = rotate_ccw90(0, shift_idx);
		if (shift_idx + H > N) break;
	}
}

void number_check() {
	int temp[100][100] = { {0,} };
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			for (int m_idx = 0; m_idx < 2; m_idx++) {
				int r_m = r + moves[m_idx].first;
				int c_m = c + moves[m_idx].second;
				if (r_m < 0 || r_m >= N || c_m < 0 || c_m >= N || world[r][c] == 0 || world[r_m][c_m] == 0) continue;

				if (world[r][c] > world[r_m][c_m]) {
					int gap = (world[r][c] - world[r_m][c_m]) / 5;
					temp[r][c] -= gap;
					temp[r_m][c_m] += gap;
				}
				else if (world[r][c] < world[r_m][c_m]) {
					int gap = (world[r_m][c_m] - world[r][c]) / 5;
					temp[r][c] += gap;
					temp[r_m][c_m] -= gap;
				}
				else continue;
			}
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) world[r][c] += temp[r][c];
	}

}

void stretch(){
	fish_ball.clear();

	for (int c = 0; c < N; c++) {
		for (int r = 0; r < N; r++) {
			if (world[r][c] == 0) continue;
			fish_ball.push_back(world[r][c]);
		}
	}
	
}

void fold() {
	int size = fish_ball.size();
	
	int center = size / 2;
	
	fill(&world[0][0], &world[0][0] + 100 * 100, 0);
	copy(fish_ball.begin(), fish_ball.end(), &world[0][0]);
	for (int c = 0; c < center; c++) {
		world[1][center + c] = world[0][center - c - 1];
		world[0][center - c - 1] = 0;
	}

	center += center / 2;

	for (int c = 0; c < N - center; c++) {
		for (int r = 1; r <= 2; r++) {
			world[r + 2 - 1][center + c] = world[2 - r][center - c - 1];
			world[2 - r][center - c - 1] = 0;
		}
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> fish_ball[i];
		//world[0][i] = fish_ball[i];
	}

	int cnt = 0;
	while (1) {
		vector<int> temp_fish(fish_ball.begin(), fish_ball.begin() + N);
		sort(temp_fish.begin(), temp_fish.end());
		int min_fish = temp_fish[0];
		int max_fish = temp_fish[N - 1];
		if (abs(min_fish - max_fish) <= K) break;
		fill(&world[0][0], &world[0][0] + 100 * 100, 0);
		H = 1;

		add_fish();
		copy(&fish_ball[0], &fish_ball[0] + N, &world[0][0]);
		ratate();
		number_check();
		stretch();
		fold();
		number_check();
		stretch();
		cnt++;
	}
	
	cout << cnt;
	

}
