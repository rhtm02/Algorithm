using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int quotient = n/7;
        int remainder = n%7;
        int sum = 0;
        for(int i = 1;i <= quotient;i++)
        {
            sum += (7 * i + 21);
        }
        sum += (((2 * quotient + 1 + remainder)*remainder)/2);
        
        return sum;
    }
};