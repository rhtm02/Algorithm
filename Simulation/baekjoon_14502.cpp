#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;

int N,M;
int world[8][8] = {{0,}};
int checker[8][8] = {{0,}};
int depth = 3;
vector<pair<int,int> > combination(3);
vector<pair<int,int> > moves = {{0,-1},{0,1},{1,0},{-1,0}};
int ans = 0;
void visualize(){

    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++) cout << checker[r][c] << ' ';
        cout << '\n';
    }
    cout << "----------\n";
}

void bfs(){
    queue<pair<int,int> > q;

    for(int r = 0;r < N;r++){
        for(int c =0;c<M;c++){
            if(world[r][c] == 2) q.push({r,c});
        }
    }

    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        if(world[temp.first][temp.second] == 1 || checker[temp.first][temp.second] != 0) continue;
        checker[temp.first][temp.second] = 1;

        for(int move_idx = 0;move_idx < moves.size();move_idx++){
            int r_m = temp.first + moves[move_idx].first;
            int c_m = temp.second + moves[move_idx].second;

            if(r_m < 0 || r_m >= N || c_m < 0 || c_m >= M) continue;

            q.push({r_m,c_m});
        }
//        visualize();
    }

    int val = 0;
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            if(world[r][c] == 0 && checker[r][c] == 0) val++;
        }
    }
    ans = max(ans,val);
}

void recursive(int r,int c){
    if(world[r][c] != 0) return;
    if(depth == 0){
        combination[depth].first = r;
        combination[depth].second = c;
        for(int comb_idx = 0;comb_idx < 3;comb_idx++) world[combination[comb_idx].first][combination[comb_idx].second] = 1;
        bfs();
        for(int comb_idx = 0;comb_idx < 3;comb_idx++) world[combination[comb_idx].first][combination[comb_idx].second] = 0;
        for(int r = 0;r < N;r++){
            for(int c = 0;c < M;c++) checker[r][c] = 0;
        }
//        cout << "======\n";
        return;
    }

    combination[depth].first = r;
    combination[depth].second = c;

    for(int idx = (M*r + c + 1);idx < N*M;idx++){
        int r_m = idx / M;
        int c_m = idx % M;
        depth--;
        recursive(r_m,c_m);
        depth++;
    }


}

int main() {
    cin >> N >> M;

    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++) cin >> world[r][c];
    }
    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++){
            depth--;
            recursive(r,c);
            depth++;
        }
    }
    cout << ans;
}