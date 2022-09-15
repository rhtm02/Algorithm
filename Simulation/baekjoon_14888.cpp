#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include<set>
using namespace std;

int N;
vector<int> numbers;
map<char, int> operators;
map<char, string> graph = { {'+',"+-*/"},{'-',"+-*/"},{'*',"+-*/"},{'/',"+-*/"} };
vector<long long> answers;
set<string> opers;



void recursive(string temp, char key) {
    temp.push_back(key);
    if (temp.size() == (N - 1)) {
        opers.insert(temp);
        return;
    }
    for (auto it : graph[key]) {
        if (operators[it] == 0) continue;
        operators[it]--;
        recursive(temp, it);
        operators[it]++;
        
    }
    return;
}


int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        numbers.push_back(val);
    }
    
    for (int i = 0; i < 4; i++) {
        int cnt;
        cin >> cnt;
        if (i == 0) operators['+'] += cnt;
        else if (i == 1) operators['-'] += cnt;
        else if (i == 2) operators['*'] += cnt;
        else operators['/'] += cnt;
    }

    for (auto it : "+-*/") {
        if (operators[it] == 0) continue;
        operators[it]--;
        recursive("", it);
        operators[it]++;
    }
    
    for (auto it : opers) {
        long long val = numbers[0];
        for (int idx = 0; idx < N - 1; idx++) {
            if (it[idx] == '+') {
                val += numbers[idx + 1];
            }
            else if (it[idx] == '-') {
                val -= numbers[idx + 1];
            }
            else if (it[idx] == '*') {
                val *= numbers[idx + 1];
            }
            else {
                val /= numbers[idx + 1];
            }
        }
        answers.push_back(val);
    }
    sort(answers.begin(), answers.end());
    cout << answers[answers.size() - 1] << '\n' << answers[0];
}