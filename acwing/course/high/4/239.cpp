//并查集

/*
    L~R奇偶性相同，可以简化为 [1~R] 和 [1~L-1]  奇偶性相同。因为：奇数 - 奇数 = 偶数，偶数 - 偶数 = 偶数
    L~R奇偶性不同，可以简化为 [1~R] 和 [1~L-1]  奇偶性相同。因为：奇数 - 偶数 = 奇数，偶数 - 奇数 = 奇数
    设相同为0 不同为1.
    那么：
        d[x]表示x点，到连通块跟（p[u] = u）的路径异或值，也就是x和u的奇偶性。
        为什么可以这样表示：
            考虑所有可能性：
                x y 相同 y z相同 那么x z相同 也就是 1 ^ 1，x z相同
                x y 不同 y z相同 那么x z不同 也就是 0 ^ 1，x z不同
                x y 不同 y z不同 那么x z相同 也就是 0 ^ 0，x z相同
    注意点：
        在合并连通块的时候，d[pa] = d[a] ^ d[b] ^ t;解释
        d[pa]相当于要改成1~pa的奇偶性和1~pb的奇偶性差的绝对值，也就是[pa + 1~pb]区间的奇偶性。
        d[a] ^ d[b] ^ d[pa] = t 为1~a 和1~b 的奇偶性差的绝对值
        d[pa] = t ^ d[a] ^ d[b]


*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 20010;


int n,m;
int p[N];
int d[N];
int st = 1;
map<int,int> cnt;

int get(int u){
    if(cnt.count(u)){
        return cnt[u];
    }
    cnt[u] = st++;
    return cnt[u];
}


int find(int u){
    if(p[u] != u){
        int t = find(p[u]);
        d[u] ^= d[p[u]];
        p[u] = t;
    }
    return p[u];
}

int main(){
    cin >> n >> m;
    int res = m;
    for(int i = 1;i < N;i++)p[i] = i;
    for(int i = 0;i < m;i++){
        int a,b;string op;
        int t = 0;
        cin >> a >> b;cin >> op;
        a--;
        a = get(a);
        b = get(b);
        if(op == "odd"){
            t = 1;
        }else {
            t = 0;
        }
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){
            if((d[a] ^ d[b]) != t){
                res = i;
                break;
            }
        }else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }
    cout << res << endl;
    return 0;
}