#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

bool compare(pair<pair<int,int>,long long> a,pair<pair<int,int>,long long> b){
    return a.second < b.second;
}

int V,E;
long long ans = 0;
vector<int> roots(10001);

vector<pair<pair<int,int>,int>> inputs;

void init_roots(){
    for(int i = 1;i < 10001;i++){
        roots[i] = i;
    }
}

int find(int node){
    if(roots[node] == node) return node;

    return find(roots[node]);
}

void union_set(int node1, int node2){
    int _node1 = find(node1);
    int _node2 = find(node2);

    if(_node1 != _node2){
        if(_node1 > _node2) roots[_node1] = _node2;
        else roots[_node2] = _node1;
    }
}

void kruskal(){

    sort(inputs.begin(),inputs.end(),compare);

    for(auto it:inputs){
        int node1 = it.first.first;
        int node2 = it.first.second;

        if(find(node1) != find(node2)){
            union_set(node1,node2);
            ans += it.second;
        }
    }

}




int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> V >> E;

    for(int i = 0;i < E;i++){
        int a,b;
        int w;
        cin >> a >> b >> w;
        inputs.push_back({{a,b},w});
    }

    init_roots();
    kruskal();
    cout << ans;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> PAIR;

struct cmp{
    bool operator()(PAIR a, PAIR b){
        return a.second > b.second;
    }
};

int V,E;
long long ans = 0;

map<int,vector<PAIR>> inputs;
vector<int> nodes;

void prim(int start){
    priority_queue<PAIR,vector<PAIR>,cmp> pq;

    pq.push({start,0});

    while(!pq.empty()){
        int cur = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if(nodes[cur] == 1) continue;
        nodes[cur] = 1;
        ans += weight;

        for(auto it:inputs[cur]){
            if(nodes[it.first] == 1) continue;
            pq.push(it);
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> V >> E;
    nodes.resize(V + 1);
    int a,b;
    int w;
    int start;
    for(int i = 0;i < E;i++){
        cin >> a >> b >> w;
        inputs[a].push_back({b,w});
        inputs[b].push_back({a,w});
        start = a;
    }
    prim(start);
    cout << ans;

}