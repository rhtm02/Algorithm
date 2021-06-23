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
    vector<int> DP(N + 1);
    DP[1] = 1;
    for(int idx = 2;idx <= N;idx++)
    {
        int temp = (int)sqrt(idx);
        if(idx == pow(temp,2)) DP[idx] = 1;
        else
        {
            DP[idx] = 1 + DP[idx - pow(temp,2)];
            for(int i = temp - 1;i >= 1;i--) DP[idx] = min(DP[idx],DP[pow(i,2)] + DP[idx - pow(i,2)]);
        }
    }
    cout << DP[N];
}