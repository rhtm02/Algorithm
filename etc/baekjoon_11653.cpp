#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int N2 = 2;
	while (true)
	{
		if (N == 1) break;
		if ((N % N2) == 0)
		{
			cout << N2 << '\n';
			N /= N2;
		}
		else
		{
			N2 += 1;
		}
	}
}