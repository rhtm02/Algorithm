#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int N;
	string cmd;
	int val;
	deque<int> dq;


	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if (cmd == "push_front")
		{
			cin >> val;
			dq.push_front(val);
		}
		else if (cmd == "push_back")
		{
			cin >> val;
			dq.push_back(val);
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty()) { printf("-1\n"); continue; }
			printf("%d\n", dq.front());
			dq.pop_front();
			
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty()) { printf("-1\n"); continue; }
			printf("%d\n", dq.back());
			dq.pop_back();
		}
		else if (cmd == "size")
		{
			printf("%d\n", dq.size());
		}
		else if (cmd == "empty")
		{
			if (dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (cmd == "front")
		{
			if (dq.empty()) { printf("-1\n"); continue; }
			else printf("%d\n",dq.front());
		}
		else if (cmd == "back")
		{
			if (dq.empty()) { printf("-1\n"); continue; }
			else printf("%d\n", dq.back());
		}
	}
}