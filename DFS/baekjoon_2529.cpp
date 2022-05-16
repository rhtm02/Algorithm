#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<char> inputs;
map<int,bool> node_check;
vector<string> ans;
int K;



void recursive(int k,string s){
    if(k == K){
        ans.push_back(s);
        return;
    }

    for(int i = 0;i < 10;i++){
        if(node_check[i] == true) continue;
        node_check[i] = true;
        if(s.empty()) recursive(k,s + to_string(i));
        else{
            if(inputs[k] == '>'){
                if((s.back() - '0') > i) recursive(k + 1,s + to_string(i));
            }
            else{
                if((s.back() - '0') < i) recursive(k + 1,s + to_string(i));
            }
        }
        node_check[i] = false;
    }



}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> K;

    for(int i = 0;i < K;i++){
        char temp;
        cin >> temp;
        inputs.push_back(temp);
    }

    for(int i = 0;i < 10;i++) node_check[i] = false;

    recursive(0,"");

    cout << ans.back() <<'\n';
    cout << ans[0] <<'\n';



    return 0;
}