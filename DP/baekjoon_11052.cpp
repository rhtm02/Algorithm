#include <iostream>
#include <vector>
#include <cmath>
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
    DP[1] = values[1];
    for(int i = 2;i <= N;i++)
    {
        DP[i] = values[i];
        for(int temp = i;temp > 0;temp--)
        {
            DP[i] = max(DP[i - temp] + values[temp],DP[i]);
        }
    }
    cout << DP[N];
}