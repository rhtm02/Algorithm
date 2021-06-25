#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N1; int N2;
    cin >> N1; cin >> N2;
    map<int,vector<int>> DP;
    for(int i = 1;i <= N1;i++)
    {
        vector<int> temp(N2 + 1);
        temp[1] = 1;
        DP[i] = temp;
    }

    for(int sum = 1;sum <= N1;sum++)
    {
        vector<int> temp(N2 + 1);
        for(int choice = 2;choice <=N2;choice++)
        {
            for(int i = 1;i <= sum;i++) DP[sum][choice] = (DP[sum][choice] + DP[i][choice - 1]) % 1000000000;
            DP[sum][choice] = (DP[sum][choice] + 1) % 1000000000;
        }
    }
    cout << DP[N1][N2];
}