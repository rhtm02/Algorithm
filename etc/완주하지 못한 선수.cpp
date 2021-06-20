#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    vector<string>::iterator rightParticipant = participant.begin();
    vector<string>::iterator leftParticipant = prev(participant.end());
    vector<string>::iterator rightCompletion = completion.begin();
    vector<string>::iterator leftCompletion = prev(completion.end());
    while(leftCompletion != rightCompletion)
    {
        if(*rightParticipant != *rightCompletion) {answer = *rightParticipant; break;}
        if(*leftParticipant != *leftCompletion) {answer = *leftParticipant; break;}
        rightParticipant++; rightCompletion++;
        leftParticipant--; leftCompletion--;
        answer = *rightParticipant;
    }

    return answer;
}