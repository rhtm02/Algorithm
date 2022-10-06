#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <set>
#include <cmath>

using namespace std;

int N, L;
vector<vector<int> > world(100,vector<int>(100,0));
vector<vector<int> > world_transpose(100, vector<int>(100, 0));


vector<int> line(100,0);
vector<int> checker(100, 0);

bool is_possible() {

	int size = N;
	int cur_pos = 0;
	while (cur_pos < size - 1) {

		if (line[cur_pos] + 1 == line[cur_pos + 1]) {
			if (cur_pos >= L - 1) {
				int check = 0;
				for (int shift = 0; shift < L; shift++) {
					if (line[cur_pos - shift] != line[cur_pos] || checker[cur_pos - shift] == 1) {
						check = 1;
						break;
					}
				}
				if (check == 1) return false;
				else cur_pos++;
			}
			else return false;
		}

		else if (line[cur_pos] - 1 == line[cur_pos + 1]) {
			if (cur_pos < size - L) {
				int check = 0;
				for (int shift = 2; shift <= L; shift++) {

					if (line[cur_pos + shift] != line[cur_pos + 1]) {
						check = 1;
						break;
					}
				}
				if (check == 1) return false;
				else {
					cur_pos += L;
					checker[cur_pos] = 1;
				}
			}
			else return false;
		}

		else if (abs(line[cur_pos] - line[cur_pos + 1]) >= 2) return false;

		else cur_pos++;
	}

	return true;
}

int ans = 0;

int main() {
	cin >> N >> L;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> world[r][c];
			world_transpose[c][r] = world[r][c];
		}
	}
	

	for (int r = 0; r < N; r++) {
		
		copy(world[r].begin(), world[r].end(), line.begin());
		fill(checker.begin(),checker.end(), 0);
		
		if (is_possible()) ans++;

		copy(world_transpose[r].begin(), world_transpose[r].end(), line.begin());
		fill(checker.begin(), checker.end(), 0);

		if (is_possible()) ans++;
		
	}
	cout << ans;
}
