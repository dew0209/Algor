//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int g[N];
int f[N];
int q[N];

int main(){
    while(cin >> g[++n]);
    //赋值操作需要先找到变量的地址，
    //然后再进行读入，
    //也就是说最后一次跳出循环是因为cin返回值使得我们跳出了while循环，
    //而在这之前，我们已经完成了++n的操作。故需要--操作
    n--;
    int res = 0;
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(g[j] >= g[i]){
                f[i] = max(f[i],f[j] + 1);
            }
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
    int cnt = 0;
    
    for(int i = 1;i <= n;i++){
        int k = 0;
        int x = g[i];
        while(k < cnt && x > q[k])k++;
        q[k] = x;
        cnt = max(cnt,k + 1);
    }
    cout << cnt << endl;
    
    return 0;
}