#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,m;

void solve(){
    cin >> n >> m;
    vector<int> ans(n + 1);
    vector<int> res;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        if(c % 2)res.push_back(i);
    }
    int diff = res.size() - m + 1;
    if(diff % 2 && diff > 0){
        cout << "YES" << endl;
        for(int i = 0;i < m - 1;i++){
            cout << res[i] << ' ';
        }
        cout << n;
    }else {
        cout << "NO";
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}