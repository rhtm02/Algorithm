#include <iostream>
#include <list>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int N1; int N2;
	for (int i = 0; i < N; i++)
	{
		cin >> N1; cin >> N2;
		int minVal = 0;
		int maxVal = 0;
		if (N1 > N2) maxVal = N1;
		else  maxVal = N2;
		int out2 = maxVal;
		while (1)
		{
			if (((maxVal % N1) == 0) && ((maxVal % N2) == 0)) break;
			maxVal += out2;
		}
		cout << maxVal << '\n';
	}
}