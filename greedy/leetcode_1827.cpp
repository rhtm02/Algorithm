#include <iostream>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int temp= 0;
        for(int idx = 1;idx < nums.size();idx++)
        {
            temp = nums[idx];
            if(nums[idx - 1] >= nums[idx]) nums[idx] += (nums[idx - 1] - nums[idx] + 1);
            cnt += (nums[idx] - temp);
        }
        
        return cnt;
    }
};