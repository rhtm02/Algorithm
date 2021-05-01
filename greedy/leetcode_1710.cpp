
#include <algorithm>
using namespace std;


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),this->compare);
        
        int sum = 0;
        for(auto it:boxTypes)
        {
            if(truckSize <= it[0] ) 
            {
                sum += (truckSize * it[1]);
                //cout << truckSize << " " << sum << endl;
                break;
            }
            truckSize -= it[0];
            sum += (it[0] * it[1]);
            //cout << truckSize << " " << sum << endl;
        }

        cout<<sum<<endl;
        
        return sum;
    }
    
    static bool compare(vector<int> a,vector<int> b)
    {
        return a[1] > b[1];
    }
};