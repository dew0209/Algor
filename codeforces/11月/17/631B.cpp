#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;


#define fi first
#define se second

using namespace std;

const int N = 5010;

int n,m,k;
int tr[N],itr[N],td[N],itd[N];

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        int a,b,c;cin >> a >> b >> c;
        if(a == 1){
            tr[b] = c;
            itr[b] = i;
        }else {
            td[b] = c;
            itd[b] = i; 
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(itr[i] > itd[j]){
                cout << tr[i] << ' ';
            }else {
                cout << td[j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}