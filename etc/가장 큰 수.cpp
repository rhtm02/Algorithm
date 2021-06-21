#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b)
{
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> values;
    for(auto it:numbers) values.push_back(to_string(it));    
    sort(values.begin(),values.end(),compare);

    for(auto it:values) 
    {
        answer += it; 
        if(answer == "0") break;
    }

    return answer;
}