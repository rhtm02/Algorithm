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
int world[20][20] = {{0,}};
int temp_world[20][20] = {{0,}};
int field[20][20] = {{0,}};
int checker[20][20] = {{0,}};

vector<pair<int,int> > moves = {{0,-1},{0,1},{1,0},{-1,0}};
vector<pair<int,int> > coords;
int ans = 0;
bool compare(vector<int> a, vector<int> b){
    if((a[2] + a[3]) > (b[2] + b[3])) return true;
    else if (((a[2] + a[3]) == (b[2] + b[3])) && (a[2] > b[2])) return true;
    else if (((a[2] + a[3]) == (b[2] + b[3])) && (a[2] == b[2]) && (a[0] > b[0])) return true;
    else if (((a[2] + a[3]) == (b[2] + b[3])) && (a[2] == b[2]) && (a[0] == b[0]) && (a[1] > b[1])) return true;
    else return false;
}


void visualize(){
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++) {
            if(world[r][c] == -2) cout << ' ' << ' ';
            else if(world[r][c] == -1) cout << '*' << ' ';
            else cout <<  world[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << "=======\n";
}

void bfs(int r, int c, int num){
    queue<pair<int,int> > q;
    q.push({r,c});

    coords.clear();
    fill(&field[0][0],&field[0][0] + 20*20,0);

    while (!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(world[top.first][top.second] == -1 || field[top.first][top.second] == 1) continue;
        if(world[top.first][top.second] != num && world[top.first][top.second] != 0) continue;

        field[top.first][top.second] = 1;

        coords.push_back(top);

        if(world[top.first][top.second] > 0) checker[top.first][top.second] = 1;

        for(int m_idx = 0;m_idx < 4;m_idx++) {
            int r_m = top.first + moves[m_idx].first;
            int c_m = top.second + moves[m_idx].second;

            if (r_m < 0 || r_m >= N || c_m < 0 || c_m >= N) continue;

            q.push({r_m, c_m});
        }
    }
}

vector<int> count_block(){
    int rainbow_cnt = 0;
    int cnt = 0;
    int row = 0;
    int col = 0;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            if(field[r][c] == 1 && world[r][c] != 0) cnt++;
            else if(field[r][c] == 1 && world[r][c] == 0) rainbow_cnt++;
        }
    }
    for(int idx = 0;idx < N*N;idx++){
        if(field[idx / N][idx % N] == 1 && world[idx / N][idx % N] != 0){
            row = idx / N;
            col = idx % N;
            break;
        }
    }
    return {row,col,rainbow_cnt,cnt};
}

bool group_block(){
    fill(&checker[0][0],&checker[0][0] + 20*20,0);
    vector<vector<int> > groups;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            if(world[r][c] <= 0 || checker[r][c] == 1) continue;
            bfs(r,c,world[r][c]);
            vector<int> output = count_block();
            if((output[2] + output[3]) < 2) continue;
            groups.push_back(output);
        }
    }
    if(groups.size() == 0) return false;
    sort(groups.begin(),groups.end(), compare);
    
    bfs(groups[0][0],groups[0][1],world[groups[0][0]][groups[0][1]]);

    ans += (groups[0][2] + groups[0][3]) * (groups[0][2] + groups[0][3]);
    for(int idx = 0;idx < coords.size();idx++) world[coords[idx].first][coords[idx].second] = -2;


    return true;
}

void gravity_block(){

    fill(&temp_world[0][0],&temp_world[0][0] + 20*20,-2);

    for(int c = 0;c < N;c++){
        for(int r = N - 1;r >= 0;r--){
            if(world[r][c] == -1) {
                temp_world[r][c] = -1;
                continue;
            }
            else if(world[r][c] == -2) continue;
            int shift = r;
            while(shift < N - 1){
                if(temp_world[shift + 1][c] >= -1) break;
                shift++;
            }
            temp_world[shift][c] = world[r][c];
        }
    }
    copy(&temp_world[0][0],&temp_world[0][0] + 20*20,&world[0][0]);
}


