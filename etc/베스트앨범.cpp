
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

bool compare1(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}
bool compare2(pair<string,int> a,pair<string,int> b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    pair<int,int> id_plays;
    map<string,vector<pair<int,int>>> table;
    map<string,int> temp;
    for(int id = 0;id < genres.size();id++)
    {
        string str(genres[id]);
        id_plays.first = plays[id];
        id_plays.second = id;
        table[str].push_back(id_plays);
        temp[str] += plays[id];
    }
    vector<pair<string,int>> genTable(temp.begin(),temp.end());
    sort(genTable.begin(),genTable.end(),compare2);

    for(int i = 0;i < genTable.size();i++)
    {
        string key = genTable[i].first;
        sort(table[key].begin(),table[key].end(),compare1);

        if(table[key].size() < 2) {answer.push_back(table[key][0].second); continue;}

        for(int idx = 0;idx < 2;idx++)
        {
            answer.push_back(table[key][idx].second);
        }
    }

    /*
    for(auto it:table) 
    {
        sort(it.second.begin(),it.second.end(),compare1);
        cout << it.first;
        for(auto vec:it.second) cout << ' ' << vec.first << ' ' << vec.second;
        cout <<'\n';
    }
    */  
    return answer;
}
