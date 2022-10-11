#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <chrono>
#include <set>

using namespace std;

int N,M;
int world[49][49];

vector<pair<int,int> > transform_world(49*49,{0,0});
map<int,pair<int,int> > d_s = {{1,{-1,0}},{2,{1,0}},{3,{0,-1}},{4,{0,1}}};

vector<pair<int,int> > d_s_magic;
vector<int> ans(4,0);
void visualize(){
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++) cout << world[r][c] << ' ';
        cout << '\n';
    }
    cout << "=====\n";
}

void build_transform(){

    transform_world[0] = {N/2,N/2};
    int r = N/2;
    int c = N/2;
    for(int circle = 1;circle <= N/2;circle++){
        int line = 2 * circle;
        int phase = 0;
        c -= 1;
        transform_world[(2 * circle - 1) * (2 * circle - 1)] = {r,c};
        for(int idx = (2 * circle - 1) * (2 * circle - 1) + 1;idx < (2 * circle + 1) * (2 * circle + 1);idx++){
            if(phase == 0){
                r += 1;
            }
            else if(phase == 1){
                c += 1;
            }
            else if(phase == 2){
                r -= 1;
            }
            else {
                c -= 1;
            }
            transform_world[idx] = {r,c};
            if(idx % line == 0) phase++;
        }
    }

}

void blizzard(int d, int s){

    int c = N/2;

    for(int len = 1;len <= s;len++){
        if(d == 1){
            world[c + d_s[d].first * len][c] = 0;
        }
        else if(d == 2){
            world[c + d_s[d].first * len][c] = 0;
        }
        else if(d == 3){
            world[c][c + d_s[d].second * len] = 0;
        }
        else{
            world[c][c + d_s[d].second * len] = 0;
        }
    }
}

void forwarding_world(){
    int temp_world[49][49] = {{0,}};
    vector<int> numbers;
    for(int idx = 1;idx < N*N;idx++){
        if(world[transform_world[idx].first][transform_world[idx].second] == 0) continue;
        numbers.push_back(world[transform_world[idx].first][transform_world[idx].second]);

    }
    for(int idx = 1;idx <= numbers.size();idx++){
        temp_world[transform_world[idx].first][transform_world[idx].second] = numbers[idx - 1];
    }
    copy(&temp_world[0][0],&temp_world[0][0] + 49*49, &world[0][0]);
}

bool bomb(){
    int idx = 1;
    int output = false;

    while(idx < N*N){
        int num = world[transform_world[idx].first][transform_world[idx].second];
        if(num == 0) {
            break;
        }
        int check = 1;
        for(int temp = 1;temp < N*N - idx;temp++){
            if(num != world[transform_world[idx + temp].first][transform_world[idx + temp].second]) break;
            check++;
        }

        if(check >= 4){
            ans[num] += check;
            for(int temp = 0;temp < check;temp++) world[transform_world[idx + temp].first][transform_world[idx + temp].second] = 0;
            idx += check;
            output = true;
        }
        else{
            idx += 1;
        }
    }
    return output;
}

void group(){
    int idx = 1;

    int temp_world[49][49] = {{0,}};
    int temp_idx = 1;

    while(idx < N*N){
        if(temp_idx > N*N - 1) break;
        int num = world[transform_world[idx].first][transform_world[idx].second];
        if(num == 0) {
            break;
        }
        int check = 1;
        for(int temp = 1;temp < N*N - idx;temp++){
            if(num != world[transform_world[idx + temp].first][transform_world[idx + temp].second]) break;
            check++;
        }

        temp_world[transform_world[temp_idx].first][transform_world[temp_idx].second] = check;
        temp_world[transform_world[temp_idx + 1].first][transform_world[temp_idx + 1].second] = num;
        temp_idx += 2;
        idx += check;
    }
    copy(&temp_world[0][0],&temp_world[0][0] + 49*49, &world[0][0]);

}
int main() {
    cin >> N >> M;

    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++) cin >> world[r][c];
    }

    for(int i = 0;i < M;i++){
        int d,s;
        cin >> d >> s;
        d_s_magic.push_back({d,s});
    }
    build_transform();

    for(int idx = 0;idx < M;idx++){
        blizzard(d_s_magic[idx].first,d_s_magic[idx].second);
        forwarding_world();
        while(bomb()){
            forwarding_world();
        }
        group();
    }

    cout << ans[1]*1 + ans[2]*2 + ans[3]*3;
}