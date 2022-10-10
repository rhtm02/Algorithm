#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <chrono>
#include <set>

using namespace std;

int N,M,K;

int dice[4][4] = {{0,2,0,0},
                  {4,1,3,6},
                  {0,5,0,0},
                  {0,6,0,0}};
pair<int,int> dice_pos = {1,1};
int dice_direction = 0;
int world[21][21] = {{0,}};
map<int, pair<int,int> > dice_directions = {{0,{0,1}},{1,{-1,0}},{2,{0,-1}},{3,{1,0}}};

void visualize(){
    cout << "WORLD : \n";
    for(int r = 1;r <= N;r++){
        for(int c = 1;c <=M;c++) cout << world[r][c] << ' ';
        cout << '\n';
    }

    cout << "DICE : \n";
    for(int r = 0;r < 4;r++){
        for(int c = 0;c < 4;c++) cout << dice[r][c] << ' ';
        cout << '\n';
    }
    cout << "DICE POS : " << dice_pos.first << '-' << dice_pos.second << '\n';
    cout << "DICE DRECTION : " << dice_direction << '\n';
    cout << "=================\n";

}

void roll_dice(){

    int r_m = dice_pos.first + dice_directions[dice_direction].first;
    int c_m = dice_pos.second + dice_directions[dice_direction].second;

    if(r_m < 1 || r_m > N || c_m < 1 || c_m > M){
        dice_direction += 2;
        dice_direction %= 4;
        r_m = dice_pos.first + dice_directions[dice_direction].first;
        c_m = dice_pos.second + dice_directions[dice_direction].second;
    }

    dice_pos = {r_m,c_m};
    int temp_dice[4][4];
    copy(&dice[0][0],&dice[0][0] + 4*4,&temp_dice[0][0]);
    if(dice_direction == 0){
        for(int c = 0;c < 4;c++) temp_dice[1][(c + 1) % 4] = dice[1][c];
        temp_dice[3][1] = temp_dice[1][3];
        copy(&temp_dice[0][0],&temp_dice[0][0] + 4*4,&dice[0][0]);
    }
    else if(dice_direction == 1){
        for(int r = 3;r >= 0;r--) temp_dice[(r - 1 + 4) % 4][1] = dice[r][1];
        temp_dice[1][3] = temp_dice[3][1];
        copy(&temp_dice[0][0],&temp_dice[0][0] + 4*4,&dice[0][0]);
    }
    else if(dice_direction == 2){
        for(int c = 3;c >= 0;c--) temp_dice[1][(c - 1 + 4) % 4] = dice[1][c];
        temp_dice[3][1] = temp_dice[1][3];
        copy(&temp_dice[0][0],&temp_dice[0][0] + 4*4,&dice[0][0]);
    }
    else{
        for(int r = 0;r < 4;r++) temp_dice[(r + 1) % 4][1] = dice[r][1];
        temp_dice[1][3] = temp_dice[3][1];
        copy(&temp_dice[0][0],&temp_dice[0][0] + 4*4,&dice[0][0]);
    }
}

int checker[21][21] = {{0,}};
vector<pair<int,int> > moves = {{0,1},{0,-1},{1,0},{-1,0}};

int cal_score(){

    int cnt = 0;
    int num = world[dice_pos.first][dice_pos.second];

    fill(&checker[0][0],&checker[0][0] + 21*21,0);
    queue<pair<int,int> > q;
    q.push(dice_pos);

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(checker[top.first][top.second] == 1 || world[top.first][top.second] != num) continue;
        checker[top.first][top.second] = 1;
        cnt++;
        for(int m_idx = 0;m_idx < 4;m_idx++){
            int r_m = top.first + moves[m_idx].first;
            int c_m = top.second + moves[m_idx].second;
            if(r_m < 1 || r_m > N || c_m < 1 || c_m > M) continue;
            q.push({r_m,c_m});
        }
    }

    return cnt * num;
}

void rotate_direction(){

    int bottom_num = dice[1][3];
    int world_num = world[dice_pos.first][dice_pos.second];

    if(bottom_num > world_num){
        dice_direction += 3;
        dice_direction %= 4;
    }
    else if(bottom_num < world_num){
        dice_direction += 1;
        dice_direction %= 4;
    }
}


int main() {
    cin >> N >> M >> K;

    for(int r = 1;r <= N;r++){
        for(int c = 1; c <=M ;c++) cin >> world[r][c];
    }
    int ans = 0;
    while(K-->0){
        roll_dice();
        ans += cal_score();
        rotate_direction();
    }
    cout << ans;
}