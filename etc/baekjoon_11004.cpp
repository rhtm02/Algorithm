#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
	return a < b;
}


int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	vector<int> values(N);
	for (int i = 0; i < N; i++) scanf("%d", &values[i]);
	sort(values.begin(), values.end(), compare);
	printf("%d", values[K - 1]);
}