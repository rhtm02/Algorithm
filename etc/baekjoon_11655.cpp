#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	getline(cin, s);

	for (auto it : s)
	{
		if ((it >= 'A') && (it <= 'Z'))
		{
			cout << (char)(((it - 'A') + 13) % 26 + (int)'A');
		}
		else if ((it >= 'a') && (it <= 'z'))
		{
			cout << (char)(((it - 'a') + 13) % 26 + (int)'a');
		}
		else cout << it;
	}
}