#include <iostream>

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int r_cnt = 0;
        int l_cnt = 0;
        
        for(auto it : s)
        {
            if(it == 'R') r_cnt++;
            else l_cnt++;
            
            if(r_cnt == l_cnt) cnt++;
        }
        
        return cnt;
    }
};