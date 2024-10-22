//树状数组


/*
    树状数组：
        从后往前，x = a[n]，包含n的高度为第x + 1高的数，计算sum(answer) == x + 1。也就是answer位置的前缀和为x + 1，即可找到答案
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int tr[N];
int a[N];
int res[N];

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
    cin >> n;
    for(int i = 2;i <= n;i++){
        cin >> a[i];
    }
    
    for(int i = 1;i <= n;i++)tr[i] = lowbit(i);
    
    for(int i = n;i;i--){
        int x = a[i] + 1;
        int l = 1,r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(sum(mid) >= x)r = mid;
            else l = mid + 1;
        }
        res[i] = r;
        add(r,-1);
    }
    
    for(int i = 1;i <= n;i++){
        cout << res[i] << endl; 
    }

    return 0;
}