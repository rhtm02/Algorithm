#include <iostream>
#include <list>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N1; int N2;
	cin >> N1; cin >> N2;
	int minVal = 0;
	int maxVal = 0;
	if (N1 > N2) { minVal = N2; maxVal = N1; }
	else { minVal = N1; maxVal = N2; }
	int out;
	for (int i = 1; i <= minVal; i++)
	{
		if (((N1 % i) == 0) && ((N2 % i) == 0)) out = i;
	}
	cout << out << '\n';
	int out2 = maxVal;
	while (1)
	{
		if (((maxVal % N1) == 0)&& ((maxVal % N2) == 0)) break;
		maxVal += out2;
	}
	cout << maxVal;
}