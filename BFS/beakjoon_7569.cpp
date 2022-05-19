#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef vector<vector<int>> layer;

int M,N,H;
map<int,layer> tomatos;
layer start;

int ans = 0;

vector<pair<int,int>> layer_moves = {{0,-1},{-1,0},{1,0},{0,1}};
vector<int> up_down = {-1,1};

vector<vector<int>> diffuse(int h,int m,int n){
    vector<vector<int>> outputs;

    for(auto it:up_down){
        if(tomatos[h + it].empty()) continue;
        if(tomatos[h + it][m - 1][n - 1] == -1) continue;
        tomatos[h + it][m - 1][n - 1] = 1;
        outputs.push_back({h + it,m,n});
    }
    for(auto it:layer_moves){
        if((m + it.first) > M || (n + it.second) > N) continue;
        if(tomatos[h][m - 1 + it.first][n - 1 + it.second] == -1) continue;
        tomatos[h][m - 1 + it.first][n - 1 + it.second] = 1;
        outputs.push_back({h,m + it.first,n + it.second});
    }
    return outputs;
};


void bfs(){

    queue<vector<vector<int>>> q;
    vector<vector<int>> temp1;
    for(auto it:start){
        vector<int> temp2;
        for(auto it2:it) temp2.push_back(it2);
        temp1.push_back(temp2);
    }
    q.push(temp1);

    while(!q.empty()){
        vector<vector<int>> h_m_ns = q.front();
        q.pop();
        vector<vector<int>> outputs;
        for(auto it: h_m_ns) {
            //diffuse(it[0],it[1],it[2]);
            int h = it[0],m = it[1],n = it[2];
            if(tomatos[h][m - 1][n - 1] != 1) continue;
            for(auto it:up_down){
                if(tomatos[h + it].empty()) continue;
                if(tomatos[h + it][m - 1][n - 1] == 0){
                    tomatos[h + it][m - 1][n - 1] = 1;
                    outputs.push_back({h + it,m,n});
                }
            }
            for(auto it:layer_moves){
                if((m + it.first) < 1 ||(m + it.first) > N || (n + it.second) > M || (n + it.second) < 1) continue;
                if(tomatos[h][m - 1 + it.first][n - 1 + it.second] == 0){
                    tomatos[h][m - 1 + it.first][n - 1 + it.second] = 1;
                    outputs.push_back({h,m + it.first,n + it.second});
                }

            }
        }
//        for(auto it:tomatos){
//            cout << it.first << '\n';
//            for(auto it2:it.second){
//                for(auto it3:it2) cout << it3 << ' ';
//                cout << '\n';
//            }
//        }
        if(outputs.empty()) continue;
        ans++;
        q.push(outputs);

    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> M >> N >> H;

    for(int h = 1;h <= H;h++) {
        layer l;
        for(int n = 0;n < N;n++){
            vector<int> row;
            for(int m = 0;m < M;m++){
                int temp;
                cin >> temp;
                row.push_back(temp);
                if(temp == 1) start.push_back({h,n + 1,m + 1});
            }
            l.push_back(row);
        }
        tomatos[h] = l;
    }

    bfs();
//    for(auto it:start){
//        for(auto it2:it) cout << it2 << ' ';
//        cout << '\n';
//    }

//
//    diffuse(2,3,2);
//
    for(auto it:tomatos){
        for(auto it2:it.second){
            for(auto it3:it2){
                if(it3 == 0) ans = -1;
            }
        }
    }

    cout << ans;
}
