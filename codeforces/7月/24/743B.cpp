#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 100010;

LL n,m;

LL dfs(LL l,LL r,LL need,LL maxv){
    LL m = l + (r - l) / 2;
    //cout << l << ' ' << r << ' ' << m << endl;
    if(m > need){
        return dfs(l,m - 1,need,maxv - 1);
    }else if(m < need){
        
        return dfs(m + 1,r,need,maxv - 1);
    }else {
        return maxv;
    }

}

int main(){
    cin >> n >> m;
    LL sz = 1;
    for(int i = 1;i < n;i++){
        sz = sz * 2LL + 1LL;
    }
    //cout << sz << endl;
    cout << dfs(1,sz,m,n) << endl;;
}