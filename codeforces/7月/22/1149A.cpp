#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,m;

int main(){
    cin >> n;
    vector<int> ans;
    vector<int> res;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        if(x == 1)ans.push_back(x);
        else res.push_back(x);
    }
    if(res.size()){
        cout << res.back() << ' ';
        res.pop_back();
    }
    if(ans.size()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    while(res.size()){
        cout << res.back() << ' ';
        res.pop_back();
    }
    while(ans.size()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    cout << endl;
}