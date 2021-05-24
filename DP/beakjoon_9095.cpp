#include <iostream>
#include <vector>

using namespace std;


int  main()
{
	int N;
	cin >> N;
	vector<int> inputArr,sorted;
	vector<int> arr;
	//0,1,2,3,4,5,6
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(4);
	for (int i = 0;i < N; i++) {int temp; cin >> temp; inputArr.push_back(temp);}
	while (arr.size() <= 11)
	{
		arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2] + arr[arr.size() - 3]);
	}
	for (auto it : inputArr) cout << arr[it] << '\n';
	return 0;
}