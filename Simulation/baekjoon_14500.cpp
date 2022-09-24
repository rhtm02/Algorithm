#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;

int N,M;
int world[500][500];
int checker[500][500] = {{0,}};
int depth = 4;
vector<pair<int,int> > moves = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int> > centers = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};

int ans = 0;
vector<int> answers;


void recursive(int r,int c, int val){
    if(depth == 0) {ans = max(ans,val); return;}


    for(int m_idx = 0;m_idx < moves.size();m_idx++){
        int r_m = r + moves[m_idx].first;
        int c_m = c + moves[m_idx].second;

        if(checker[r_m][c_m] == 1) continue;
        if(r_m < 0 || r_m >= N || c_m < 0 || c_m >= M) continue;

        checker[r][c] = 1;
        depth--;
        recursive(r_m,c_m,val + world[r_m][c_m]);
        depth++;
        checker[r][c] = 0;
    }
}

int main() {

    cin >> N >> M;

    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++) cin >> world[r][c];
    }

    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            depth--;
            recursive(r,c,world[r][c]);
            depth++;
        }
    }

    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            for(int centers_idx = 0;centers_idx < centers.size();centers_idx++){
                int val = world[r][c];
                int check = 0;
                for(int idx = 0;idx < centers[centers_idx].size();idx++){
                    int r_m = r + moves[centers[centers_idx][idx]].first;
                    int c_m = c + moves[centers[centers_idx][idx]].second;
                    if(r_m < 0 || r_m >= N || c_m < 0 || c_m >= M) {
                        check = 1;
                        break;
                    }
                    val += world[r_m][c_m];
                }
                if(check == 0) ans = max(ans,val);
            }
        }
    }
    cout << ans;

}