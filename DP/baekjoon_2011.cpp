#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    cin >> N;
    if(N.size() == 0) {cout << 0; return 0;}
    if(N[0] == '0') {cout << 0; return 0;}
    else if((N.size() == 1) && (N[0] != '0')) {cout << 1; return 0;}
    vector<int> arr(N.size() + 1);
    vector<int> DP(N.size() + 1);
    for(int idx = 1;idx <= N.size();idx++) arr[idx] = N[idx - 1] - 48;
    DP[1] = 1;
    if(arr[2] != 0) DP[2]++;
    if((((10*arr[1] + arr[2]) <= 26) && ((10*arr[1] + arr[2]) >= 1)) && (arr[1] != 0)) DP[2]++;
    for(int i = 3;i <= N.size();i++)
    {

        if(arr[i] == 0) DP[i] = 0;
        else DP[i] = (DP[i] + DP[i - 1]) % 1000000;

        if((((10*arr[i - 1] + arr[i]) < 1) || ((10*arr[i - 1] + arr[i]) > 26)) || (arr[i - 1] == 0)) DP[i] += 0;
        else DP[i] = (DP[i] + DP[i - 2]) % 1000000;
    }
    cout << DP[N.size()];
}
