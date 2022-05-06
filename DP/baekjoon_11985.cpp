#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M;
long long K;
vector<long long> oranges(20001);
vector<long long> dp(20001);

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N; cin >> M; cin >> K;

    for(int i = 1;i <= N;i++) {
        long long temp;
        cin >> temp;
        oranges[i] = temp;
        dp[i] = i*K;
    }

    for(int i = 1;i <= N;i++){
        long long max_val = oranges[i];
        long long min_val = oranges[i];
        for(int j = 0;j < min(i,M);j++){
            min_val = min(min_val,oranges[i - j]);
            max_val = max(max_val,oranges[i - j]);
//            vector<long long> temp(oranges.begin() + 1 + i - j,oranges.begin() + 1 + i);
//            long long max_val = *max_element(temp.begin(),temp.end());
//            long long min_val = *min_element(temp.begin(),temp.end());
            dp[i] = min(dp[i],dp[i - j - 1] + K + (j + 1)*(max_val - min_val));

        }
    }

    cout << dp[N];
    return 0;
}