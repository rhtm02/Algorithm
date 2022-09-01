//
// Created by 이형준 on 2022/08/15.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<climits>
#include<string>
using namespace std;

vector<vector<int>> image;
vector<vector<int>> row_sum;
int R,C,cnt,r_1,c_1,r_2,c_2;

void visualize(){
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++) cout << image[i][j] << ' ';
        cout << '\n';
    }
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++) cout << row_sum[i][j] << ' ';
        cout << '\n';
    }
}

void cal_mean(){
    int val = 0;
    for(int i = r_1 - 1;i <= r_2 - 1;i++){
        val += (row_sum[i][c_2 - 1] - row_sum[i][c_2 - 1 - (c_2 - c_1 + 1)]);
    }
    cout << val/((r_2 - r_1 +1)*(c_2 - c_1 + 1)) << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin >> R; cin >> C; cin >> cnt;

    for(int i = 0;i < R;i++){
        vector<int> temp;
        vector<int> sums;
        int sum = 0;
        int v;
        for(int j = 0;j < C;j++){
            cin >> v;
            sum += v;
            temp.push_back(v);
            sums.push_back(sum);
        }
        image.push_back(temp);
        row_sum.push_back(sums);
    }


    for(int i = 0;i < cnt;i++){
        cin >> r_1; cin >> c_1; cin >> r_2; cin >> c_2;
        cal_mean();
    }
//    visualize();

}