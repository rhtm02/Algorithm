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

map<int,int> cctv_state = {{1,4},{2,2},{3,4},{4,4},{5,1}};
vector<pair<int,int> > cctv_coordinates;
vector<pair<int,int> > status;
int depth = 0;
int ans;
void visualize(){
    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++) cout << world[r][c] << ' ';
        cout << '\n';
    }
    cout << "=======\n";

}

void beam_down(int r, int c){
    for(int r_m = r + 1;r_m < N;r_m++) {
        if(world[r_m][c] == 6) break;
        world[r_m][c] = 7;
    }
}

void beam_up(int r, int c){
    for(int r_m = r - 1;r_m >= 0;r_m--) {
        if(world[r_m][c] == 6) break;
        world[r_m][c] = 7;
    }
}

void beam_right(int r, int c){
    for(int c_m = c + 1;c_m < M;c_m++) {
        if(world[r][c_m] == 6) break;
        world[r][c_m] = 7;
    }
}

void beam_left(int r, int c){
    for(int c_m = c - 1;c_m >= 0;c_m--) {
        if(world[r][c_m] == 6) break;
        world[r][c_m] = 7;
    }
}



void cctv_operate(){
    int temp_world[8][8];

    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++) temp_world[r][c] = world[r][c];
    }

    for(int idx = 0; idx < cctv_coordinates.size();idx++){
        int r = cctv_coordinates[idx].first;
        int c = cctv_coordinates[idx].second;
        int type = status[idx].first;
        int state = status[idx].second;

        if(type == 1){
            if(state == 0) {
                beam_right(r,c);
            }
            else if(state == 1){
                beam_down(r,c);
            }
            else if(state == 2){
                beam_left(r,c);
            }
            else {
                beam_up(r,c);
            }
        }
        else if(type == 2){
            if(state == 0) {
                beam_right(r,c);
                beam_left(r,c);
            }
            else {
                beam_up(r,c);
                beam_down(r,c);
            }
        }
        else if(type == 3){
            if(state == 0) {
                beam_right(r,c);
                beam_up(r,c);
            }
            else if(state == 1){
                beam_down(r,c);
                beam_right(r,c);
            }
            else if(state == 2){
                beam_left(r,c);
                beam_down(r,c);
            }
            else {
                beam_up(r,c);
                beam_left(r,c);
            }
        }
        else if(type == 4){
            if(state == 0) {
                beam_right(r,c);
                beam_up(r,c);
                beam_left(r,c);
            }
            else if(state == 1){
                beam_down(r,c);
                beam_right(r,c);
                beam_up(r,c);
            }
            else if(state == 2){
                beam_right(r,c);
                beam_down(r,c);
                beam_left(r,c);
            }
            else {
                beam_up(r,c);
                beam_left(r,c);
                beam_down(r,c);
            }
        }
        else{
            beam_right(r,c);
            beam_down(r,c);
            beam_left(r,c);
            beam_up(r,c);
        }
    }
    //visualize();
    int val = 0;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++){
            if(world[r][c] == 0) val++;
        }
    }

    for(int r = 0;r < N;r++){
        for(int c = 0;c < M;c++) world[r][c] = temp_world[r][c];
    }

    ans = min(ans,val);

}


void recursive(int direction){

    if(depth == status.size() - 1) {
        status[depth].second = direction;
        //for(int idx = 0;idx < status.size();idx++) cout << status[idx].first << '-' << status[idx].second << '\n';
        //cout << "\n=======\n";

        cctv_operate();
        //cout << "\n=======\n";
        return;
    }

    status[depth].second = direction;
    for(int cur_direction = 0;cur_direction < cctv_state[status[depth + 1].first];cur_direction++){
        depth++;
        recursive(cur_direction);
        depth--;
    }

}


int main() {
    cin >> N >> M;
    for(int r = 0;r < N;r++){
        for(int c = 0; c < M;c++) {
            cin >> world[r][c];
            if(world[r][c] != 0 && world[r][c] != 6) {
                cctv_coordinates.push_back({r, c});
                status.push_back({world[r][c], 0});
            }
        }
    }

    ans = N*M;

    if(status.size() == 0) {
        int val = 0;
        for(int r = 0;r < N;r++){
            for(int c = 0;c < M;c++){
                if(world[r][c] == 0) val++;
            }
        }
        ans = min(ans,val);
        cout << ans;
    }
    else{
        for(int pos = 0; pos < cctv_state[status[depth].first];pos++)   recursive(pos);
        cout << ans;
    }

}