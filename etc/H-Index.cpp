#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(auto it:citations)
    {
        int idx = citations.end() - lower_bound(citations.begin(),citations.end(),it);
        if(it >= idx) {answer = idx; break;}
    }
    return answer;
}