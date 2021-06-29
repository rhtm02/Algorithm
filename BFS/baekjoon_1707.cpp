#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int,vector<int>> edge;
vector<char> vertex;

bool bfs(int root)
{
    queue<int> q;
    q.push(root);
    vertex[root] = 'B';
    while(!q.empty())
    {
        int present_v = q.front();
        q.pop();
        for(auto it:edge[present_v])
        {
            if(vertex[it] != NULL)
            {
                if((vertex[present_v] == 'R') && (vertex[it] == 'R')) return false;
                else if((vertex[present_v] == 'B') && (vertex[it] == 'B')) return false;
                continue;
            }
            if((vertex[present_v] == 'R') && (vertex[it] == NULL)) vertex[it] = 'B';
            else if((vertex[present_v] == 'B') && (vertex[it] == NULL)) vertex[it] = 'R';
            q.push(it);
        }
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; int V; int E;
    cin >> T;
    for(int t = 0;t < T;t++)
    {
        cin >> V; cin >> E;
        vertex.assign(V + 1,NULL);
        for(int i = 0;i < E;i++)
        {
            int v1; int v2;
            cin >> v1; cin >> v2;
            edge[v1].push_back(v2);
            edge[v2].push_back(v1);
        }
        bool ans = true;
        for(int i = 1;i <= V;i++)
        {
            if(vertex[i] != NULL) continue;
            ans = bfs(i);
            if(ans == false) break;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
        vertex.clear();
        edge.clear();
    }
}