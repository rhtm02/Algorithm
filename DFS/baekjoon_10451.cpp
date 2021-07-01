#include <iostream>
#include <vector>
using namespace std;
vector<int> vertex;
vector<int> edge;
void dfs(int v)
{
    if(vertex[v] == 1) return;
    vertex[v] = 1;
    dfs(edge[v]);
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
        for(int idx = 1;idx <= N;idx++) cin >> edge[idx];
        int ans = 0;
        for(int i = 1;i <= N;i++)
        {
            if(vertex[i] == 1) continue;
            dfs(i);
            ans++;
        }
        cout << ans << '\n';
    }

}
