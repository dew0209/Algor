#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>

typedef long long LL;

const int N = 200010;

using namespace std;

int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    int i = 0,j = n + 1;
    int idx = 0;
    LL zi = 0;
    LL zj = 0;
    while(i < j){
        if(zi < zj){
            zi += a[++i];
        }else if(zi > zj){
            zj += a[--j];
        }else {
            idx = i;
            zi += a[++i];
            zj += a[--j];
        }
    }
    cout << accumulate(a + 1,a + idx + 1,0LL) << endl;
}