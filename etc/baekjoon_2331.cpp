#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P; int N;
    cin >> N; cin >> P;
    map<int,int> table;
    table[N]++;
    while(table[N] != 3)
    {
        int temp = 0;
        string str = to_string(N);
        for(int idx = 0;idx < str.size();idx++) temp += pow((str[idx] - '1' + 1),P);
        table[temp]++;
        N = temp;
    }
    int ans = 0;
    for(auto it:table)
    {
        if(it.second == 1) ans++;
    }
    cout << ans;
}