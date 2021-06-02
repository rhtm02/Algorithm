#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	string str;
	for (int i = 0; i < N; i++)
	{
		vector<char> stack;
		cin >> str;
		for (auto it : str)
		{
			if (stack.empty()) { stack.push_back(it); continue; }
			else if ((stack[0] == '(') && (it == ')'))
			{
				vector<char> temp(stack.begin(), prev(stack.end()));
				stack = temp;
				continue;
			}
			else stack.push_back(it);
		}
		if (stack.empty()) printf("YES\n");
		else printf("NO\n");
	}
}