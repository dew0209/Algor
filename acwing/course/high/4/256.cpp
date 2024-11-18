//可持久化trie树

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 600010,M = N * 25;

int n,m;
int tr[M][2],version[M];
int root[N],idx;
int s[N];

//当前版本 当前操作的位 上一个版本 当前版本
void insert(int i,int k,int p,int q){
    if(k < 0){
        version[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if(p)tr[q][v ^ 1] = tr[p][v ^ 1];
    tr[q][v] = ++idx;
    insert(i,k - 1,tr[p][v],tr[q][v]);
    version[q] = i;
}

int query(int l,int r,int C){
    
    int p = root[r];
    for(int i = 23;i >= 0;i--){
        int v = C >> i & 1;
        if(version[tr[p][v ^ 1]] >= l)p = tr[p][v ^ 1];
        else p = tr[p][v];
    }
    return C ^ s[version[p]];
}

int main(){
    cin >> n >> m;
    version[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);
    for(int i = 1;i <= n;i++){
        cin >> s[i];
        s[i] = s[i] ^ s[i - 1];
        root[i] = ++idx;
        insert(i,23,root[i - 1],root[i]);
    }
    while(m--){
        
        string op;cin >> op;
        int l,r,x;
        if(op == "A"){
            cin >> x;
            ++n;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n,23,root[n - 1],root[n]);
        }
        if(op == "Q"){
            cin >> l >> r >> x;
            int res = query(l - 1,r - 1,s[n] ^ x);
            cout << res << endl;
        }
    }
    return 0;
}