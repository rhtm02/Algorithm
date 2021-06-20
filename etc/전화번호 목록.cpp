#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    //for(auto it:phone_book) cout << it << ' ';
    //cout << '\n';
    for(auto it = phone_book.begin();it != phone_book.end();it++)
    {
        if(next(it) == phone_book.end()) break;
        auto temp = upper_bound(next(it),phone_book.end(),*it);
        if(*it == (*temp).substr(0,(*it).size())) {answer = false; break;}
        //cout << *it << ' ' << *temp << " \n";
    }
    return answer;
}