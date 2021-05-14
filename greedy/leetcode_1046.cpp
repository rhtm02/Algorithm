#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a >= b;
}

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) return 0;
        else if(stones.size() == 1) return stones[0];
    
        sort(stones.begin(),stones.end(),compare);

        vector<int> subvector;
        if(stones[0] == stones[1]) 
        {
            for(int idx = 2;idx < stones.size();idx++) subvector.push_back(stones[idx]);
            return lastStoneWeight(subvector);
        }
        else
        {
            //if(stones.size() == 2) return 2;
            subvector.push_back(stones[0] - stones[1]);
            for(int idx = 2;idx < stones.size();idx++) subvector.push_back(stones[idx]);
            return lastStoneWeight(subvector);
        }
             
    }
};