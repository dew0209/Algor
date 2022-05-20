//这个题不错，没有华丽花哨的玩意，全是套路
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    set<string> se;
    for(int i = 0;i < n;i++){
        string ss;
        for(int k = 0;k < 3 && k + i < n;k++){
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
    for(int len = 1;len <= 3;len++){
        string t(len,'a');
        while(true){
            if(se.count(t) == 0){
                cout << t;
                return;
            }
            int idx = len - 1;
            while(idx >= 0 && t[idx] == 'z'){
                t[idx] = 'a';
                idx--;
            }
            if(idx < 0)break;
            t[idx]++;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}