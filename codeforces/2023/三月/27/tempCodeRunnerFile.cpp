#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

void solve(){
    int n;scanf("%d",&n);
    vector<int> pos;
    vector<int> neg;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int x;scanf("%d",&x);
        if(x < 0)neg.pb(x);
        else if(x > 0)pos.pb(x);
        else {
            if(a.size() < 2)a.pb(x);
        }
    }
    if(pos.size() > 2 || neg.size() > 2){
        printf("No");
        return;
    }
    for(int i : pos)a.pb(i);
    for(int i : neg)a.pb(i);
    cout << endl;
    for(int i = 0;i < a.size();i++){
        for(int j = i + 1;j < a.size();j++){
            for(int k = j + 1;k < a.size();k++){
                int ok = 0;
                for(int u = 0;u < a.size();k++){
                    if(a[i] + a[j] + a[k] == a[u]){
                        ok = 1;
                    }
                    
                }
                if(!ok){
                    printf("No");
                    return;
                }
            }
        }
    }
    printf("Yes");
}


int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}