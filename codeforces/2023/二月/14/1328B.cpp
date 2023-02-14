#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

const int N = 100010;

using namespace std;

int n,a,b;
LL s[N];


void init(){
    for(int i = 1;i <= N;i++){
        s[i] = i;
        s[i] += s[i - 1];
    }
}

int getIdx(int u){
    int l = 1,r = N;
    while(l < r){
        int mid = l + r >> 1;
        if(s[mid] >= u){
            r = mid;
        }
        else l = mid + 1;
    }
    return r;
}

void solve(){
    scanf("%d%d",&a,&b);
    vector<char> res(a,'a');
    int aI = getIdx(b);
    res[aI] = 'b';
    res[b - s[aI] + aI - 1] = 'b';
    reverse(res.begin(),res.end());
    for(int i = 0;i < a;i++){
        printf("%c",res[i]);
    }
}

int main(){
    init();
    scanf("%d",&n);
    while(n--)solve(),puts("");
    return 0;
}