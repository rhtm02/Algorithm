#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

map<int,bool> node_check;
map<int,vector<pair<int,int>>> graph;
vector<vector<int>> ans;
int N,M,A,B,C;


void recursive(int node,int weight, vector<int> weights){
    weights.push_back(weight);
    if(node == B){
        int val = 0;
        for(auto it:weights) val += it;
        if(C >= val) ans.push_back(weights);
//        ans.push_back(weights);
        return;
    }

    for(auto it:graph[node]){
        if(node_check[it.first] == true) continue;
        node_check[node] = true;

        recursive(it.first,it.second,weights);
        node_check[node] = false;
    }

}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; cin >> M, cin >> A, cin >> B, cin >> C;

    for(int i = 0;i < M;i++){
        int from,to,weight;
        cin >> from;
        cin >> to;
        cin >> weight;
        graph[from].push_back(pair(to,weight));
        graph[to].push_back(pair(from,weight));
        node_check[from] = false;
        node_check[to] = false;
    }


    vector<int> temp;
    recursive(A,0,temp);

    if(ans.empty()){
        cout << -1;
        return 0;
    }

    int val = 10001;
    for(auto it:ans){
        auto temp = *max_element(it.begin(),it.end());
        val = min(val,temp);
    }

    cout << val;

    return 0;
}