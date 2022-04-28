#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if(N < 100) cout << N << '\n';

    else{
//        cout << N / 100 << '\n';
//        cout << N % 10 << '\n';
        int K_100 = N / 100;
        int K_1 = N % 10;
        int ans = 99 + 5*(K_100 - 1);

        for(int i = 0;i < 10;i++){
            float K; int K_10;
            K = (float)((K_100 + i) % 2);
            K_10 = ((K_100 + i) / 2);
            if(K == 0) {
                int val = 100 * K_100 + 10 * (int) K_10 + i;
                if (val <= N) ans++;
            }
        }
        cout << ans;
    }

    return 0;
}
