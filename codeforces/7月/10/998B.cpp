#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define fi first
#define se second

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;
int q[110];
int ans[110];

int main(){
    cin >> n >> m;
    int j = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        if(!cnt && i >= 1)ans[j++] = abs(q[i] - q[i - 1]);
        q[i] % 2 ? cnt++ : cnt--;
    }
    sort(ans,ans + j);
    int res = 0;
    for(int i = 0;i < j && m >= 0;i++){
        if(m < ans[i])break;
        m -= ans[i];
        res++;
    }
    cout << res << endl;
}