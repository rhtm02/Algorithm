#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
using namespace std;

bool compare(int a, int b){
    return a < b;
}



int T,N,M,value;


int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);


    cin >> T;

    while(T > 0){
        vector<int> note1;
        vector<int> note2;

        cin >> N;
        for(int i = 0;i < N;i++){
            cin >> value;
            note1.push_back(value);
        }

        cin >> M;
        for(int i = 0;i < M;i++){
            cin >> value;
            note2.push_back(value);
        }

        sort(note1.begin(),note1.end(),compare);


        for(auto it:note2){
            auto it2 = lower_bound(note1.begin(),note1.end(),it);
            if(it == *it2) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        T--;
    }
}