#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

typedef unsigned long long ull;
using namespace std;

int N,M;
vector<ull> inputs;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> M; cin >> N;

    for(int i = 0;i < N;i++){
        int temp;
        cin >> temp;
        inputs.push_back(temp);
    }
    sort(inputs.begin(),inputs.end());
    ull left = 1;
    ull right = inputs[N - 1];

    ull val;
    ull ans = 0;
    while(left <= right) {
        val = (left + right) / 2;
        ull nums = 0;
        for(auto it:inputs){
            nums += (it/val);
        }
        if(nums >= M){
            left = val + 1;
            ans = val;
        }
        else{
            right = val - 1;
        }
    }
    cout << ans;
    return 0;
}