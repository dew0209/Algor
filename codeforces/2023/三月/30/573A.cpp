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
 
const int N = 1010,M = 100010;
 
int n;
int q[M];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
        while(q[i] % 2 == 0)q[i] /= 2;
        while(q[i] % 3 == 0)q[i] /= 3;
    }
    for(int i = 1;i < n;i++){
        if(q[i] != q[i + 1]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}