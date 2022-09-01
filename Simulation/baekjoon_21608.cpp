#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <bitset>
using namespace std;


int N;
vector<vector<int>> matrix;
vector<pair<int, int>> coord;
vector<pair<int, vector<int>>> lst;

vector<pair<int, int>> moves = { {-1,0},{1,0},{0,-1},{0,1} };

bool compare(vector<int> a, vector<int> b) {
	if (a[0] > b[0]) return a > b;
	if (a[0] == b[0] && a[1] >= b[1]) return a > b;
	if (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]) return a > b;
	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] < b[3]) return a > b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int student;
		int f;
		cin >> student;

		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			cin >> f;
			temp.push_back(f);
		}
		lst.push_back(pair<int, vector<int>>(student, temp));
	}
	
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) temp.push_back(0);
		matrix.push_back(temp);
	}

	for (auto it : lst) {
		int student = it.first;

		
		int max_empty = 0; int max_friends = 0;

		vector<vector<int>> temp;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				
				vector<int> temp2;

				int empty = 0;
				int friends = 0;
				
				if (matrix[x][y] != 0) continue;
				
				for (auto m : moves) {
					int m_x = x + m.first;
					int m_y = y + m.second;

					if (m_x < 0 || m_x >= N || m_y < 0 || m_y >= N) continue;
					if (matrix[m_x][m_y] == 0) empty++;

					for (auto f : it.second) {
						if (matrix[m_x][m_y] == f) friends++;
					}

				}
				temp.push_back({ friends, empty, x, y });
			}
		}
		sort(temp.begin(), temp.end(), compare);
		int set_x = temp[0][2]; int set_y = temp[0][3];
		matrix[set_x][set_y] = student;
		coord.push_back(pair<int,int>(set_x, set_y));
	}

	int score = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int idx = N * i + j;
			int cnt = 0;
			for (auto m : moves) {
				int m_x = m.first + coord[idx].first;
				int m_y = m.second + coord[idx].second;
				if (m_x < 0 || m_x >= N || m_y < 0 || m_y >= N) continue;

				for (auto it : lst[idx].second) {
					if (it == matrix[m_x][m_y]) cnt++;
				}
			}

			if (cnt == 0) score += 0;
			else if (cnt == 1) score += 1;
			else if (cnt == 2) score += 10;
			else if (cnt == 3) score += 100;
			else score += 1000;
		}
	}
	
	cout << score;

	return 0;
}