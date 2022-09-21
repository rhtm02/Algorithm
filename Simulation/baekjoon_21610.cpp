#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N, M;

int world[51][51];
int check[51][51] = { {0,} };

map<int, pair<int, int>> moves = { {1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}}, {5,{0,1}},{6,{1,1}},{7,{1,0}}, {8,{1,-1}} };

vector<pair<int, int>> diagonal = { {-1,-1},{1,1},{1, - 1},{-1,1} };

vector<pair<int, int>> cloud_coordinates;

void move_clouds(int d, int s) {
	vector<pair<int, int>> temp_cloud_coordinates;

	for (auto it : cloud_coordinates) {


		int r_m = it.first + s * moves[d].first;
		int c_m = it.second + s * moves[d].second;
		
		if (c_m <= 0) c_m += (50 * N);
		if (r_m <= 0) r_m += (50 * N);

		if (c_m % N == 0) c_m = N;
		else c_m = c_m % N;

		if (r_m % N == 0) r_m = N;
		else r_m = r_m % N;

		
		check[r_m][c_m] = 1;

		world[r_m][c_m]++;
		temp_cloud_coordinates.push_back({ r_m,c_m });
	}

	cloud_coordinates.clear();

	for (auto it : temp_cloud_coordinates) {
		int cnt = 0;
		for (auto m : diagonal) {
			int r_m = it.first + m.first;
			int c_m = it.second + m.second;

			if (r_m <= 0 || r_m > N || c_m <= 0 || c_m > N) continue;

			if (world[r_m][c_m] != 0) cnt++;
		}
		world[it.first][it.second] += cnt;
	}

}

void add_clouds() {

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (check[r][c] == 1) continue;

			if (world[r][c] >= 2) {
				cloud_coordinates.push_back({ r,c });
				world[r][c] -= 2;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) cin >> world[r + 1][c + 1];
	}

	cloud_coordinates.push_back({ N,1 });
	cloud_coordinates.push_back({ N,2 });
	cloud_coordinates.push_back({ N - 1,1 });
	cloud_coordinates.push_back({ N - 1,2 });

	while (M > 0) {

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) check[r + 1][c + 1] = 0;
		}
		
		int s, d;
		cin >> d >> s;
		move_clouds(d, s);

		
		add_clouds();
		
		M--;
	}
	int ans = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) ans += world[r + 1][c + 1];
	}

	cout << ans;

}