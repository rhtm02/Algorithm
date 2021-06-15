#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A; int B; int C;
	cin >> A;
	cin >> B;
	cin >> C;
	cout << (A + B) % C << '\n';
	cout << ((A % C) + (B % C)) % C << '\n';
	cout << (A*B) % C << '\n';
	cout << ((A % C)*(B % C)) % C << '\n';
}