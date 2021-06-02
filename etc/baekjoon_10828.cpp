#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	string cmd;
	int val;
	vector<int> stack;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		//cout << cmd << ' ' << val << '\n';
		if (cmd == "push")
		{
			scanf("%d", &val);
			stack.push_back(val);
		}
		else if (cmd == "top")
		{
			if (stack.empty()) { printf("-1\n"); continue; }
			printf("%d\n", stack.back());
		}
		else if (cmd == "pop")
		{
			if (stack.empty()) { printf("-1\n"); continue; }
			printf("%d\n", stack.back());
			vector<int> temp(stack.begin(), prev(stack.end()));
			stack = temp;
		}
		else if (cmd == "size")
		{
			printf("%d\n", stack.size());
		}
		else if (cmd == "empty")
		{
			if (stack.empty()) printf("1\n");
			else printf("0\n");
		}
	}
}