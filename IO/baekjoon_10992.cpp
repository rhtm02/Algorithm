#include <iostream>

using namespace std;
int main()
{
    int row = 0;
    int col = 0;
    int headIdx, tailIdx = 0;
    cin >> row;
    col = (2 * row) - 1;
    headIdx = row - 1;
    tailIdx = row - 1;
    for (int i = 0; i < row; i++)
    {
      
        for (int j = 0; j < col; j++)
        {
            if (headIdx == tailIdx)
            {
                if (j == headIdx) cout << "*";
                else if (j > headIdx) { cout << endl; break; }
                else cout << " ";
            }
            else
            {
                if (headIdx == 0)
                {
                    cout << "*";
                }
                else
                {
                    if ((j == headIdx) || (j == tailIdx)) cout << "*";
                    else if (j > tailIdx) { cout << endl; break; }
                    else cout << " ";
                }
            }
        }
        //if(i != (row - 1)) cout << endl;
        
        headIdx--;
        tailIdx++;
    }
    return 0;
}