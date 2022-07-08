#include <iostream>

using namespace std;

void solve(){
    //编码 数学 不会
    int c,m,x;cin >> c >> m >> x;
    int l = 0,r = min(c,m);
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(c + m + x >= 3 * mid){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}