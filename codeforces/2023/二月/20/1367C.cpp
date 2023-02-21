#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n,k;
string s;

void solve(){
    scanf("%d%d",&n,&k);
    cin >> s;
    int len = s.size();
    int ok = 1;
    for(int i = 0;i < n;i++){
        if(s[i] == '1'){
            ok = 0;
            break;
        }
    }
    if(ok){
        printf("%d",1 + (n - 1) / (k + 1));
        return;
    }
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '0'){
            int j = i;
            while(s[j + 1] == '0' && j + 1 < n){
                j++;
            }
            if(i == 0 || j == n - 1){
                sum += (j - i + 1) / (k + 1);  
            }else {
                sum += (j - i + 1 - k) / (k + 1);
            }
            i = j + 1;
        }
    }
    printf("%d",sum);
}


int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
}