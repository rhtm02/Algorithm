#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int W; int H;
vector<vector<int>> table;
int ans = 0;
vector<pair<int, int>> shift = { {-1,0},{1,0},{0,-1},{0,1} };
void bfs(vector<pair<int, int>> roots)
{
    queue<pair<int, int>> q;
    for (auto it : roots)
    {
        table[it.first][it.second] = 1;
        q.push(it);
    }
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (auto it : shift)
        {
            pair<int, int> route;
            route.first = temp.first + it.first;
            route.second = temp.second + it.second;
            if (route.first < 0 || route.first >= H || route.second < 0 || route.second >= W) continue;
            if (table[route.first][route.second] != 0) continue;
            q.push(route);
            table[route.first][route.second] = table[temp.first][temp.second] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> W; cin >> H;

    vector<pair<int, int>> roots;
    for (int h = 0; h < H; h++) {
        vector<int> Ws;
        for (int w = 0; w < W; w++) {
            int val;
            cin >> val;
            if (val == -1) { Ws.push_back(-1); continue; }
            Ws.push_back(0);
            if (val == 1) roots.emplace_back(make_pair(h, w));
        }
        table.push_back(Ws);
    }
    bfs(roots);

    for (auto it : table)
    {
        for(auto w:it)
        if (w == 0)
        {
            cout << -1;
            return 0;
        }
    }
    for (auto it : table)
    {
        for(auto w:it)  ans = max(ans, w);
    }
    cout << ans - 1;
}