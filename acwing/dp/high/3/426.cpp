/*
 * 开心的金明
 *  01背包裸题
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n,m;
int f[N];

int main(){
    cin >> m >> n;
    int v,p;
    for(int i = 1;i <= n;i++){
        cin >> v >> p;
        for(int j = m;j >= v;v--){
            f[j] = max(f[j],f[j - v] + v * p);
        }
    }
    cout << f[m] << endl;

    return 0;
}