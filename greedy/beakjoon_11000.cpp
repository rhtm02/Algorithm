#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int,int> PAIR;

int N,S,T;

vector<PAIR> inputs;

bool compare(PAIR a,PAIR b){
    return a.first < b.first;
}

struct cmp{
    bool operator()(int a,int b){
        return a > b;
    }
};

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;

    for(int i = 0;i < N;i++){
        cin >> S >> T;
        inputs.push_back({S,T});
    }

    sort(inputs.begin(),inputs.end(),compare);

    priority_queue<int,vector<int>,cmp> pq;
    pq.push(inputs[0].second);

    vector<PAIR> temp(inputs.begin() + 1,inputs.end());

    priority_queue<int,vector<int>,cmp> p;


    for(auto it:temp){
        if(it.first >= pq.top()) {
            pq.pop();
            pq.push(it.second);
        }
        else {
            pq.push(it.second);
        }
    }

    cout << pq.size();
}