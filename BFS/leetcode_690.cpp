/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int startIdx = 0;
        queue<Employee*> q;
        map<int,Employee*> hashEmployees;
        
        int sumValue = 0;
        Employee* temp;
        
        for(int idx = 0;idx < employees.size();idx++)
        {
            hashEmployees[employees[idx]->id] = employees[idx];
        }
        
        q.push(hashEmployees[id]);
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            sumValue += temp->importance;
            if(temp->subordinates.empty()) continue;
            
            for(auto it:temp->subordinates)
            {
                q.push(hashEmployees[it]);    
            }
        }
        
        //cout << sumValue << endl;
        
        return sumValue;
    }
};