#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <chrono>
#include<set>

using namespace std;

vector<vector<int> > world(11,vector<int>(11,5));
vector<vector<int> > add_world(11,vector<int>(11,0));
deque<int> alive_trees[11][11];
vector<vector<int> > dead_trees;
vector<pair<int,int> > moves = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool compare(int a, int b){
    if(a < b) return true;
    else return false;
}

int N,M,K;

void visualize(){

    for(int r = 1;r <= N;r++){
        for(int c = 1;c <= N;c++) cout << world[r][c] << ' ';
        cout << '\n';
    }

    cout << "=====\n";
}

void spring(){
   for(int r = 1;r <= N;r++){
       for(int c = 1;c <= N;c++){
           int size = alive_trees[r][c].size();
           if(size == 0) continue;
           sort(alive_trees[r][c].begin(),alive_trees[r][c].end());
           while(size-- > 0){
               int year = alive_trees[r][c].front();
               alive_trees[r][c].pop_front();
               if(year > world[r][c]) {
                   dead_trees.push_back({r, c, year});
                   continue;
               }
               world[r][c] -= year;
               alive_trees[r][c].push_back(year+1);
           }
       }
   }
}

void summer(){
    for(int idx = 0;idx < dead_trees.size();idx++){
        world[dead_trees[idx][0]][dead_trees[idx][1]] += (int)(dead_trees[idx][2] / 2);
    }
    dead_trees.clear();
}

void fall() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int size = alive_trees[r][c].size();
            if (size == 0) continue;
            for(int idx = 0;idx < size;idx++){
                if(alive_trees[r][c][idx] % 5 == 0){
                    for(int m_idx = 0;m_idx < 8;m_idx++){
                        int r_m = r + moves[m_idx].first;
                        int c_m = c + moves[m_idx].second;
                        if(r_m < 1 || r_m > N || c_m <1 || c_m > N) continue;
                        alive_trees[r_m][c_m].push_front(1);
                    }
                }
            }
        }
    }

}
void winter(){
    for(int r = 1;r <= N;r++){
        for(int c = 1;c <=N;c++) world[r][c] += add_world[r][c];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> K;

    for(int r = 1;r <= N;r++){
        for(int c=1;c <= N;c++) cin >> add_world[r][c];
    }

    for(int t = 0;t < M;t++){
        int r,c,y;
        cin >> r >> c >> y;
        alive_trees[r][c].push_back(y);
    }

    while(K-->0){
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for(int r = 1;r <= N;r++){
        for(int c = 1;c <=N;c++) ans += alive_trees[r][c].size();
    }

    cout << ans << '\n';
}