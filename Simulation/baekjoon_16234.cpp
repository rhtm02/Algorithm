#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N, L, R;

vector<vector<int>> world;

vector<pair<int, int>> moves = { {1,0},{-1,0} ,{0,-1} ,{0,1} };
map<int, int> parents_coordinate;


int find(pair<int, int> node) {
    int node_ = node.first * N + node.second;
    if (parents_coordinate[node_] == node_) return parents_coordinate[node_];
    
    

    return parents_coordinate[node_] = find({ parents_coordinate[node_] / N, parents_coordinate[node_] % N });
}

void union_find(pair<int, int> node1, pair<int, int> node2) {
    int node1_ = node1.first * N + node1.second;
    int node2_ = node2.first * N + node2.second;

    int node1_p = find(node1);
    int node2_p = find(node2);

    if (node1_p == node2_p) return;

    parents_coordinate[node2_p] = node1_p;

}


int main() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
            parents_coordinate[N * i + j] = N * i + j;
        }
        world.push_back(temp);
    }

    int ans = 0;

    while (true) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                for (auto m : moves) {
                    int r_m = r + m.first;
                    int c_m = c + m.second;

                    if (r_m < 0 || r_m >= N || c_m < 0 || c_m >= N) continue;
                    int gap = abs(world[r][c] - world[r_m][c_m]);
                    if (L <= gap && gap <= R) {
                        union_find({ r,c }, { r_m,c_m });
                    }
                }
            }
        }

        map<int, vector<pair<int, int>>> coords;
        int check = 1;
        for (auto it : parents_coordinate) {
            if (it.first != it.second) check *= 0;
            coords[find({ it.second / N,it.second % N })].push_back({ it.first / N,it.first % N });
        }


        if (check == 1) break;

        for (auto it : coords) {
            int val = 0;
            for (auto it2 : it.second) val += world[it2.first][it2.second];
            for (auto it2 : it.second) world[it2.first][it2.second] = (val / (int)it.second.size());

        }


        parents_coordinate.clear();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) parents_coordinate[N * r + c] = N * r + c;
        }
        ans++;
    }
    cout << ans;
}