#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <chrono>
#include<set>

using namespace std;
int M,S;
int world[5][5][9] = {{{0,}}};
int fish_smell[5][5] = {{0,}};
pair<int,int> shark;
int fishes[5][5][9] = {{{0,}}};
map<int,pair<int,int> > fish_moves = {{0,{0,0}},{1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}},{5,{0,1}},{6,{1,1}},{7,{1,0}},{8,{1,-1}}};
map<int,pair<int,int> > shark_moves = {{1,{-1,0}},{2,{0,-1}},{3,{1,0}},{4,{0,1}}};


void visualize(){
    for(int r = 1;r <=4 ; r++){
        for(int c = 1;c <=4;c++){
            int sum = 0;
            for(int idx = 1;idx <=8;idx++) sum += world[r][c][idx];
            cout << sum << ' ';
        }
        cout << '\n';
    }
    cout << "--------\n";
    for(int r = 1;r <=4 ; r++){
        for(int c = 1;c <=4;c++) cout << fish_smell[r][c] << ' ';
        cout << '\n';
    }
            cout << "SHARK : " << shark.first << '-' << shark.second << '\n';
    cout << "=====\n";
}

int rotate(int direc, int r, int c){
    int cnt = 8;
    while(cnt-- > 0){
        int r_m = r + fish_moves[direc].first;
        int c_m = c + fish_moves[direc].second;
        if(r_m < 1 || r_m > 4 || c_m < 1 || c_m > 4 || fish_smell[r_m][c_m] != 0 || (r_m == shark.first && c_m == shark.second)) {
            direc--;
            if(direc == 0) direc = 8;
            continue;
        }
        else return direc;
    }

    return 0;
}

void move_fishes(){

    int temp_world[5][5][9] = {{{0,}}};

    for(int r = 1;r <= 4;r++){
        for(int c = 1;c <= 4;c++){
            for(int direc = 1;direc <= 8;direc++){
                if(world[r][c][direc] == 0) continue;
                int cur_direc = rotate(direc,r,c);
                int r_m = r + fish_moves[cur_direc].first;
                int c_m = c + fish_moves[cur_direc].second;
                if(cur_direc == 0) temp_world[r_m][c_m][direc] += world[r][c][direc];
                else temp_world[r_m][c_m][cur_direc] += world[r][c][direc];
            }
        }
    }

    copy(&temp_world[0][0][0], &temp_world[0][0][0] + 5*5*9, &world[0][0][0]);
}

int depth = 3;

int max_fish_num = -1;
vector<int> combination;
vector<int> route(3);

void shark_move(){
    if(depth == 0){

        int val = 0;
        int r = shark.first;
        int c = shark.second;
        int temp_world[5][5][9];
        copy(&world[0][0][0],&world[0][0][0] + 5*5*9,&temp_world[0][0][0]);

        for(int idx = 0;idx < 3;idx++){
            r += shark_moves[combination[idx]].first;
            c += shark_moves[combination[idx]].second;
            if(r < 1 || r > 4 || c < 1 || c > 4) return;
            for(int idx = 1;idx <= 8;idx++){
                if(temp_world[r][c][idx] == 0) continue;
                val += temp_world[r][c][idx];
                temp_world[r][c][idx] = 0;
            }
        }

        if(max_fish_num < val){
            max_fish_num = val;
            copy(combination.begin(),combination.end(),route.begin());
        }
        return;
    }
    for(int idx = 1;idx <=4;idx++){
        depth--;
        combination.push_back(idx);
        shark_move();
        combination.pop_back();
        depth++;
    }
}

void shark_route(){
    max_fish_num = -1;
    combination.clear();

    for(int idx = 1;idx <=4;idx++){
        depth--;
        combination.push_back(idx);
        shark_move();
        combination.pop_back();
        depth++;
    }

    int r = shark.first;
    int c = shark.second;

    for(int idx = 0;idx < 3;idx++){
        r += shark_moves[route[idx]].first;
        c += shark_moves[route[idx]].second;
        int val = 0;
        for(int d = 1;d <= 8;d++) {
            if(world[r][c][d] != 0) val++;
            world[r][c][d] = 0;
        }
        if(val > 0) fish_smell[r][c] = 3;
    }

    shark = {r,c};
}

void delete_smell(){
    for(int r = 1;r <= 4;r++){
        for(int c = 1;c <=4;c++){
            if(fish_smell[r][c] > 0) fish_smell[r][c]--;
        }
    }
}

void duplicate_fishes(){
    for(int r = 1;r <= 4;r++){
        for(int c = 1;c <=4;c++){
            for(int d = 1;d <= 8;d++){
                world[r][c][d] += fishes[r][c][d];
            }
        }
    }

    copy(&world[0][0][0],&world[0][0][0] + 5*5*9,&fishes[0][0][0]);
}

int main() {
    cin >> M >> S;
    for(int i = 0;i < M;i++){
        int r,c,d;
        cin >> r >> c >> d;
        world[r][c][d]++;
        fishes[r][c][d]++;
    }

    int r,c;
    cin >> r >> c;
    shark.first = r; shark.second = c;

    while(S-- > 0){
        move_fishes();
        shark_route();
        delete_smell();
        duplicate_fishes();
    }


    int ans = 0;
    for(int r = 1;r <= 4;r++){
        for(int c = 1;c <=4;c++){
            for(int d = 1;d <= 8;d++){
                ans += world[r][c][d];
            }
        }
    }
    cout << ans;

}