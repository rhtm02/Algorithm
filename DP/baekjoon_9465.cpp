#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;int N;
    cin >> T;
    for(int i = 0;i < T;i++)
    {
        cin >> N;
        vector<int> row1(N + 1);
        vector<int> row2(N + 1);
        vector<int> DP1(N + 1);
        vector<int> DP2(N + 1);
        for(int j = 1;j <= N;j++) cin >> row1[j];
        for(int j = 1;j <= N;j++) cin >> row2[j];
        DP1[1] = row1[1];
        DP2[1] = row2[1];
        DP2[2] = DP1[1] + row2[2];
        DP1[2] = DP2[1] + row1[2];
        for(int idx = 3;idx <= N;idx++)
        {
            DP1[idx] = max(DP2[idx - 1] + row1[idx],DP1[idx - 2] + row1[idx]);
            DP1[idx] = max(DP1[idx],DP2[idx - 2] + row1[idx]);
            DP2[idx] = max(DP1[idx - 1] + row2[idx],DP2[idx - 2] + row2[idx]);
            DP2[idx] = max(DP2[idx],DP1[idx - 2] + row2[idx]);
        }
        cout << max(DP1[N],DP2[N]) << '\n';
    }
}