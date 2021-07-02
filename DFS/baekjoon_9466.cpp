#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> vertex;
vector<int> edge;

void dfs(int v,map<int,int> &table)
{
    if(vertex[v] == 1) return;
    if(vertex[v] == -1) return;
    table[v]++;
    if(table[v] == 3) return;
    dfs(edge[v],table);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; int N;
    cin >> T;
    for(int t = 0;t < T;t++)
    {
        cin >> N;
        vertex.assign(N + 1,0);
        edge.assign(N + 1,0);
        for(int idx = 1;idx <=N;idx++) cin >> edge[idx];
        int ans = 0;
        for(int i = 1;i <= N;i++)
        {
            if(vertex[i] == 1) continue;
            map<int,int> table;
            dfs(i,table);
            for(auto it:table)
            {
                //cout << it.first << ' ' << it.second << '\n';
                if(it.second >= 2) vertex[it.first] = 1;
                else vertex[it.first] = -1;
            }
            //for(auto it:vertex) cout << it << ' ';
            //cout << '\n';
            //cout << "========\n";
        }
        for(auto it:vertex) if(it == -1) ans++;
        cout << ans << '\n';
    }
}