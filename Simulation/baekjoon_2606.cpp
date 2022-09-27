#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>

using namespace std;

int N,M;
vector<int> parents(101);
vector<pair<int,int> > edges;
int find(int node){
    if(parents[node] == node) return node;

    return parents[node] = find(parents[node]);
}

void union_node(int node1, int node2){

    int parent1 = find(node1);
    int parent2 = find(node2);

    if(parent1 == parent2) return;

    if(parent1 < parent2) parents[parent2] = parent1;
    else parents[parent1] = parent2;
}
int main() {
    cin >> N;
    cin >> M;

    for(int i = 1;i <= N;i++) parents[i] = i;

    for(int i = 0;i < M;i++){
        int s,d;
        cin >> s >> d;
        edges.push_back({s,d});
    }

    for(int i = 0;i < M;i++){
        union_node(edges[i].first,edges[i].second);
    }

    int ans = 0;
    for(int i = 2;i <= N;i++){
        if(find(i) == 1) ans++;
    }
    cout << ans;
}