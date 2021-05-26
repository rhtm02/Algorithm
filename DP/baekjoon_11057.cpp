
#include <iostream>
#include <vector>
using namespace std;



int  main()
{
	int N;
	cin >> N;

	vector<vector<int>> table = { {1,1,1,1,1,1,1,1,1,1} };
	vector<int> val = { 10 };
	for (int row = 1; row < N; row++)
	{
		vector<int> temp;
		int sum = 0;
		for (int col = 0; col < 10; col++)
		{
			if (col == 0) temp.push_back(val[row - 1]%10007);

			else
			{
				int tempSum = 0;
				for (int i = col; i < 10; i++) tempSum += table[row - 1][i];
				temp.push_back(tempSum % 10007);
			}
			sum += (temp.back() % 10007);
		}
		table.push_back(temp);
		val.push_back(sum % 10007);
	}

	cout << val[N - 1];
	
}