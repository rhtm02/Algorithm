#include <iostream>
#include <string>
using namespace std;

int n; // 부등호 갯수
char b[9];
bool c[10] = { false, };
string mn, mx;

bool possible(int i, int j, char k) {
    if (k == '<')return i < j;
    if (k == '>')return i > j;
    return true;
}

void solve(int cnt, string s){
    if (cnt == n + 1) {
        if (!mn.size()) {
            mn = s;
        }
        else mx = s;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (c[i]) continue;
        if (cnt == 0 || possible(s[cnt - 1], i+'0', b[cnt - 1])) {
            c[i] = true;
            solve(cnt+1, s+to_string(i));
            c[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve(0, "");
    cout << mx << '\n';
    cout << mn << '\n';
    return 0;
}