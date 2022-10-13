#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <chrono>
#include <set>

#define MAX_SIZE 20
#define MAX_TEAM 5

using namespace std;
int N,M,K;

int world[MAX_SIZE][MAX_SIZE] = {{0,}};
int checker[MAX_SIZE][MAX_SIZE] = {{0,}};

deque<pair<int,int> > teams[MAX_TEAM];

vector<pair<int,int> > moves = {{0,1},{0,-1},{1,0},{-1,0}};

void visualize(){

    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            int check = 0;
            for(int t_idx = 0;t_idx < M;t_idx++){
                for(int idx = 0;idx < teams[t_idx].size();idx++){
                    if(r == teams[t_idx][idx].first && c == teams[t_idx][idx].second){
                        check = 1;
                        if(idx == 0) cout << '1' << ' ';
                        else if(idx > 0 && idx < teams[t_idx].size() - 1) cout << '2' << ' ';
                        else cout << '3' << ' ';
                        break;
                    }
                }
                if(check == 1) break;
            }
            if(check == 0) cout << world[r][c] << ' ';
        }
        cout << '\n';
    }

    cout << "=====\n";
//    for(int t_idx = 0;t_idx < M;t_idx++) {
//        for (int idx = 0; idx < teams[t_idx].size(); idx++) cout << teams[t_idx][idx].first << '-' << teams[t_idx][idx].second << ' ';
//        cout << '\n';
//    }

}



void bfs(int r,int c, int t_idx){
    fill(&checker[0][0],&checker[0][0] + MAX_SIZE*MAX_SIZE,0);

    queue<pair<int,int> > q;
    q.push({r,c});

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(checker[top.first][top.second] == 1) continue;
        if(world[top.first][top.second] == 4 || world[top.first][top.second] == 0) continue;

        checker[top.first][top.second] = 1;
        teams[t_idx].push_back(top);
        for(int m_idx = 0;m_idx < 4;m_idx++){
            int r_m = top.first + moves[m_idx].first;
            int c_m = top.second + moves[m_idx].second;

            if(r_m < 0 || r_m >= N || c_m < 0 || c_m >= N) continue;
            if(world[top.first][top.second] == 1 && world[r_m][c_m] == 3) continue;

            q.push({r_m,c_m});
        }
    }
    for(int idx = 0;idx < teams[t_idx].size();idx++) world[teams[t_idx][idx].first][teams[t_idx][idx].second] = 4;
}


void build_teams(){
    int t_idx = 0;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            if(world[r][c] != 1) continue;
            bfs(r,c,t_idx);
            t_idx++;
        }
    }
}

void move_teams(){
    for(int t_idx = 0;t_idx < M;t_idx++){

        int r = teams[t_idx][0].first;
        int c = teams[t_idx][0].second;
        int r_2 = teams[t_idx][1].first;
        int c_2 = teams[t_idx][1].second;

        for(int m_idx = 0;m_idx < 4;m_idx++){
            int r_m = r + moves[m_idx].first;
            int c_m = c + moves[m_idx].second;
            if(r_m < 0 || r_m >= N || c_m < 0 || c_m >= N) continue;
            if(world[r_m][c_m] == 0 || (r_2 == r_m && c_2 == c_m)) continue;
            teams[t_idx].push_front({r_m,c_m});
        }
        teams[t_idx].pop_back();
    }
}

void reverse_team(int t_idx){
     deque<pair<int,int> > temp_team(teams[t_idx].rbegin(),teams[t_idx].rend());

     copy(temp_team.begin(),temp_team.end(),teams[t_idx].begin());
}

int ans = 0;


void calculate_score(int round){
    int temp_world[MAX_SIZE][MAX_SIZE] = {{0,}};
    int team_check[MAX_SIZE][MAX_SIZE] = {{0,}};

    copy(&world[0][0],&world[0][0] + MAX_SIZE*MAX_SIZE,&temp_world[0][0]);

    for(int t_idx = 0;t_idx < M;t_idx++){
        for(int idx = 0;idx < teams[t_idx].size();idx++){
            temp_world[teams[t_idx][idx].first][teams[t_idx][idx].second] = -(idx+1);
            team_check[teams[t_idx][idx].first][teams[t_idx][idx].second] = t_idx;
        }
    }


    if(round / N == 0){
        for(int c = 0;c < N;c++){
            if(temp_world[round % N][c] < 0) {
                ans += (temp_world[round % N][c] * temp_world[round % N][c]);
                reverse_team(team_check[round % N][c]);
                return;
            }
        }
    }
    else if(round / N == 1){
        for(int r = N - 1;r >= 0;r--){
            if(temp_world[r][round % N] < 0) {
                ans += (temp_world[r][round % N] * temp_world[r][round % N]);
                reverse_team(team_check[r][round % N]);
                return;
            }
        }
    }
    else if(round / N == 2){
        for(int c = N - 1;c >= 0;c--){
            if(temp_world[N - 1 - round % N][c] < 0) {
                ans += (temp_world[N - 1 - round % N][c] * temp_world[N - 1 - round % N][c]);
                reverse_team(team_check[N - 1 - round % N][c]);
                return;
            }
        }
    }
    else {
        for(int r = 0;r < N;r++){
            if(temp_world[r][N - 1 - round % N] < 0) {
                ans += (temp_world[r][N - 1 - round % N] * temp_world[r][N - 1 - round % N]);
                reverse_team(team_check[r][N - 1 - round % N]);
                return;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++) cin >> world[r][c];
    }
    int round = 0;
    build_teams();
    while(K-- > 0){
        move_teams();
        calculate_score(round);
        round++;
        round %= (4*N);
    }

    cout << ans;
}