#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N;
int M;
map<int, vector<pair<int, int>>> coordinates;
vector<vector<int>> town_map;

vector<vector<pair<int, int>> > combinations;
vector<int> answers;
void recursive(int idx, vector<pair<int, int>> temp) {
    if (M == 1) {
        temp.push_back(coordinates[2][idx]);
        combinations.push_back(temp);
        return;
    }
    temp.push_back(coordinates[2][idx]);
    for (int i = idx + 1; i < coordinates[2].size(); i++) {
        M--;
        recursive(i,temp);
        M++;
    }

}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        vector<int> temp;
        vector<int> check;
        for (int j = 0; j <= N; j++) {
            if (i == 0 || j == 0) temp.push_back(0);
            else {
                int val;
                cin >> val;

                if (val != 0) {
                    coordinates[val].push_back({ i,j });
                }

                temp.push_back(val);
            }
            check.push_back(0);
        }
        town_map.push_back(temp);
    }
    
    for (int idx = 0; idx < coordinates[2].size(); idx++) {
        vector<pair<int, int>> temp;
        recursive(idx, temp);
    }
    
    
    for (auto it : combinations) {
        int min_cost = 0;
        for (auto home : coordinates[1]) {
            int cost = 5000;
            for (auto dest : it) {
                int dist = abs(home.first - dest.first) + abs(home.second - dest.second);
                cost = min(dist, cost);
            }
            min_cost += cost;
        }
        answers.push_back(min_cost);
    }
    sort(answers.begin(), answers.end());
    cout << answers[0];

}