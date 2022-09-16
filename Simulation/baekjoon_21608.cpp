#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N;
vector<vector<int>> class_room;
vector<int> order;
map<int, vector<int>> student_table;

vector<pair<int, int>> moves = { {-1,0},{1,0},{0,1},{0,-1} };


bool compare(vector<int> a = {0,0,0,0}, vector<int> b = { 0,0,0,0 }) {
    if (a[0] > b[0]) return true;
    else if (a[0] == b[0] && a[1] > b[1]) return true;
    else if (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]) return true;
    else if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] < b[3]) return true;
    else return false;
        
}


int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;

    for (int r = 0; r < N; r++) {
        vector<int> row;
        row.resize(N);
        class_room.push_back(row);
    }

    for (int i = 0; i < N*N; i++) {
        int s = 0; 
        cin >> s;
        for (int j = 0; j < 4; j++) {
            int f = 0;
            cin >> f;
            student_table[s].push_back(f);
        }
        order.push_back(s);
    }
    

    for (auto student : order) {
        vector<vector<int>> factors;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (class_room[row][col] != 0) continue;
                int num_friends = 0;
                int num_empty = 0;
                for (auto m : moves) {
                    int r = row + m.first;
                    int c = col + m.second;
                    if (r < 0 || r >= N || c < 0 || c >= N) continue;
                    for (auto f : student_table[student]) {
                        if (class_room[r][c] == f) num_friends++;
                        if (class_room[r][c] == 0) num_empty++;
                    }
                }
                factors.push_back({ num_friends,num_empty,row,col });
            }
        }
        
        sort(factors.begin(), factors.end(), compare);
        class_room[factors[0][2]][factors[0][3]] = student;
    }



    int ans = 0;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int num_friends = 0;
            for (auto m : moves) {
                int r = row + m.first;
                int c = col + m.second;
                if (r < 0 || r >= N || c < 0 || c >= N) continue;
                for (auto f : student_table[class_room[row][col]]) {
                    if (class_room[r][c] == f) num_friends++;
                }
            }

            if (num_friends == 0) ans += 0;
            else if (num_friends == 1) ans += 1;
            else if (num_friends == 2) ans += 10;
            else if (num_friends == 3) ans += 100;
            else ans += 1000;
        }
    }

    cout << ans;

}