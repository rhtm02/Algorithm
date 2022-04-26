//
// Created by 이형준 on 2022/04/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

void debug(map<int,vector<int>> &inputs, set<int> &nodes){
    cout << "size : " << inputs.size() << '\n';
    for(auto it:nodes){
        cout << it << " : ";
        for(auto it2:inputs[it]) cout << it2 << ' ';
        cout << '\n';
    }
}

int bfs(map<int,vector<int>> &inputs,int root){
    int ans = 0;
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans++;
        if(inputs[node].empty()) continue;
        for(auto it:inputs[node]) q.push(it);

    }
    return ans;
}

bool isTree(map<int,vector<int>> &inputs, set<int> &nodes, map<int,int> &check){
//    cout << "Node size : " << nodes.size() << '\n';
    if(inputs.size() == 0) return true;
    for(auto it:nodes){
//        if (inputs[it].empty()) continue;
        for(auto it2:inputs[it]){
            check[it2] += 1;
        }
    }
    int value = 0;
    int root = 0;
    for(auto it:nodes){
        value += check[it];
        if(check[it] == 0) root = it;
    }
//    cout << nodes.size() << ' ' << value << '\n';
    if (nodes.size() - 1 != value) return false;
    else {
//        cout << "root : " << root << '\n';
        int num = bfs(inputs,root);
        if(num == nodes.size()) return true;
        else return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int,vector<int>> graph;
    map<int,int> check;
    set<int> nodes;

    int u = 1; int v = 1; int N = 1;
    while (u >= 0 && v >= 0){
        cin >> u; cin >> v;
        if(u == 0 && v == 0) {
//            debug(graph,nodes);
            bool ans = isTree(graph,nodes,check);
            if(ans) cout << "Case " << N <<" is a tree.\n";
            else cout << "Case " << N <<" is not a tree.\n";
            graph.clear();
            nodes.clear();
            check.clear();
            N++;
            continue;
        }
        else if(u < 0 && v < 0) break;
        nodes.insert(u);
        nodes.insert(v);
        for(auto it:nodes) check[it] = 0;
        graph[u].push_back(v);
    }

    return 0;
}