void rotate_odd(){
    fill(&temp_world[0][0],&temp_world[0][0] + 20*20,-2);

    int r_center = N/2;
    int c_center = N/2;

    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++){
            int dr = r_center - r;
            int dc = c_center - c;

            if(dr > 0 && dc >= 0) temp_world[r_center + abs(dc)][c_center - abs(dr)] = world[r][c];
            else if(dr <= 0 && dc > 0) temp_world[r_center + abs(dc)][c_center + abs(dr)] = world[r][c];
            else if(dr < 0 && dc <= 0) temp_world[r_center - abs(dc)][c_center + abs(dr)] = world[r][c];
            else temp_world[r_center - abs(dc)][c_center - abs(dr)] = world[r][c];
        }
    }
    copy(&temp_world[0][0],&temp_world[0][0] + 20*20,&world[0][0]);
}

void rotate_even(){
    fill(&temp_world[0][0],&temp_world[0][0] + 20*20,-2);

    // 1
    for(int r = 0;r < N/2;r++){
        for(int c = 0;c < N/2;c++){
            int r_center = N/2;
            int c_center = N/2;
            int dr = r_center - r;
            int dc = c_center - c;

            if(dr > 0 && dc >= 0) temp_world[r_center - 1 + abs(dc)][c_center - abs(dr)] = world[r][c];
            else if(dr <= 0 && dc > 0) temp_world[r_center - 1 + abs(dc)][c_center + abs(dr)] = world[r][c];
            else if(dr < 0 && dc <= 0) temp_world[r_center - 1 - abs(dc)][c_center + abs(dr)] = world[r][c];
            else temp_world[r_center - 1 - abs(dc)][c_center - abs(dr)] = world[r][c];
        }
    }
    // 2
    for(int r = N/2;r < N;r++){
        for(int c = 0;c < N/2;c++){
            int r_center = N/2 - 1;
            int c_center = N/2;

            int dr = r_center - r;
            int dc = c_center - c;

            if(dr > 0 && dc >= 0) temp_world[r_center + abs(dc)][c_center - 1 - abs(dr)] = world[r][c];
            else if(dr <= 0 && dc > 0) temp_world[r_center + abs(dc)][c_center - 1 + abs(dr)] = world[r][c];
            else if(dr < 0 && dc <= 0) temp_world[r_center - abs(dc)][c_center - 1 + abs(dr)] = world[r][c];
            else temp_world[r_center - abs(dc)][c_center - 1 - abs(dr)] = world[r][c];
        }
    }
    // 3
    for(int r = N/2;r < N;r++){
        for(int c = N/2;c < N;c++){
            int r_center = N/2 - 1;
            int c_center = N/2 - 1;

            int dr = r_center - r;
            int dc = c_center - c;

            if(dr > 0 && dc >= 0) temp_world[r_center + 1 + abs(dc)][c_center - abs(dr)] = world[r][c];
            else if(dr <= 0 && dc > 0) temp_world[r_center + 1 + abs(dc)][c_center + abs(dr)] = world[r][c];
            else if(dr < 0 && dc <= 0) temp_world[r_center + 1 - abs(dc)][c_center + abs(dr)] = world[r][c];
            else temp_world[r_center + 1 - abs(dc)][c_center - abs(dr)] = world[r][c];
        }
    }
    // 4
    for(int r = 0;r < N/2;r++){
        for(int c = N/2;c < N;c++){
            int r_center = N/2;
            int c_center = N/2 - 1;

            int dr = r_center - r;
            int dc = c_center - c;

            if(dr > 0 && dc >= 0) temp_world[r_center + abs(dc)][c_center + 1 - abs(dr)] = world[r][c];
            else if(dr <= 0 && dc > 0) temp_world[r_center + abs(dc)][c_center + 1 + abs(dr)] = world[r][c];
            else if(dr < 0 && dc <= 0) temp_world[r_center - abs(dc)][c_center + 1 + abs(dr)] = world[r][c];
            else temp_world[r_center - abs(dc)][c_center + 1 - abs(dr)] = world[r][c];
        }
    }
    copy(&temp_world[0][0],&temp_world[0][0] + 20*20,&world[0][0]);
}

void rotate_90_ccw(){

    if(N % 2 == 1) rotate_odd();
    else rotate_even();
}


int main() {
    cin >> N >> M;
    for(int r = 0;r < N;r++){
        for(int c = 0;c < N;c++) cin >> world[r][c];
    }


    while(group_block()){
        gravity_block();
        rotate_90_ccw();
        gravity_block();
    }


    cout << ans;
}