#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> values(N + 1);
    vector<int> DP(N + 1);
    for(int i = 1;i <= N;i++) cin >> values[i];
    DP[1] = 1;
    int ans = 1;
    for(int idx = 2;idx <= N;idx++)
    {
        int val = 0;
        for(int temp = idx - 1;temp > 0;temp--)
        {
            if(values[temp] < values[idx]) val = max(val,DP[temp]);
        }
        DP[idx] = val + 1;
        ans = max(DP[idx],ans);
    }
    cout << ans;
}
