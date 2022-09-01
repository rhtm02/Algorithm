#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int,int> PAIR;

int N,M,S,E;

vector<pair<int,PAIR>> inputs;
vector<int> parents;
vector<int> cost;
map<int,vector<PAIR>> tree;
map<int,bool> nodes;
bool compare(pair<int,PAIR> a, pair<int,PAIR> b){
    return a.second.second > b.second.second;
}


int find(int node){
    if(parents[node] == node) return node;

    return find(parents[node]);
}

void union_set(int a,int b){
    int node1 = find(a);
    int node2 = find(b);

    if(node1 > node2) parents[node1] = node2;
    else parents[node2] = node1;
}

void kruskal(){

    sort(inputs.begin(),inputs.end(),compare);

    for(int i = 0;i <= N;i++) parents.push_back(i);

    for(auto it:inputs){
        if(find(it.first) == find(it.second.first)) continue;
        union_set(it.first,it.second.first);
        tree[it.first].push_back({it.second.first,it.second.second});
        tree[it.second.first].push_back({it.first,it.second.second});
    }

}

void bfs(){
    for(int i = 0;i <= N;i++) cost.push_back(INT_MAX);

    queue<int> q;
    q.push(S);
//    cost[S] = 0;

    while(!q.empty()){
        int cur_node = q.front();
        q.pop();
        if(nodes[cur_node] == true) continue;
        nodes[cur_node] = true;
        if(cur_node == E) break;

        for(auto it:tree[cur_node]){
            cost[it.first] = min(cost[it.first],it.second);
            cost[it.first] = min(cost[cur_node],cost[it.first]);
            q.push(it.first);
        }
    }

}



int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> S >> E;

    for(int i = 0;i < M;i++){
        int h1,h2,w;
        cin >> h1 >> h2 >> w;
        inputs.push_back({h1,{h2,w}});
        inputs.push_back({h2,{h1,w}});
        nodes[h1] = false;
        nodes[h2] = false;
    }

    kruskal();
    bfs();

    if(cost[E] == INT_MAX) cout << 0;
    else cout << cost[E];
//    for(auto it:tree){
//        cout << it.first << " : ";
//        for(auto it2:it.second) cout << it2.first << ' ' << it2.second << ' ';
//        cout << '\n';
//    }


}