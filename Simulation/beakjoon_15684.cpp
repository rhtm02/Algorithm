#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <set>
#include <cmath>

using namespace std;
int N, M, H;

int bridge[31][11] = { {0,} };


int depth = 3;
int ans = 4;

void visualize() {
	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= N; c++) cout << bridge[r][c] << ' ';
		cout << '\n';
	}
	cout << "====\n";
}

bool explore() {

	for (int col = 1; col <= N; col++) {
		int c = col;
		int r = 1;

		int temp_bridge[31][11] = { {0,} };
		/*
		for (int r = 1; r <= H; r++) {
			for (int c = 1; c <= N; c++) temp_bridge[r][c] = bridge[r][c];
		}
		*/
		copy(&bridge[0][0],&bridge[0][0] + 31*11,&temp_bridge[0][0]);

		while (r <= H) {
			//cout << r << '-' << c << '\n';
			// left
			if (temp_bridge[r][c] == 2 && temp_bridge[r][c - 1] == 1) {
				temp_bridge[r][c] = 0;
				temp_bridge[r][c - 1] = 0;
				c--;
			}
			// right
			else if (temp_bridge[r][c] == 1 && temp_bridge[r][c + 1] == 2) {
				temp_bridge[r][c] = 0;
				temp_bridge[r][c + 1] = 0;
				c++;
			}
			else r++;
		}
		//cout << "===========\n";
		if (col != c) { 
			return false; 
		}
	}
	return true;
}

void recursive(int val, int cnt) {
	if (depth == 0) {
		//visualize();
		bool check = explore();
		if (check) { 
			ans = min(ans, cnt); 
		}
		return;
	}

	

	for (int cur_val = val + 1; cur_val <= (N + 1) * H - depth; cur_val++) {
		if (cur_val % N == 0) continue;
		int cur_r = cur_val / N;
		int cur_c = cur_val % N;
		
		if (bridge[cur_r][cur_c] != 0 || bridge[cur_r][cur_c + 1] != 0) continue;
		//cout << cur_r << '-' << cur_c << '\n';
		bridge[cur_r][cur_c] = 1;
		bridge[cur_r][cur_c + 1] = 2;
		depth--;
		recursive(cur_val, cnt + 1);
		bridge[cur_r][cur_c] = 0;
		bridge[cur_r][cur_c + 1] = 0;
		depth++;
	}
}


int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		bridge[r][c] = 1;
		bridge[r][c + 1] = 2;
	}

	/*
	for (depth = 3; depth >= 0; depth--) {
		for (int val = N + 1; val < (N + 1) * H - depth; val++) {
			if (val % N == 0) continue;
			if (bridge[val / N][val % N] == 1 || bridge[val / N][val % N + 1] == 1) continue;
			bridge[val / N][val % N] = 1;
			bridge[val / N][val % N + 1] = 1;
			depth--;
			recursive(val, 0);
			depth++;
			bridge[val / N][val % N] = 0;
			bridge[val / N][val % N + 1] = 0;
		}
	}
	*/
	bool check = explore();
	if (check) cout << 0;

	else {
		for (depth = 1; depth < 4; depth++)
		{
			for (int val = N + 1; val <= (N + 1) * H - depth; val++) {
				if (val % N == 0) continue;
				if (bridge[val / N][val % N] != 0 || bridge[val / N][val % N + 1] != 0) continue;
				bridge[val / N][val % N] = 1;
				bridge[val / N][val % N + 1] = 2;
				depth--;
				recursive(val, 1);
				depth++;
				bridge[val / N][val % N] = 0;
				bridge[val / N][val % N + 1] = 0;
			}
			if(ans != 4) break;
		}
		if (ans == 4) cout << -1;
		else cout << ans;
	}
	
	//explore();

}
