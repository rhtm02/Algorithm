//
// Created by 이형준 on 2022/01/04.
//
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
using namespace std;

int N,M;
int r,c,pos;
vector<vector<int>> room;

map<string,pair<int,int>> left_moves = {{"up",{0,-1}},{"right",{-1,0}},{"down",{0,1}},{"left",{1,0}}};
map<pair<int,int>,int> change_head = {{{0,-1},3},{{-1,0},0},{{0,1},1},{{1,0},2}};
map<int,string> heading = {{0,"up"},{1,"right"},{2,"down"},{3,"left"}};
map<int,pair<int,int>> backward = {{0,{1,0}},{1,{0,-1}},{2,{-1,-0}},{3,{0,1}}};
vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> pos;

    for(int i = 0;i<N;i++){
        vector<int> temp;
        for(int j = 0;j<M;j++){
            int val;
            cin >> val;
            temp.push_back(val);
        }
        room.push_back(temp);
    }


    int ans = 0;

    while(1){
        room[r][c] = 2;
        int checker = 1;
        for(auto it:moves){
            checker *= room[r + it.first][c + it.second];
        }
        if(checker != 0){
            r += backward[pos].first;
            c += backward[pos].second;

            if(room[r][c] == 1) break;
            continue;
        }
        int m_r = r + left_moves[heading[pos]].first;
        int m_c = c + left_moves[heading[pos]].second;
        if(room[m_r][m_c] == 0){
            pos = change_head[left_moves[heading[pos]]];
            r = m_r;
            c = m_c;
        }
        else pos = change_head[left_moves[heading[pos]]];
//
//        for(auto it:room){
//            for(auto it2:it) cout << it2 << ' ';
//            cout << '\n';
//        }
    }

    for(auto it:room){
        for(auto it2:it){
            if(it2 == 2) ans++;
        }
    }
    cout << ans;

}