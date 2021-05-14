#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    for (auto it: new_id) 
    {
        char lowerChar = tolower(it);
        if(((lowerChar < 'a') || (lowerChar > 'z')) && (lowerChar != '.') 
           && (lowerChar != '_') && (lowerChar != '-') && ((lowerChar < '0') || (lowerChar > '9'))) continue;
        temp.push_back(lowerChar);
    }
    for(auto it = temp.begin();it != temp.end();it++)
    {
        if((*it == '.') && (answer.back() == '.')) continue;
        answer.push_back(*it);
    }
    
    if(answer[0] == '.') answer.erase(0,1);
    if(answer[answer.size() - 1] == '.') answer.pop_back();
    if(answer.size() == 0) answer.push_back('a');
    
    if(answer.size() < 3)
    {
        int answerSize = answer.size();
        char endChar = *(answer.end() - 1);
        while(answerSize < 3)
        {
            answer.push_back(endChar);
            answerSize++;
        }
    }
    if(answer.size() > 15)
    {
        answer = answer.substr(0,15);
    }


    if(answer[answer.size() - 1] == '.') answer.pop_back();

    cout << answer << endl;
    return answer;
}