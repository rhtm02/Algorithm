#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        vector<int> temp(strs[0].size(),0);
        vector<int> check;
        int cnt = 0;
        for(auto it: strs)
        {   
            for(int idx = 0;idx < it.size();idx++)
            {
                if(find(check.begin(),check.end(),idx)
                  != check.end()) continue;
                if(temp[idx] <= it[idx]) temp[idx] = it[idx];
                
                else
                {
                    check.push_back(idx);
                    cnt++;
                }
            }
            
            for(auto that:temp) cout << that << " ";
        }
        //cout << cnt << endl;
        return cnt;
    }
};