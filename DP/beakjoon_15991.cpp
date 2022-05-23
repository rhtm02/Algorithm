#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
using namespace std;

int N;

vector<long long> dp(100001);



int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;

    vector<int> inputs;

    for(int i = 0;i < N;i++){
        int idx;
        cin >> idx;
        inputs.push_back(idx);
    }

    int max = *max_element(inputs.begin(),inputs.end());

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    for(int i = 7;i <= max;i++){
        dp[i] = (dp[i - 6] + dp[i - 4] + dp[i - 2])/1000000009;
    }

    for(auto it:inputs) cout << dp[it] << '\n';
}