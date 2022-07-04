//https://codeforces.com/contest/1406/problem/B
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL ans;

void solve(){
    cin >> n;
    vector<LL> a(n);
    LL mv = -1e9;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        mv = max(mv,a[i]);
    }
    sort(a.begin(),a.end(),[](LL x,LL y){return abs(x) > abs(y);});
    if(mv < 0){
        cout << a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];
    }else {
        ans=a[0]*a[1]*a[2]*a[3]*a[4];
		for(int i = 5;i < n;i++){
            //cout << a[i] << "debug" << endl;
		    for(int j = 0;j< 5;j++){
		        long long tmp=a[i];
		        for(int k=0;k<5;k++){
                    //cout << a[k] << " debug " << endl;
		            if(k!=j)tmp*=a[k];
		        }
		        ans=max(ans,tmp);
		    }
		}
		cout << ans;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}