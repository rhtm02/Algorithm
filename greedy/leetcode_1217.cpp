
#include <map>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        map<int,int> odd_even;
        odd_even[0] = 0;
        odd_even[1] = 0;
        int num = 0;
        for(auto it:position)
        {
            if(it%2 == 1) odd_even[1]++;
            else odd_even[0]++;
        }
        //cout << odd_even[0] << " " << odd_even[1] << endl;
        if(odd_even[0] > odd_even[1]) return odd_even[1];
        else return odd_even[0];
        return 0;
    }
};