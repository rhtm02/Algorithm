#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

vector<string> mines;
vector<string> inputs;
int N;
int M = 10;

vector<pair<int, int>> check = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
vector<pair<int, int>> mine_coord;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N;

	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		mines.push_back(temp);
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (mines[y][x] == '*') mine_coord.push_back({ y,x });
		}
	}


	for (int i = 0; i < N; i++) {
		cin >> temp;
		inputs.push_back(temp);
	}

	int mine_act = 0;

	vector<string> ans;

	for (int y = 0; y < N; y++) {
		string temp;
		for (int x = 0; x < N; x++) {

			if (inputs[y][x] == 'x') {

				int cnt = 0;
				
				if (mines[y][x] == '*') mine_act = 1;

				for (auto m : check) {
					int m_y = y + m.first;
					int m_x = x + m.second;

					if (m_x < 0 || m_x >= N || m_y < 0 || m_y >= N) continue;
					
					if (mines[m_y][m_x] == '*') cnt++;
				}
				temp.push_back('0' + cnt);
			}
			else {
				temp.push_back('.');
			}
		}
		
		ans.push_back(temp);
	}

	if (mine_act) {
		for (auto coord : mine_coord) {
			ans[coord.first][coord.second] = '*';
		}
	}

	for (auto it : ans) {
		for (auto it2 : it) cout << it2;
		cout << '\n';
	}


	return 0;
}