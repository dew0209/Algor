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

const int N = 100010;

int main(){
    int n;scanf("%d",&n);
    string a,b;
    cin >> a >> b;
    int res = 0;
    for(int i = 0;i < n;i++){
        if(i + 1 < n && a[i] != b[i] && a[i + 1] && b[i + 1] && a[i] == b[i + 1]){
            res ++;
            i++;
        }else if(a[i] != b[i]){
            res++;
        }
    }
    printf("%d\n",res);
}