using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int quotientBottles = (numBottles / numExchange);
        int remainBottles = (numBottles % numExchange);
        int sumBottles = numBottles + quotientBottles;
        
        int temp = 0;
        while(quotientBottles != 0)
        {
            temp = quotientBottles + remainBottles;
            quotientBottles = (temp / numExchange);
            remainBottles = (temp % numExchange);
            sumBottles += quotientBottles;
            //cout << sumBottles << endl;
        }
        return sumBottles;
    }

};