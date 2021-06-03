#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string temp;

	int cnt = 0;
	unsigned long long sum = 0;
	getline(cin, s);
	for (auto it : s) 
	{
		
		if (it == ' ') 
		{ 
			cnt++;
			if (cnt == 2) { sum += stoull(temp); temp.clear(); }
		}
		else
		{
			temp.push_back(it);
		}
	}
	
	sum += stoull(temp); temp.clear();
	cout << sum;
	return 0;
}