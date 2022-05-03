#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;
int N,M;
//map<int,vector<int>> inputs;
//map<int,int> check;

vector<vector<int>> inputs(100000 + 1);
vector<int> check(100000 + 1);

int bridge = 0;
int pass = 0;

void dfs(int node){
    if(check[node] == 1) {
        return;
    }

    check[node] = 1;

    for(auto it:inputs[node]){
        if(check[it] == 0) {
            pass++;
        }
        dfs(it);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N; cin >> M;

    if(M == 0) {
        cout << N - 1;
        return 0;
    }



    for(int i = 0;i < M;i++){
        int u,v;
        cin >> u; cin >> v;
        inputs[u].push_back(v);
        inputs[v].push_back(u);
    }
    for(int node = 1;node < N + 1;node++)
    {
        if(check[node] == 1) continue;

        dfs(node);
        bridge++;
//        for(auto that:check) cout << that.first << ' ' << that.second << ' ';
//        cout << '\n';
    }
//    cout << bridge << ' ' << pass << '\n';
    cout << (bridge - 1) + (M - pass);

    return 0;
}