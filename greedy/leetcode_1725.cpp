#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> LenCnt;
        int length = 0;
        int width = 0;
        int maxlen = 0;
        int temp = 0;
        for(auto it:rectangles)
        {
            length = it[0];
            width = it[1];
            
            if(length >= width) 
            {
                temp = width;
            }
            else 
            {
                temp = length;
            }
            if(maxlen < temp) maxlen = temp;
            
            if(maxlen == temp) LenCnt[maxlen]++;
        }
        
        return LenCnt[maxlen];
    }
};