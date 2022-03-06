#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;

int n,Q;
vector<int> h[N];
int p[N],q[N],s[N];
int top;

int dfs(int u){
    s[u] = 1;
    p[top] = u;
    q[u] = top;
    top++;
    for(auto t : h[u]){
        dfs(t);
        s[u] += s[t];
    }
}

int main(){
    cin >> n >> Q;
    for(int i = 2;i <= n;i++){
        int c;cin >> c;
        h[c].push_back(i);
    }
    dfs(1);
    while(Q--){
        int u,k;cin >> u >> k;
        if(s[u] < k)cout << -1 << endl;
        else cout << p[q[u] + k - 1] << endl;
    }

    return 0;
}