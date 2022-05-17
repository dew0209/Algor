#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 200010;


void solve(){
    LL a,s;cin >> a >> s;
    vector<int> b;
    while(s){
        int x = a % 10;
        int y = s % 10;
        if(x <= y)b.emplace_back(y - x);
        else {
            s /= 10;
            y += 10 * (s % 10);
            if(x < y && y >= 10 && y < 19)b.emplace_back(y - x);
            else {
                cout << -1 << endl;
                return;
            }
        }
        a /= 10;
        s /= 10;
    }
    if(a)cout << -1 << endl;
    else {
        while(b.back() == 0)b.pop_back();
        for(int i = b.size() - 1;i >= 0;i--)cout << b[i];
        cout << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}