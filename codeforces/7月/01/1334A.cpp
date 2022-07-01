//https://codeforces.com/contest/1334/problem/A
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int oa[N],ob[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> oa[i] >> ob[i];
    }
    bool ok = oa[1] >= ob[1];
    for(int i = 2;i <= n;i++){
        //尝试次数更新，通过可能更新可能不更新
        int diffa = oa[i] - oa[i - 1];
        int diffb = ob[i] - ob[i - 1];
        if(diffb < 0){
            ok = false;
            break;
        }
        //通过更新，尝试必更新
        if(diffb > 0 && diffa <= 0){
            ok = false;
            break;
        }
        //数据大小错误
        if(diffb > diffa){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}