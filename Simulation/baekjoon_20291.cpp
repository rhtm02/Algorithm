#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

vector<string> files;
map<string,int> exe_table;
int N;


bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N;

	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		files.push_back(temp);
	}

	for (auto it : files) {
		
		string exe;
		int split_idx =  it.find('.') + 1;

		for (int idx = split_idx; idx < it.size(); idx++) {
			exe.push_back(it[idx]);
		}
		exe_table[exe]++;
	}

	vector<pair<string,int>> exe_list(exe_table.begin(), exe_table.end());

	sort(exe_list.begin(), exe_list.end(),cmp);

	for (auto it : exe_list) {
		cout << it.first << ' ' << it.second << '\n';
	}




	return 0;
}