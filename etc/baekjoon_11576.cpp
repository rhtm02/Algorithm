#include <iostream>
#include <deque>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int F; int P; int N;
	cin >> F; cin >> P; cin >> N;
	unsigned int val = 0;
	deque<int> ans;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		val += temp*(pow(F,N - i - 1));
	}
	while (true)
	{
		
		ans.push_front(val % P);
		if (val < P) break;
		val = val / P;
	}

	for (auto it : ans)cout << it << ' ';
}