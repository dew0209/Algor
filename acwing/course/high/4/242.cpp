//树状数组


/*
    等差 + 树状数组
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int tr[N];
int a[N];


int lowbit(int u){
    return u & -u;
}

void add(int u,int c){
    for(int i = u;i <= n;i += lowbit(i)){
        tr[i] += c;
    }
}


int sum(int u){
    int res = 0;
    for(int i = u;i;i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}


int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    
    for(int i = 1;i <= n;i++){
        int c = a[i] - a[i - 1];
        add(i,c);
    }
    
    for(int i = 1;i <= m;i++){
        string op;
        cin >> op;
        if(op == "Q"){
            int x;cin >> x;
            int res = sum(x);
            printf("%d\n",res);
        }else {
            int x,y,c;
            cin >> x >> y >> c;
            add(x,c);
            add(y + 1,-c);
        }
    }
    return 0;
}
