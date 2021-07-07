#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<vector<int>> table;

vector<pair<int, int>> shift = { {-1,0},{1,0},{0,1},{0,-1} };
int N; int M;

void bfs(pair<int,int> v)
{
    queue<pair<int,int>> q;
    q.push(v);
    table[0][0] = 1;

    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        if((temp.first == N -1) && (temp.second == M - 1)) break;
        for(auto it:shift)
        {
            int h = temp.first + it.first;
            int w = temp.second + it.second;
            if(h < 0 || h >= N || w < 0 || w >= M) continue;
            if(table[h][w] != 0) continue;
            table[h][w] = table[temp.first][temp.second] + 1;
            q.push(make_pair(h,w));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N; cin >> M;

    for (int n = 0; n < N; n++)
    {
        vector<int> temp;
        string str;
        cin >> str;
        for (auto it : str)
        {
            if (it == '0') temp.push_back(-1);
            else if (it == '1') temp.push_back(0);
        }

        table.push_back(temp);
    }

    bfs(make_pair(0,0));
//    for(auto h:table)
//    {
//        for(auto w:h) cout << w << "  ";
//        cout << '\n';
//    }
    cout << table[N - 1][M - 1];
}