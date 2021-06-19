#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; int src; int dest; int len; string filter;
    cin >> T;
    for(int i = 0; i < T;i++)
    {
        cin >> src; cin >> dest; cin >> len;
        cin >> filter; string revFilter(filter.rbegin(),filter.rend());
        int filterInt = 0; int revFilterInt = 0;
        int gap = 0;
        if(dest < src) gap = dest - src;
        else gap = src - dest;
        int srcSize = 0; set<int> filters;int ans = 0;
        while(src > 0) {srcSize++; src /= 10;}
        for(int idx = 0;idx < len;idx++)
        {
            if(filter[idx] == '+') filterInt += pow(10,len - 1 -idx);
            else if(filter[idx] == '-') filterInt += (-pow(10,len - 1 -idx));
            if(revFilter[idx] == '+') revFilterInt += pow(10,len - 1 -idx);
            else if(revFilter[idx] == '-') revFilterInt += (-pow(10,len - 1 -idx));
        }
        if((gap % filterInt) != 0) {cout << '#' << i + 1 << " -1\n"; continue;}
        for(int i = 0;i <= (srcSize - len);i++)
        {
            int temp = pow(10,i);
            filters.insert(temp * filterInt);
            filters.insert(temp * revFilterInt);
        }

        while(gap != 0)
        {
            auto it = filters.lower_bound(gap);
            if(it != prev(filters.end())) {
                auto temp = next(it);
                if (abs(gap - *it) > abs(gap - *temp)) it = temp;
            }
            gap += (-*it);
            ans++;
        }
        cout << '#' << i + 1 << ' ' << ans << '\n';
    }
}