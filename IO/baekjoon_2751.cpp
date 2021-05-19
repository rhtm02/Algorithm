#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  main()
{
	int inputNums; int temp;
	cin >> inputNums;
	vector<int> nums;
	for (int i = 0; i < inputNums; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != nums.end(); it++) cout << *it << "\n";
}