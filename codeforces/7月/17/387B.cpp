#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int n,m;
int q[3010],p[3010];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> q[i];
    for(int i = 0;i < m;i++)cin >> p[i];
    int ans = 0;
    int j = 0;
    int i = 0;
    for(i = 0;i < n;i++){
        while(j < m && p[j] < q[i])j++;
        if(j >= m)break;
        j++;
    }
    ans = n - i;
    cout << ans << endl;
}