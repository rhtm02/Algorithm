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
    if((N%2) == 1)
    {
        cout << 0;
        return 0;
    }
    vector<int> DP(N + 1);
    DP[2] = 3;
    DP[4] = 3*DP[2] + 2;
    for(int idx = 6;idx <= N;idx += 2)
    {
        DP[idx] = 3*DP[idx - 2];
        for(int temp = idx - 4;temp > 0;temp -= 2) DP[idx] += (2*DP[temp]);
        DP[idx] += 2;
    }
    cout << DP[N];
}