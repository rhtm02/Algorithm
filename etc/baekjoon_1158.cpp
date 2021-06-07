#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int IDX;
	cin >> N; cin >> IDX;
	vector<int> values,outputs;
	for (int i = 0; i < N; i++) values.push_back(i + 1);
	int idx = (IDX % values.size());
	
	
	while (!values.empty())
	{
		int idx = (IDX % values.size());
		vector<int> left(values.begin(), values.begin() + idx);
		vector<int> right(values.begin() + idx,values.end());
		for (auto it : left) right.push_back(it);
		outputs.push_back(right[right.size() - 1]);
		//cout << right[right.size() - 1];
		vector<int> temp(right.begin(), prev(right.end()));
		//cout << "##\n";
		values = temp;
	}
	
	cout << '<';
	for (auto it = outputs.begin(); it != prev(outputs.end()); it++) cout << *it << ", ";
	cout << outputs[outputs.size() - 1] << '>';
}