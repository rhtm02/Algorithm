#include <iostream>
#include <utility>
#include <map>
#include <queue>
using namespace std;
map<pair<int,int>,int> table;
int W; int H;
void bfs(pair<int,int> root)
{
    queue<pair<int,int>> q;
    q.push(root);
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        if(table[temp] == 0) continue;
        table[temp] = 0;
        if(temp.first == 1)
        {
            if(temp.second == 1)
            {
                q.push(make_pair(temp.first + 1,temp.second));
                q.push(make_pair(temp.first + 1,temp.second + 1));
                q.push(make_pair(temp.first,temp.second + 1));
                continue;
            }
            else if(temp.second == W)
            {
                q.push(make_pair(temp.first,temp.second - 1));
                q.push(make_pair(temp.first + 1,temp.second - 1));
                q.push(make_pair(temp.first + 1,temp.second));
                continue;
            }
            q.push(make_pair(temp.first + 1,temp.second));
            q.push(make_pair(temp.first + 1,temp.second + 1));
            q.push(make_pair(temp.first + 1,temp.second - 1));
            q.push(make_pair(temp.first,temp.second + 1));
            q.push(make_pair(temp.first,temp.second - 1));
        }
        else if(temp.first == H)
        {
            if(temp.second == 1)
            {
                q.push(make_pair(temp.first - 1,temp.second));
                q.push(make_pair(temp.first - 1,temp.second + 1));
                q.push(make_pair(temp.first,temp.second + 1));
                continue;
            }
            else if(temp.second == W)
            {
                q.push(make_pair(temp.first - 1,temp.second));
                q.push(make_pair(temp.first - 1,temp.second - 1));
                q.push(make_pair(temp.first,temp.second - 1));
                continue;
            }
            q.push(make_pair(temp.first - 1,temp.second - 1));
            q.push(make_pair(temp.first - 1,temp.second));
            q.push(make_pair(temp.first - 1,temp.second + 1));
            q.push(make_pair(temp.first,temp.second - 1));
            q.push(make_pair(temp.first,temp.second + 1));
        }
        else
        {
            if(temp.second == 1)
            {
                q.push(make_pair(temp.first - 1,temp.second));
                q.push(make_pair(temp.first - 1,temp.second + 1));
                q.push(make_pair(temp.first,temp.second + 1));
                q.push(make_pair(temp.first + 1,temp.second));
                q.push(make_pair(temp.first + 1,temp.second + 1));
                continue;
            }
            else if(temp.second == W)
            {
                q.push(make_pair(temp.first - 1,temp.second - 1));
                q.push(make_pair(temp.first - 1,temp.second));
                q.push(make_pair(temp.first,temp.second - 1));
                q.push(make_pair(temp.first + 1,temp.second));
                q.push(make_pair(temp.first + 1,temp.second - 1));
                continue;
            }
            q.push(make_pair(temp.first - 1,temp.second - 1));
            q.push(make_pair(temp.first - 1,temp.second));
            q.push(make_pair(temp.first - 1,temp.second + 1));
            q.push(make_pair(temp.first,temp.second - 1));
            q.push(make_pair(temp.first,temp.second + 1));
            q.push(make_pair(temp.first + 1,temp.second - 1));
            q.push(make_pair(temp.first + 1,temp.second));
            q.push(make_pair(temp.first + 1,temp.second + 1));
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1) {
        cin >> W;
        cin >> H;
        if ((W == 0) && (H == 0)) return 0;
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W;w++) {
                int val;
                cin >> val;
                table[make_pair(h,w)] = val;
            }
        }
        for(auto it:table)
        {
            if(it.second == 0) continue;
            bfs(it.first);
            ans++;
        }
        cout << ans << '\n';
//        for(auto it:table)
//        {
//            //cout << it.first.first << ' ' << it.first.second << " : ";
//            cout << it.second << ' ';
//            if(it.first.second >= W) cout << '\n';
//        }
    }
}