
#include <iostream>
#include <vector>
using namespace std;



int  main()
{
	int N;
	vector<vector<int>> table = { {1,1,1,1,1,1,1,1,1},
								  {2,2,2,2,2,2,2,2,1} };
	vector<int> val = { 9,17 };
	
	cin >> N;
	for (int rowIdx = 2; rowIdx < N; rowIdx++)
	{	
		vector<int> row;
		long long sum = 0;
		for (int colIdx = 0; colIdx < 9; colIdx++)
		{
			int temp;
			if (colIdx == 0) temp = (table[rowIdx - 2][colIdx] + table[rowIdx - 1][colIdx + 1])%1000000000;
			else if(colIdx == 8) temp = (table[rowIdx - 1][colIdx - 1]) % 1000000000;
			else temp = (table[rowIdx - 1][colIdx - 1] + table[rowIdx - 1][colIdx + 1]) % 1000000000;
			row.push_back(temp);
			sum += temp % 1000000000;
		}
		table.push_back(row);
		val.push_back(sum % 1000000000);
	}

	cout << val[N - 1];
	
}