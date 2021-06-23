#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> DP(N + 1);
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    for(int i = 4; i <= N;i++)
    {
        if(((i%3) == 0) && ((i%2) != 0))
        {
            DP[i] = min(DP[i - 1] + 1,DP[i/3] + 1);
        }
        else if(((i%2) == 0) && ((i%3) != 0))
        {
            DP[i] = min(DP[i - 1] + 1,DP[i/2] + 1);
        }
        else if(((i%2) == 0) && ((i%3) == 0))
        {
            int temp = min(DP[i - 1] + 1,DP[i/2] + 1);
            temp = min(temp,DP[i/3] + 1);
            DP[i] = temp;
        }
        else
        {
            DP[i] = DP[i - 1] + 1;
        }
    }
    cout << DP[N];
}