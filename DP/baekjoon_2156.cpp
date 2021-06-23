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
    for(int i = 1;i <= N;i++) cin >> values[i];

    vector<int> DP(N + 1);
    DP[1] = values[1];
    DP[2] = values[2] + values[1];
    DP[3] = max(values[1] + values[3],values[2] + values[3]);
    DP[3] = max(DP[3],values[1] + values[2]);
    for(int i = 4;i <= N;i++)
    {
        DP[i] = max(DP[i - 1],DP[i - 2] + values[i]);
        DP[i] = max(DP[i],DP[i - 3] + values[i] + values[i - 1]);
    }

    cout << DP[N];
}
