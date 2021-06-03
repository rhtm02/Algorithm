#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	string cmd;
	int val;
	queue<int> q;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			scanf("%d", &val);
			q.push(val);
		}
		else if (cmd == "front")
		{
			if (q.empty()) { printf("-1\n"); continue; }
			printf("%d\n", q.front());
		}
		else if (cmd == "back")
		{
			if (q.empty()) { printf("-1\n"); continue; }
			printf("%d\n", q.back());
		}
		else if (cmd == "pop")
		{
			if (q.empty()) { printf("-1\n"); continue; }
			printf("%d\n", q.front());
			q.pop();
		}
		else if (cmd == "size")
		{
			printf("%d\n", q.size());
		}
		else if (cmd == "empty")
		{
			if (q.empty()) printf("1\n");
			else printf("0\n");
		}
	}
}