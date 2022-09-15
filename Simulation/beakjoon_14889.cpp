#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int N;
vector<vector<int>> T;
vector<pair<int, int>> answers;

map<pair<int, int>, int> cost_map;
map<int, vector<int>> graph;


bool compare(pair<int, int> a, pair<int, int> b) {
    return (abs(a.first - a.second) < abs(b.first - b.second));
}



void recursive(pair<int,int> node, int num_member, vector<int> checker) {
    if (checker[node.second] == 1) return;
    if (num_member == (N / 2)) {
        checker[node.second] = 1;
        int A = 0;
        int B = 0;
        for (int idx = 1; idx < checker.size();idx++) {
            if (checker[idx] != 1) checker[idx] = 2;
        }
        
        for (int s = 1; s < N + 1; s++) {
            for (int d = s; d < N + 1; d++) {
                if (checker[s] != checker[d]) continue;
                if (checker[s] == 1) A += cost_map[{s, d}];
                if (checker[s] == 2) B += cost_map[{s, d}];
            }
        }
        answers.push_back({ A,B });

        return;
    }
    checker[node.second] = 1;


    for (auto it : graph[node.second]) {
        pair<int, int> temp = { node.second, it };

        recursive(temp, num_member + 1, checker);
    }
    return;
}


int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;

    vector<int> temp;
    temp.resize(N + 1);
    T.push_back(temp);

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        temp.push_back(0);
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        T.push_back(temp);
    }
    
    //map<pair<int,int>,int> node_check;
    vector<int> node_check;
    node_check.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            graph[i].push_back(j);
            cost_map[{i, j}] = T[i][j] + T[j][i];
            //node_check[{i, j}];
        }
    }

    
    int num_member = 2;
    node_check[1] = 1;
    for(auto it:graph[1]) recursive({1,it},num_member, node_check);

    sort(answers.begin(), answers.end(), compare);

    cout << abs(answers[0].first - answers[0].second);

}