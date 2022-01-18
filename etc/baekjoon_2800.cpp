//
// Created by 이형준 on 2022/01/19.
//
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    stack<int> s;
    vector<pair<int,int>> v;
    vector<string> ans;
    for(int idx = 0;idx < str.size();idx++)
    {
        if(str[idx] == '(') s.push(idx);
        else if(str[idx] == ')')
        {
            int idx_ = s.top();
            s.pop();
            v.push_back(pair(idx_,idx));
        }
    }

    for(int i = 0;i < pow(2,v.size()) - 1;i++)
    {
        string temp = "";
        vector<int> bin;
        int quotient = i;

        while(quotient > 0) {
            int remain = quotient % 2;
            quotient /= 2;
            bin.push_back(remain);
        }
        int k = v.size() - bin.size();
        for(int j = 0;j < k;j++) bin.push_back(0);
//        for(auto it:bin) cout << it;

        for(int j = 0;j < str.size();j++)
        {
            vector<int> indxes;
            for(int idx = 0;idx < v.size();idx++)
            {
                if(bin[idx] == 0) {
                    indxes.push_back(v[idx].first);
                    indxes.push_back(v[idx].second);
                }
            }

            auto it = find(indxes.begin(),indxes.end(),j);
            if(it == indxes.end()) temp += str[j];
        }
        auto it = find(ans.begin(),ans.end(),temp);
        if (it == ans.end()) ans.push_back(temp);

    }

    sort(ans.begin(),ans.end());
    for(auto it:ans) cout << it << '\n';

    return 0;
}
