#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

void solve(){
    scanf("%d%d",&n,&m);
    priority_queue<int> que;
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    sort(q,q + n);
    int l = 0;
    for(int i = n - 1;i >= 0;i--){
        if(que.empty()){
            que.push(m - q[i]);
        }else {
            if(que.top() < q[i])que.push(m - q[i]);
            else {
                int t = que.top();
                que.pop();
                t -= q[i];
                que.push(t);
            }
        }
    }
    printf("%d\n",que.size());
}

int main(){

    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}