#include <iostream>
#include <vector>
using namespace std;
int main() {
    string str;
    cin >> str;
    vector<char> stack;
    vector<char> term;
    int sum = 0;
    for(auto it = str.begin();it != str.end();it++)
    {
        if((*it == ')') && (stack.back() == '('))
        {
            vector<char> temp(stack.begin(),prev(stack.end()));
            stack = temp;
        }
        else
        {
            stack.push_back(*it);
            if (*it == '(') term.push_back(*it);
        }
        if((*it == ')') && (*prev(it)== '('))
        {
            sum += stack.size();
            sum += (term.size() - 1);
            term.clear();
        }

    }
    cout << sum;
}