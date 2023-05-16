#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

typedef long long LL;

int n,m;
int q[N];

int get_res(vector<int> c,int u){
    if(c.size() == 0)return 0;
    int l = 0,r = c.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(c[mid] >= u){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    return l + 1;
}

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    LL res = 0;
    vector<int> c;
    for(int i = 1;i <= n;i++){
        if(q[i] < i){
            res = res + get_res(c,q[i]);
            c.push_back(i);
        }
    }
    printf("%lld\n",res);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}