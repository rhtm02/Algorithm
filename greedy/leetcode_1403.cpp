#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        int numsSum = 0;
        int outputSum = 0;
        vector<int> output;
        sort(nums.begin(),nums.end(),compare);
        
        for(auto it:nums) numsSum+=it;
        
        for(int idx = 0;idx < nums.size();idx++)
        {
            outputSum += nums[idx];
            output.push_back(nums[idx]);
            if((numsSum - outputSum) < outputSum) break;
        }
        //cout << outputSum << endl;
        //for(auto it:output) cout << it << endl;
        
        
        return output;
    }
};