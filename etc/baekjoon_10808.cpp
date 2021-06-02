#include <iostream>
#include <map>
using namespace std;
int main() {
    string str;
    cin >> str;
    map<char,int> table;
    string s("abcdefghijklmnopqrstuvwxyz");
    for(auto it:s) table[it] =0;
    for(auto it = str.begin();it != str.end();it++)
    {
        table[*it]++;
    }
    for(auto it:s) cout << table[it] << ' ';
}