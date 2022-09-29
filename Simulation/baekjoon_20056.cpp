#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <set>

using namespace std;

int world_mass[51][51] = { {0,} };
int world_speed[51][51] = { {0,} };
int world_cnt[51][51][2] = { {{0,}} };
int world_pre_direction[51][51] = { {0,} };

queue<vector<int> >  fire_balls;


map<int, pair<int, int> > moves = { {0,{-1,0}},{1,{-1,1}},{2,{0,1}},{3,{1,1}},{4,{1,0}},{5,{1,-1}},{6,{0,-1}},{7,{-1,-1}} };

int N, M, K;

int ans;

void initialize() {

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) world_mass[r][c] = 0;
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) world_speed[r][c] = 0;
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) world_cnt[r][c][0] = 0;
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) world_cnt[r][c][1] = 0;
	}
}

void visualize() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) cout << world_mass[r][c] << ' ';
		cout << '\n';
	}
	cout << "====\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) cout << world_speed[r][c] << ' ';
		cout << '\n';
	}
	cout << "====\n";

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) cout << world_cnt[r][c][0] << ' ';
		cout << '\n';
	}
	cout << "====\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) cout << world_cnt[r][c][1] << ' ';
		cout << '\n';
	}
	cout << "====\n";
}

void move_fire_balls() {
	
	int size = fire_balls.size();
	while (size-- > 0) {
		vector<int>  top = fire_balls.front();
		fire_balls.pop();
		int r_m = top[0] + top[3] * moves[top[4]].first;
		int c_m = top[1] + top[3] * moves[top[4]].second;
		
		if (r_m <= 0) r_m = ((abs(r_m) / N) + 1) * N + r_m;
		else r_m = (r_m - 1) % N + 1;

		if (c_m <= 0) c_m = ((abs(c_m) / N) + 1) * N + c_m;
		else c_m = (c_m - 1) % N + 1;

		world_mass[r_m][c_m] += top[2];
		world_speed[r_m][c_m] += top[3];
		if(top[4] % 2 == 0)	world_cnt[r_m][c_m][0]++;
		else world_cnt[r_m][c_m][1]++;
		world_pre_direction[r_m][c_m] = top[4];
	}

}

void processing_fire_balls() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (world_mass[r][c] == 0) continue;
			int size = world_cnt[r][c][0] + world_cnt[r][c][1];
			if (size >= 2) {
				if (world_cnt[r][c][0] == 0 || world_cnt[r][c][1] == 0) {
					if (world_mass[r][c] / 5 == 0) continue;
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 2 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 4 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 6 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 0 });
				}
				else{
					if (world_mass[r][c] / 5 == 0) continue;
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 1 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 3 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 5 });
					fire_balls.push({ r,c,world_mass[r][c] / 5, world_speed[r][c] / size, 7 });
				}
			}
			else {
				fire_balls.push({ r,c,world_mass[r][c], world_speed[r][c], world_pre_direction[r][c] });
			}

		}
	}
}

void count() {
	ans = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) ans += world_mass[r][c];
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire_balls.push({ r,c,m,s,d});
	}

	while (K-- > 0) {
		move_fire_balls();
		processing_fire_balls();
		initialize();
		move_fire_balls();
		count();
		
	}
	cout << ans;
}
	