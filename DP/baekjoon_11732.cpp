#include <iostream>
using namespace std;

int arr[1001] = { 0, };

int  main()
{
	int N;
	cin >> N;
	
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= 1001; i++) arr[i] = ((arr[i - 1] + 2 * arr[i - 2])%10'007);
	cout << arr[N] % 10'007;

	return 0;
}