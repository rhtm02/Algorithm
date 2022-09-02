#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

vector<vector<int>> matrix;
map<int, pair<int, int>> table;

vector<pair<int, int>> vertical_moves = { {0,0}, {1,0},{2,0},{3,0},{4,0} };
vector<pair<int, int>> diagonal_moves1 = { {0,0}, {1,1},{2,2}, {3,3},{4,4} };
vector<pair<int, int>> diagonal_moves2 = { {0,4}, { 1,3 },{2,2}, { 3,1}, {4,0} };
vector<pair<int, int>> horizon_moves = { {0,0}, {0,1},{0,2},{0,3},{0,4} };

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		vector<int> temp;
		int val;
		for (int j = 0; j < 5; j++) {
			cin >> val;
			temp.push_back(val);
			table[val] = { i,j };
		}
		matrix.push_back(temp);
	}

	int ans = 0;
	for (int i = 0; i < 25; i++) {
			int val = 0;
			cin >> val;
			ans++;
			int bingo = 0;

			matrix[table[val].first][table[val].second] = 0;


			int diag_cnt1 = 0;
			for (auto coord : diagonal_moves1) {
				int x = coord.first;
				int y = coord.second;
				if (matrix[x][y] == 0) diag_cnt1++;
			}
			if (diag_cnt1 == 5) bingo++;

			int diag_cnt2 = 0;
			for (auto coord : diagonal_moves2) {
				int x = coord.first;
				int y = coord.second;
				if (matrix[x][y] == 0) diag_cnt2++;
			}
			if (diag_cnt2 == 5) bingo++;


			for (int r = 0; r < 5; r++)
			{
				int h_cnt = 0;
				for (auto coord : horizon_moves) {
					int x = coord.first + r;
					int y = coord.second;
					if (matrix[x][y] == 0) h_cnt++;
				}
				if (h_cnt == 5) bingo++;
				if (bingo == 3) break;
			}
			if (bingo == 3) break;
			
			for (int c = 0; c < 5; c++)
			{
				int v_cnt = 0;
				for (auto coord : vertical_moves) {
					int x = coord.first;
					int y = coord.second + c;
					if (matrix[x][y] == 0) v_cnt++;
				}
				
				if (v_cnt == 5) bingo++;
				if (bingo == 3) break;
			}
			if (bingo == 3) break;



	}
	cout << ans;


	return 0;
}