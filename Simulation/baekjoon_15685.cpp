#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;

int world[101][101];
int N;
map<int, pair<int, int> > positions = { {0,{0,1}},{1,{-1,0}},{2,{0,-1}},{3,{1,0}} };
vector<pair<int, int> > rectangle = { {0,1},{1,0} ,{1,1} };
vector<pair<int, int> > dragon;

void visualize() {
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			int check = 0;
			for (int idx = 0; idx < dragon.size(); idx++) {
				if (dragon[idx].first == r && dragon[idx].second == c) check = 1;
			}

			if (check == 1) cout << 'x';
			else cout << '0';
		}

		cout << '\n';
	}
	cout << "-----\n";
}

void draw_dragon() {
	for (int idx = 0; idx < dragon.size(); idx++) world[dragon[idx].first][dragon[idx].second] = 1;
}

void rotate() {

	vector<pair<int,int> > now_generation;
	int anchor = dragon.size();
	for (int idx = anchor - 2; idx >= 0; idx--) {
		int dx = dragon[anchor - 1].second - dragon[idx].second;
		int dy = dragon[anchor - 1].first - dragon[idx].first;

		int rotate_dx, rotate_dy;

		if (dx >= 0 && dy < 0) {
			rotate_dx = abs(dy);
			rotate_dy = abs(dx);
		}
		else if (dx > 0 && dy >= 0) {
			rotate_dx = -abs(dy);
			rotate_dy = abs(dx);
		}
		else if (dx <= 0 && dy > 0) {
			rotate_dx = -abs(dy);
			rotate_dy = -abs(dx);
		}
		else {
			rotate_dx = abs(dy);
			rotate_dy = -abs(dx);
		}

		int rotate_x = dragon[anchor - 1].second - rotate_dx;
		int rotate_y = dragon[anchor - 1].first - rotate_dy;
		dragon.push_back({ rotate_y,rotate_x });
		//cout << dragon[anchor - 1].second << '-' << dragon[anchor - 1].first << ' ';
		//cout << rotate_dx << '-' << rotate_dy << ' ';
		//cout << rotate_x << '-' << rotate_y << '\n';
	}
	//visualize();
}




int main() {

	cin >> N;



	for (int i = 0; i < N; i++) {
		int r, c, p, g;
		cin >> c >> r >> p >> g;
		dragon.push_back({ r,c });
		dragon.push_back({ r + positions[p].first,c + positions[p].second });
		//visualize();
		while (g-- > 0) {
			rotate();
		}
		draw_dragon();
		dragon.clear();
	}

	int ans = 0;
	for (int r = 0; r < 100; r++) {
		for (int c = 0; c < 100; c++) {
			int check = world[r][c];
			for (int rec_idx = 0; rec_idx < 3; rec_idx++) {
				int r_m = rectangle[rec_idx].first + r;
				int c_m = rectangle[rec_idx].second + c;
				check *= world[r_m][c_m];
			}
			if (check == 1) ans++;
		}
	}
	cout << ans;

}