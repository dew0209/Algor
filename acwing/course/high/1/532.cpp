//dp

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 25010,M = 110;

int n,m;
int f[N];
int a[M];

void solve(){
    memset(f,0,sizeof f);
    memset(a,0,sizeof a);
    cin >> n;
    f[0] = 1;
    int res = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n);
    
    m = a[n - 1];
    
    for(int i = 0;i < n;i++){
        
        if(f[a[i]] == 0)res++;
        for(int j = a[i];j <= m;j++){
            f[j] += f[j - a[i]];
        }
    }
    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}