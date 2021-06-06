#include <iostream>
#include <list>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    char cmd;
    char val;
    int N;
    cin >> str;
    cin >> N;
    list<char> lst(str.begin(),str.end());
    auto ptr = lst.end();
    for(int i = 0;i < N;i++)
    {
        cin >> cmd;
        if(cmd == 'P')
        {
            cin >> val;
            ptr = next(lst.insert(ptr,val));
        }
        else if(cmd == 'L')
        {
            if(ptr == lst.begin()) continue;
            ptr = prev(ptr);
        }
        else if(cmd == 'D')
        {
            if(ptr == lst.end()) continue;
            ptr = next(ptr);
        }
        else if(cmd == 'B')
        {
            if(ptr == lst.begin()) continue;
            ptr = lst.erase(prev(ptr));
        }
        //for(auto it:lst) cout << it << ' ';
        //cout << '\n';
        //cout << *ptr << " val";
        //cout << '\n';
    }
    string output(lst.begin(),lst.end());
    cout << output;
}