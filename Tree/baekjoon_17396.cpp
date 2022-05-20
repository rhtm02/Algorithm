#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int, long long> PAIR;

int N, M;

vector<int> nodes;
vector<long long> cost;

map<int,vector<PAIR>> graph;



long long ans = -1;


struct cmp {
    bool operator()(PAIR a,PAIR b) {
        return a.second > b.second;
    }
};


void path_find() {
    priority_queue < PAIR, vector<PAIR>, cmp> pq;

    pq.push({ 0,0 });
    cost[0] = 0;
    while (!pq.empty()) {
        PAIR top = pq.top();
        pq.pop();
        int node = top.first;
        long long weight = top.second;
        if(cost[node] < weight) continue;
        nodes[node] = 1;

        for(auto it:graph[node]){
            if((nodes[it.first] == 0) && (cost[it.first] > cost[node] + it.second))
            {
                cost[it.first] = cost[node] + it.second;
                pq.push({it.first,cost[it.first]});
            }
        }

    }
}




int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        if(i == N -1) {
            nodes.push_back(0);
        }
        else nodes.push_back(c);

        cost.push_back(LONG_LONG_MAX);
    }

    for (int i = 0; i < M; i++) {
        int f, t;
        long long w;
        cin >> f >> t >> w;
        graph[f].push_back({ t,w });
        graph[t].push_back({ f,w });
    }

    path_find();

    if(cost[N - 1] == LONG_LONG_MAX) cout << -1;
    else cout << cost[N - 1];
}