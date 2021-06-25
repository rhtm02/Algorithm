#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; int T;
    cin >> T;
    for(int t = 0;t < T;t++)
    {
        cin >> N;
        deque<long long> DP(5);
        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 1;
        DP[3] = 2;
        DP[4] = 2;
        if(N <= 5)
        {
            cout << DP[N - 1] << '\n';
            continue;
        }
        for(int i = 6;i <= N;i++)
        {
            long long temp = DP[0] + DP[4];
            DP.push_back(temp);
            DP.pop_front();
        }
        cout << DP.back() << '\n';
    }
}