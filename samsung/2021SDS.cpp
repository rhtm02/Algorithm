#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; int T;
    cin >> T;
    for(int c = 0;c < T;c++)
    {
        cin >> N;
        int ans = 0;
        deque<int> src(N);
        deque<int> dest;
        for (int i = 0; i < N; i++) cin >> src[i];
        if(src.size() == 1)
        {
            ans += src.front();
            cout << '#' << c + 1 << ' ' << ans << '\n';
            continue;
        }
        while (1) {

            sort(src.begin(), src.end());
            ans += src[1];
            for (int idx = 0; idx < 2; idx++) {
                dest.push_back(src.front());
                src.pop_front();
            }
            if (src.size() == 0) break;
            sort(dest.begin(), dest.end());
            src.push_front(dest.front());
            ans += dest.front();
            dest.pop_front();
            ans += src.back();
            for (int idx = 0; idx < 2; idx++) {
                dest.push_back(src.back());
                src.pop_back();
            }
            sort(dest.begin(), dest.end());
            if (src.empty()) break;
            ans += dest.front();
            src.push_front(dest.front());
            dest.pop_front();
        }
        cout << '#' << c + 1 << ' ' << ans << '\n';
    }
}
