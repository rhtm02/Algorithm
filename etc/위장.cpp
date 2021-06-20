#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> table;
    for(auto it:clothes) {table[it[1]]++;}
    int combination = (*table.begin()).second + 1;
    for(auto it = next(table.begin());it != table.end();it++) 
    {
        combination *= ((*it).second + 1);
    }
    answer = combination - 1;

    return answer;
}