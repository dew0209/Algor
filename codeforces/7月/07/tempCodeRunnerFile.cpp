#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    vector<string> res;
    string s(200,'a');
    res.push_back(s);
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        string s1(res.back());
        for(int j = x;j < 200;j++){
            s1[j] = (char)('a' + (i + 1) % 26 );
        }
        res.push_back(s1);
    }
    for(auto &re : res){
        cout << re << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}