#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N, K, L;

int world[101][101];
deque<pair<int, int>> snake;
vector<pair<int, char>> commands;
pair<int, int> head;
char heading;

map<char, pair<int, int>> forwarding = { {'u',{-1,0}},{'r',{0,1}},{'d',{1,0}},{'l',{0,-1}} };


void visualize() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int check = 0;
			for (auto it : snake) {
				if (it.first == r && it.second == c) {
					cout << 'X' << ' ';
					check = 1;
				}
			}
			if (check == 0)	cout << world[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << "HEAD : " << head.first << '-' << head.second << ' ' << heading;
	cout << "\n==================\n";
}

bool check_crash() {
	int r_m = head.first + forwarding[heading].first;
	int c_m = head.second + forwarding[heading].second;
	if (r_m <= 0 || r_m > N || c_m <= 0 || c_m > N) return true;

	for (auto it : snake) {
		if (it.first == r_m && it.second == c_m) return true;
	}

	return false;
}

void move() {
	int r_m = head.first + forwarding[heading].first;
	int c_m = head.second + forwarding[heading].second;
	
	snake.push_front({ r_m,c_m });
	head.first = r_m; head.second = c_m;
	if (world[r_m][c_m] == 1) world[r_m][c_m] = 0;
	else snake.pop_back();
	// visualize();

}

void change_direction(char p) {

	if (p == 'D') {
		if (heading == 'r') heading = 'd';
		else if (heading == 'd') heading = 'l';
		else if (heading == 'l') heading = 'u';
		else heading = 'r';
	}
	else {
		if (heading == 'r') heading = 'u';
		else if (heading == 'd') heading = 'r';
		else if (heading == 'l') heading = 'd';
		else heading = 'l';
	}
}


int main() {
	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		world[r][c] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int t; char p;
		cin >> t >> p;
		commands.push_back({ t,p });
	}

	head = { 1,1 };
	heading = 'r';
	snake.push_back({ 1,1 });

	int sec = 0;
	int ans = 0;

	for (auto it : commands) {
		//cout << it.first << ' ' << it.second << '\n';
		int time = it.first;
		char pos = it.second;

		int step = time - sec;

		bool crash = false;

		while (step--) {
			crash = check_crash();
			if (crash) break;
			ans++;
			move();
		}
		if (crash) break;
		change_direction(pos);
		sec = time;
	}
	while (1) {
		ans++;
		if (check_crash()) break;
		move();
	}
	cout << ans;
}